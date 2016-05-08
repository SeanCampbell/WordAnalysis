#include "rti/rti_dictionary.h"
#include "rti/rti_word.h"
#include "rti/rti_utils.h"
#include "dictionarymodel.h"
#include <QFont>

DictionaryModel::DictionaryModel(rti_dictionary *dictionary)
{
    incompleteEntryBgColor_ = QColor(255, 200, 200);
    dictionary_ = dictionary;
}

//
// Public Methods
//
void DictionaryModel::setDictionary(rti_dictionary *dictionary)
{
    emit layoutAboutToBeChanged();
    dictionary_ = dictionary;
    emit layoutChanged();
}

int DictionaryModel::rowCount(const QModelIndex &/*parent*/) const
{
    return dictionary_ != NULL ? dictionary_->size() : 0;
}

int DictionaryModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 10;
}

QVariant DictionaryModel::data(const QModelIndex &index, int role) const
{
    if (dictionary_ == NULL || !index.isValid())
        return QVariant();

    // Color and italicize editable columns.
    if (role == Qt::TextColorRole && index.column() == MORPHEME_COL)
        return QColor(Qt::blue);
    if (role == Qt::FontRole && index.column() == MORPHEME_COL)
    {
        QFont font;
        font.setItalic(true);
        return font;
    }

    rti_word_sptr word = (*dictionary_)[index.row()];
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (index.column())
        {
            case 0:
                return QString::fromStdString(word->spelling());
            case 1:
                return QString::fromStdString(word->arpabet());
            case 2:
                return QString::fromStdString(word->morphemes());
            case 3:
                return word->syllables();
            case 4:
                return word->is_function();
            case 4:
                return word->frequency();
            case 5:
                return word->psa();
            case 6:
                return word->bipha();
            case 7:
                return tr(QString::fromStdString(rti_utils::join(word->neighbors(), ", ")).toLatin1());
            default:
                return QVariant();
        }
    }
    else if (role == Qt::BackgroundColorRole)
    {
        return word->morphemes() == "XXX" ? incompleteEntryBgColor_ : QColor(Qt::white);
    }
    return QVariant();
}

QVariant DictionaryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
            case 0:
                return tr("Spelling");
            case 1:
                return tr("Arpabet");
            case 2:
                return tr("Morphemes");
            case 3:
                return tr("Syllables");
            case 4:
                return tr("Is Function Word");
            case 5:
                return tr("Frequency");
            case 6:
                return tr("Positional Segment Average");
            case 7:
                return tr("Biphone Average");
            case 8:
                return tr("Neighbors");
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

bool DictionaryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (dictionary_ == NULL
            || !index.isValid()
            || index.row() > dictionary_->size()
            || role != Qt::EditRole)
        return false;

    /*if (index.column() == ARPABET_COL)
    {
        (*dictionary_)[index.row()]->set_morphemes(value.toString().toStdString());
        return true;
    }
    else */if (index.column() == MORPHEME_COL)
    {
        (*dictionary_)[index.row()]->set_morphemes(value.toString().toStdString());
        return true;
    }/*
    else if (index.column() == FUNC_WORD_COL)
    {
        (*dictionary_)[index.row()]->set_morphemes(value.toString().toStdString());
        return true;
    }*/

    return false;
}

Qt::ItemFlags DictionaryModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;
    if (index.column() == MORPHEME_COL)
        return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled | QAbstractItemModel::flags(index);
    return QAbstractItemModel::flags(index);
}

