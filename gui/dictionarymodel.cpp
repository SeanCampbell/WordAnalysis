#include "rti/rti_dictionary.h"
#include "rti/rti_word.h"
#include "rti/rti_util.h"
#include "dictionarymodel.h"

DictionaryModel::DictionaryModel(rti_dictionary *dict)
{
    incompleteEntryBgColor_ = QColor(255, 200, 200);
    dictionary_ = dict;
}

int DictionaryModel::rowCount(const QModelIndex &parent) const
{
    return dictionary_->size();
}

int DictionaryModel::columnCount(const QModelIndex &parent) const
{
    return 10;
}

QVariant DictionaryModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

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
                return QString::fromStdString(join(word->phonemes(), ", "));
            case 3:
                return QString::fromStdString(word->morphemes());
            case 4:
                return word->syllables();
            case 5:
                return word->is_function();
            case 6:
                return word->frequency();
            case 7:
                return word->psa();
            case 8:
                return word->bipha();
            case 9:
                return tr(QString::fromStdString(join(word->neighbors(), ", ")).toLatin1());
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
                return tr("Phonemes");
            case 3:
                return tr("Morphemes");
            case 4:
                return tr("Syllables");
            case 5:
                return tr("Is Function Word");
            case 6:
                return tr("Frequency");
            case 7:
                return tr("Positional Segment Average");
            case 8:
                return tr("Biphone Average");
            case 9:
                return tr("Neighbors");
            default:
                return QVariant();
        }
    }

    return QVariant();
}

bool DictionaryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    if (index.column() == MORPHEME_COL)
    {
        (*dictionary_)[index.row()]->set_morphemes(value.toString().toStdString());
        return true;
    }

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


