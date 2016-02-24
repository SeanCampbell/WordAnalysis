#include "rti/rti_dictionary.h"
#include "rti/rti_word.h"
#include "rti/rti_util.h"
#include "dictionarymodel.h"

DictionaryModel::DictionaryModel(rti_dictionary *dict)
{
    _dictionary = dict;
}

int DictionaryModel::rowCount(const QModelIndex &parent) const
{
    return _dictionary->size();
}

int DictionaryModel::columnCount(const QModelIndex &parent) const
{
    return 11;
}

QVariant DictionaryModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    rti_word_sptr word = (*_dictionary)[index.row()];
    switch (index.column())
    {
        case 0:
            return tr(QString::fromStdString(word->spelling()));
        case 1:
            return tr(QString::fromStdString(word->arpabet()));
        case 2:
            return tr(QString::fromStdString(join(word->phonemes(), ", ")));
        case 3:
            return tr(QString::fromStdString(join(word->stresses_(), ", ")););
        case 4:
            return tr(QString::fromStdString(join(word->morphemes(), ", ")););
        case 5:
            return word->syllables();
        case 6:
            return word->is_function();
        case 7:
            return word->frequency();
        case 8:
            return word->psa();
        case 9:
            return word->bipha();
        case 10:
            return tr("Neighbors");
        default:
            return QVariant();
    }}

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
                return tr("Stresses");
            case 4:
                return tr("Morphemes");
            case 5:
                return tr("Syllables");
            case 6:
                return tr("Is Function Word");
            case 7:
                return tr("Frequency");
            case 8:
                return tr("Positional Segment Average");
            case 9:
                return tr("Biphone Average");
            case 10:
                return tr("Neighbors");
            default:
                return QVariant();
        }
    }
}

bool DictionaryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

void DictionaryModel::flags(QModelIndex &index) const
{

}
