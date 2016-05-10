//:
// \file
// \author Sean Campbell
// \date   May 2016

#ifndef WORDFREQUENCYMODEL_H
#define WORDFREQUENCYMODEL_H

#include <QAbstractTableModel>
class rti_word_frequency_list;

class WordFrequencyModel : public QAbstractTableModel
{
public:
    WordFrequencyModel();
    WordFrequencyModel(std::vector<std::string> glist, std::vector<std::string> ilist);

    void setGeneratedList(std::vector<std::string> list);
    void setInputtedList(std::vector<std::string> list);
    std::vector<std::string> generatedList() const { return generatedList_; }
    std::vector<std::string> inputtedList() const { return inputtedList_; }

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    //bool setData(const QModelIndex &index, const QVariant &value, int role);
    //Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    std::vector<std::string> generatedList_;
    std::vector<std::string> inputtedList_;
    std::vector<std::string> intersectionList;
    std::vector<std::string> generatedDiffList;
    std::vector<std::string> inputtedDiffList;
};

#endif // WORDFREQUENCYMODEL_H
