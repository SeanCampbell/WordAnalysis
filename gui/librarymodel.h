#ifndef LIBRARYMODEL_H
#define LIBRARYMODEL_H

#include <QAbstractTableModel>
class rti_literature;

class LibraryModel : public QAbstractTableModel
{
public:
    LibraryModel(rti_literature *library = NULL);

    void setLibrary(rti_literature *library);
    rti_literature *library() const { return library_; }

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    rti_literature *library_;
};

#endif // LIBRARYMODEL_H
