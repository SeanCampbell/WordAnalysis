#ifndef LIBRARYMODEL_H
#define LIBRARYMODEL_H

#include "rti/rti_book.h"
#include <QAbstractTableModel>
class rti_literature;

class LibraryModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    LibraryModel(rti_literature *library = NULL);

    void setLibrary(rti_literature *library);
    rti_literature *library() const { return library_; }
    QList<rti_book *> selectedBooks() const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

public slots:
    bool addBook(rti_book *book);
    void removeBooks(QSet<rti_book *> books);
    void removeCheckedBooks();

    void selectAll(bool select);
    void selectAllBooksInGradeLevel(rti_book::AGE gradeLevel);

private:
    rti_literature *library_;
    QList<Qt::CheckState> bookCheckStates;
};

#endif // LIBRARYMODEL_H
