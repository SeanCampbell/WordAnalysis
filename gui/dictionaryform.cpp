#include "dictionarymodel.h"
#include "dictionaryform.h"
#include <QtWidgets>

//
// Constructors
//
DictionaryForm::DictionaryForm(QMap<QString, rti_dictionary *> dictMap, QWidget *parent) : QWidget(parent)
{
    init(dictMap);
}

DictionaryForm::DictionaryForm(std::map<std::string, rti_dictionary *> dictMap, QWidget *parent) : QWidget(parent)
{
}


//
// Private Slots
//
void DictionaryForm::search(QString searchTerm)
{
    proxyModel->setFilterRegExp(searchTerm);
    proxyModel->setFilterKeyColumn(-1);
}

void DictionaryForm::showOnlyIncompleteWords(bool incomplete)
{
    if (incomplete)
    {
        proxyModel->setFilterRegExp("XXX");
        proxyModel->setFilterKeyColumn(DictionaryModel::MORPHEME_COL);
    }
    else
    {
        proxyModel->setFilterRegExp(QRegExp());
    }
}

void DictionaryForm::importFromMaster()
{

}

void DictionaryForm::deleteDictionary()
{

}


//
// Private Methods
//
void DictionaryForm::init(QMap<QString, rti_dictionary *> dictMap)
{
    dictionaryMap = dictMap;
    // Set the dictionary to be whatever the iterator starts at.
    dictionaryModel = new DictionaryModel(dictionaryMap.begin().value());
    proxyModel = new QSortFilterProxyModel;
    proxyModel->setSourceModel(dictionaryModel);

    createInterface();
    layoutInterface();
}

void DictionaryForm::createInterface()
{
    dictionaryView = new QTableView;
    dictionaryView->setModel(proxyModel);
    dictionaryView->setSortingEnabled(true);

    dictionaryLabel = new QLabel(tr("Dictionary"));
    dictionaryComboBox = new QComboBox;
    dictionaryComboBox->addItems(dictionaryMap.keys());
    incompleteWordsCheckBox = new QCheckBox(tr("Show only incomplete words"));
    connect(incompleteWordsCheckBox, SIGNAL(clicked(bool)), this, SLOT(showOnlyIncompleteWords(bool)));
    searchLabel = new QLabel(tr("Search"));
    searchLineEdit = new QLineEdit;
    connect(searchLineEdit, SIGNAL(textChanged(QString)), this, SLOT(search(QString)));
    importFromMasterButton = new QPushButton(tr("Import From Master"));
    deleteDictionaryButton = new QPushButton(tr("Delete Dictionary"));
}

void DictionaryForm::layoutInterface()
{
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(dictionaryLabel);
    topLayout->addWidget(dictionaryComboBox);
    topLayout->addStretch();
    topLayout->addWidget(incompleteWordsCheckBox);
    topLayout->addStretch();
    topLayout->addWidget(searchLabel);
    topLayout->addWidget(searchLineEdit);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(importFromMasterButton);
    bottomLayout->addStretch();
    bottomLayout->addWidget(deleteDictionaryButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(dictionaryView);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);
}
