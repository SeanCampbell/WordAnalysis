#include "dictionarymodel.h"
#include "dictionaryform.h"
#include <QTableView>
#include <QHeaderView>
#include <QVBoxLayout>

//
// Constructors
//
DictionaryForm::DictionaryForm(rti_dictionary *dict, QWidget *parent) : QWidget(parent)
{
    createInterface(dict);
    layoutInterface();
}

//
// Private Methods
//
void DictionaryForm::createInterface(rti_dictionary *dict)
{
    dictionaryView = new QTableView;
    //dictionaryView->horizontalHeader()->show();
    dictionaryView->setModel(new DictionaryModel(dict));
}

void DictionaryForm::layoutInterface()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(dictionaryView);
    setLayout(mainLayout);
}
