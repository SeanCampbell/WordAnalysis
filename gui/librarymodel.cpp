#include "rti/rti_literature.h"
#include "wautils.h"
#include "librarymodel.h"
#include <QColor>
#include <QFont>

#include <QDebug>

LibraryModel::LibraryModel(rti_literature *library)
{
    library_ = library;
    // If there are books in the library, fill the
    // start them all deselected.
    if (library_ != NULL)
        for (int i = 0; i < library_->size(); i++)
            bookCheckStates.append(Qt::Unchecked);
}


//
// Public Methods
//
void LibraryModel::setLibrary(rti_literature *library)
{
    emit layoutAboutToBeChanged();
    library_ = library;
    // If there are books in the library, fill the
    // start them all deselected.
    bookCheckStates.clear();
    if (library_ != NULL)
        for (int i = 0; i < library_->size(); i++)
            bookCheckStates.append(Qt::Unchecked);
    emit layoutChanged();
}

QList<rti_book *> LibraryModel::selectedBooks() const
{
    QList<rti_book *> selectedBooks;
    for (int i = 0; i < bookCheckStates.length(); i++)
        if (bookCheckStates.at(i) == Qt::Checked)
            selectedBooks.append((*library_)[i].ptr());
    return selectedBooks;
}

int LibraryModel::rowCount(const QModelIndex &/*parent*/) const
{
    return library_ != NULL ? library_->size() : 0;
}

int LibraryModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 5;
}

QVariant LibraryModel::data(const QModelIndex &index, int role) const
{
    if (library_ == NULL || !index.isValid())
        return QVariant();

    // Color and italicize editable columns.
    if (role == Qt::TextColorRole)
        return QColor(Qt::blue);
    if (role == Qt::FontRole)
    {
        QFont font;
        font.setItalic(true);
        return font;
    }

    if (role == Qt::CheckStateRole)
        if (index.column() == 0)
            return bookCheckStates.at(index.row());

    rti_book_sptr book = (*library_)[index.row()];
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (index.column())
        {
            case 1:
                return QString::fromStdString(book->isbn());
            case 2:
                return QString::fromStdString(book->title());
            case 3:
                return QString::fromStdString(book->author());
            case 4:
                return wa_utils::gradeLevelMap().value(book->age_range());
            default:
                return QVariant();
        }
    }
    return QVariant();
}

QVariant LibraryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
            case 1:
                return tr("ISBN");
            case 2:
                return tr("Title");
            case 3:
                return tr("Author");
            case 4:
                return tr("Grade Level");
            default:
                return QVariant();
        }
    }
    else
    {
        return section + 1;
    }

    return QVariant();
}

bool LibraryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (library_ == NULL
            || !index.isValid()
            || index.row() > library_->size())
        return false;

    if (role == Qt::CheckStateRole && index.column() == 0)
    {
        bookCheckStates[index.row()] = (Qt::CheckState)value.toInt();
        return true;
    }

    if (role == Qt::EditRole)
    {
        switch (index.column())
        {
            case 1:
                (*library_)[index.row()]->set_isbn(value.toString().toStdString());
                emit dataChanged(index, index);
                return true;
            case 2:
                (*library_)[index.row()]->set_title(value.toString().toStdString());
                emit dataChanged(index, index);
                return true;
            case 3:
                (*library_)[index.row()]->set_author(value.toString().toStdString());
                emit dataChanged(index, index);
                return true;
            case 4:
                (*library_)[index.row()]->set_age_range(wa_utils::gradeLevelMap().key(value.toString()));
                emit dataChanged(index, index);
                return true;
        }
    }

    return false;
}

Qt::ItemFlags LibraryModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;
    if (index.column() == 0)
        return Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable | QAbstractItemModel::flags(index);
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}


//
// Public SLots
//
bool LibraryModel::addBook(rti_book *book)
{
    int index;
    if (!library_->find(book->title(), index))
    {
        emit layoutAboutToBeChanged();
        library_->insert(book, index);
        bookCheckStates.insert(index, Qt::Checked);
        emit layoutChanged();
        return true;
    }
    return false;
}

void LibraryModel::removeBooks(QSet<rti_book *> books)
{
    int index;
    // Rather than emitting the signal multiple times,
    // we only emit the layoutChanged() signal once,
    // when we're done.
    bool layoutWasChanged = false;
    foreach (rti_book *book, books)
    {
        if (library_->find(book->isbn(), index))
        {
            emit layoutAboutToBeChanged();
            library_->remove(index);
            bookCheckStates.removeAt(index);
            layoutWasChanged = true;
        }
    }
    if (layoutWasChanged)
        emit layoutChanged();
}

void LibraryModel::removeCheckedBooks()
{
    QSet<rti_book *> checkedBooks;
    for (int i = 0; i < bookCheckStates.size(); i++)
        if (bookCheckStates.at(i) == Qt::Checked)
            checkedBooks.insert((*library_)[i].ptr());
    if (!checkedBooks.isEmpty())
        removeBooks(checkedBooks);
}

void LibraryModel::selectAll(bool select)
{
    emit layoutAboutToBeChanged();
    Qt::CheckState checkState = select ? Qt::Checked : Qt::Unchecked;
    for (int i = 0; i < bookCheckStates.length(); i++)
        bookCheckStates[i] = checkState;
    emit layoutChanged();
}

void LibraryModel::selectAllBooksInGradeLevel(rti_book::AGE gradeLevel)
{
    emit layoutAboutToBeChanged();
    for (int i = 0; i < bookCheckStates.length(); i++)
        if ((*library_)[i]->age_range() == gradeLevel)
            bookCheckStates[i] = Qt::Checked;
    emit layoutChanged();
}
