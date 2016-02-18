#ifndef DICTIONARYFORM_H
#define DICTIONARYFORM_H

#include <QWidget>
class QTableView;
class rti_dictionary;

class DictionaryForm : public QWidget
{
    Q_OBJECT
public:
    explicit DictionaryForm(rti_dictionary *dict, QWidget *parent = 0);

private:
    void createInterface(rti_dictionary *dict);
    void layoutInterface();

    QTableView *dictionaryView;
};

#endif // DICTIONARYFORM_H
