#include "wordfrequencymodel.h"

WordFrequencyModel::WordFrequencyModel()
{

}

WordFrequencyModel::WordFrequencyModel(std::vector<std::string> glist, std::vector<std::string> ilist)
{
    generatedList_ = glist;
    inputtedList_ = ilist;
}

//
// Public Methods
//
void WordFrequencyModel::setGeneratedList(std::vector<std::string> list)
{
    emit layoutAboutToBeChanged();
    generatedList_ = list;
    emit layoutChanged();
}

void WordFrequencyModel::setInputtedList(std::vector<std::string> list)
{
    emit layoutAboutToBeChanged();
    inputtedList_ = list;
    emit layoutChanged();
}


int WordFrequencyModel::rowCount(const QModelIndex &/*parent*/) const
{
    return std::max(generatedList_.size(), inputtedList_.size());
}

int WordFrequencyModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 5;
}

QVariant WordFrequencyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (index.column())
        {
            case 0:
                return index.row() < inputtedList_.size() ? QString::fromStdString(inputtedList_.at(index.row())) : "";
            case 1:
                return index.row() < generatedList_.size() ? QString::fromStdString(generatedList_.at(index.row())) : "";
            case 2:
                return "";
            case 3:
                return "";
            case 4:
                return "";
            default:
                return QVariant();
        }
    }
    return QVariant();
}

QVariant WordFrequencyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
            case 0:
                return tr("Input List");
            case 1:
                return tr("Generated List");
            case 2:
                return tr("Intersection");
            case 3:
                return tr("Only Input");
            case 4:
                return tr("Only Generated");
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
