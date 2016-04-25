#include "wordfrequencymodel.h"
#include "rti/rti_utils.h"

WordFrequencyModel::WordFrequencyModel()
    : inputtedList_(), generatedList_()
{

}

WordFrequencyModel::WordFrequencyModel(std::vector<std::string> glist, std::vector<std::string> ilist)
{
    generatedList_ = glist;
    inputtedList_ = ilist;
    intersectionList = rti_utils::get_intersection(glist, ilist);
    generatedDiffList = rti_utils::get_difference(glist, ilist);
    inputtedDiffList = rti_utils::get_difference(ilist, glist);
}

//
// Public Methods
//
void WordFrequencyModel::setGeneratedList(std::vector<std::string> list)
{
    emit layoutAboutToBeChanged();
    generatedList_ = list;
    intersectionList = rti_utils::get_intersection(generatedList_, inputtedList_);
    generatedDiffList = rti_utils::get_difference(generatedList_, inputtedList_);
    inputtedDiffList = rti_utils::get_difference(inputtedList_, generatedList_);
    emit layoutChanged();
}

void WordFrequencyModel::setInputtedList(std::vector<std::string> list)
{
    emit layoutAboutToBeChanged();
    inputtedList_ = list;
    intersectionList = rti_utils::get_intersection(generatedList_, inputtedList_);
    generatedDiffList = rti_utils::get_difference(generatedList_, inputtedList_);
    inputtedDiffList = rti_utils::get_difference(inputtedList_, generatedList_);
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

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case 0:
                return index.row() < inputtedList_.size() ? QString::fromStdString(inputtedList_.at(index.row())) : "";
            case 1:
                return index.row() < generatedList_.size() ? QString::fromStdString(generatedList_.at(index.row())) : "";
            case 2:
                return index.row() < intersectionList.size() ? QString::fromStdString(intersectionList.at(index.row())) : "";;
            case 3:
                return index.row() < inputtedDiffList.size() ? QString::fromStdString(inputtedDiffList.at(index.row())) : "";;
            case 4:
                return index.row() < generatedDiffList.size() ? QString::fromStdString(generatedDiffList.at(index.row())) : "";;
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
                return tr("Only Inputted");
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
