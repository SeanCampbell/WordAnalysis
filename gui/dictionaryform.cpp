#include "rti/rti_dictionary.h"
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
    QMap<QString, rti_dictionary *> qdictMap;
    for (std::map<std::string, rti_dictionary *>::iterator it = dictMap.begin(); it != dictMap.end(); it++)
        qdictMap.insert(QString::fromStdString(it->first), it->second);
    init(qdictMap);
}


//
// Private Slots
//
void DictionaryForm::search(const QString &searchTerm)
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

void DictionaryForm::changeDictionary(const QString &dictName)
{
    if (dictionaryMap.contains(dictName))
        dictionaryModel->setDictionary(dictionaryMap.value(dictName));
}

void DictionaryForm::importFromMaster()
{

}

void DictionaryForm::deleteDictionary()
{
    QString curDictName = dictionaryComboBox->currentText();
    rti_dictionary *curDict = dictionaryMap.value(curDictName);
    if (curDict != NULL)
    {
        dictionaryMap.remove(curDictName);
        dictionaryComboBox->removeItem(dictionaryComboBox->currentIndex());
        delete curDict;
    }
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
    connect(dictionaryComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeDictionary(QString)));
    dictionaryComboBox->addItems(dictionaryMap.keys());
    incompleteWordsCheckBox = new QCheckBox(tr("Show only incomplete words"));
    connect(incompleteWordsCheckBox, SIGNAL(clicked(bool)), this, SLOT(showOnlyIncompleteWords(bool)));
    searchLabel = new QLabel(tr("Search"));
    searchLineEdit = new QLineEdit;
    connect(searchLineEdit, SIGNAL(textChanged(QString)), this, SLOT(search(QString)));
    importFromMasterButton = new QPushButton(tr("Import From Master"));
    connect(importFromMasterButton, SIGNAL(clicked(bool)), this, SLOT(importFromMaster()));
    deleteDictionaryButton = new QPushButton(tr("Delete Dictionary"));
    connect(deleteDictionaryButton, SIGNAL(clicked(bool)), this, SLOT(deleteDictionary()));
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
