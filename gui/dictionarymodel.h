#ifndef DICTIONARYMODEL_H
#define DICTIONARYMODEL_H

#include <QAbstractTableModel>
class rti_dictionary;

class DictionaryModel : public QAbstractTableModel
{
public:
    DictionaryModel(rti_dictionary *dict);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    void flags(QModelIndex &index) const;

private:
    rti_dictionary *_dictionary;
};

#endif // DICTIONARYMODEL_H
