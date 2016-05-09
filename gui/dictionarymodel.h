#ifndef DICTIONARYMODEL_H
#define DICTIONARYMODEL_H

#include <QAbstractTableModel>
#include <QColor>
class rti_dictionary;

class DictionaryModel : public QAbstractTableModel
{
public:
    enum { ARPABET_COL = 1, MORPHEME_COL = 2, FUNC_WORD_COL = 4 };

    DictionaryModel(rti_dictionary *dictionary = NULL);

    void setDictionary(rti_dictionary *dictionary);
    void setIncompleteEntryBackgroundColor(QColor color) { incompleteEntryBgColor_ = color; }
    rti_dictionary *dictionary() const { return dictionary_; }
    QColor incompleteEntryBackgroundColor() const { return incompleteEntryBgColor_; }

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    rti_dictionary *dictionary_;
    QColor incompleteEntryBgColor_;
};

#endif // DICTIONARYMODEL_H
