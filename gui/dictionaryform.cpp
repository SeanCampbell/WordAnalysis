#include "rti/rti_dictionary.h"
#include "dictionarymodel.h"
#include "dictionaryform.h"
#include <QtWidgets>

//
// Constructors
//
DictionaryForm::DictionaryForm(QWidget *parent) : QWidget(parent)
{
    init(QMap<QString, rti_dictionary *>());
}

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
// Public Slots
//

/**
 * @brief DictionaryForm::addDictionary
 * @param name - name of dictionary in the form
 * @param dictionary - the dictionary to add
 * @return true if the dictionary is inserted,
 *      false if a dictionary of the same name
 *      is already in the form, so the dictionary
 *      can't be added
 */
bool DictionaryForm::addDictionary(const QString &name, rti_dictionary *dictionary)
{
    if (!dictionaryMap.contains(name))
    {
        dictionaryMap.insert(name, dictionary);
        //dictionaryComboBox->clear();
        //dictionaryComboBox->addItems(dictionaryMap.keys());
        dictionaryComboBox->addItem(name);
        //connect(dictionaryComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeDictionary(QString)));
        dictionaryComboBox->setCurrentText(name);
        return true;
    }
    return false;
}

void DictionaryForm::setMasterDictionary(rti_dictionary *master)
{
    masterDictionary_ = master;
    changeDictionary("Master Dictionary");
}


//
// Private Slots
//
void DictionaryForm::search(const QString &searchTerm)
{
    QRegExp regExp = QRegExp(searchTerm);
    regExp.setCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterRegExp(regExp);
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
    if (dictName == "Master Dictionary")
        dictionaryModel->setDictionary(masterDictionary_);
    else if (dictionaryMap.contains(dictName))
    {
        dictionaryModel->setDictionary(dictionaryMap.value(dictName));
        dictionaryView->resizeColumnsToContents();
    }
    else
    {
        dictionaryModel = NULL;
        proxyModel->setSourceModel(NULL);
    }
}

void DictionaryForm::importFromMaster()
{

}

void DictionaryForm::deleteDictionary()
{
    QString curDictName = dictionaryComboBox->currentText();
    if (curDictName == "Master Dictionary")
    {
        QMessageBox::warning(this, tr("Cannot Delete Dictionary"), tr("You cannot delete the master dictionary."));
        return;
    }
    rti_dictionary *curDict = dictionaryMap.value(curDictName);
    if (curDict != NULL)
    {
        dictionaryMap.remove(curDictName);
        dictionaryComboBox->removeItem(dictionaryComboBox->currentIndex());
        delete curDict;
    }
    dictionaryView->resizeColumnsToContents();
}


//
// Private Methods
//
void DictionaryForm::init(QMap<QString, rti_dictionary *> dictMap)
{
    masterDictionary_ = NULL;
    dictionaryMap = dictMap;
    // Set the dictionary to be whatever the iterator starts at.
    if (!dictMap.isEmpty())
        dictionaryModel = new DictionaryModel(dictionaryMap.begin().value());
    else
        dictionaryModel = new DictionaryModel;
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
    dictionaryView->resizeColumnsToContents();
    dictionaryView->horizontalHeader()->setStretchLastSection(true);

    dictionaryLabel = new QLabel(tr("Dictionary"));
    dictionaryComboBox = new QComboBox;
    connect(dictionaryComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeDictionary(QString)));
    dictionaryComboBox->addItem("Master Dictionary");
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
