#include "rti/rti_dictionary.h"
#include "dictionarymodel.h"
#include "dictionaryform.h"
#include <QtWidgets>

//
// Constructors
//
DictionaryForm::DictionaryForm(QWidget *parent) : QWidget(parent)
{
    init(NULL);
}

DictionaryForm::DictionaryForm(rti_dictionary *dict, QWidget *parent) : QWidget(parent)
{
    init(dict);
}


//
// Public Slots
//
/**
 * @brief DictionaryForm::setDictionary
 * @param dictionary - the new dictionary
 */
void DictionaryForm::setDictionary(rti_dictionary *dictionary)
{
    dictionary_ = dictionary;
    dictionaryModel->setDictionary(dictionary_);
    dictionaryView->resizeColumnsToContents();
    currentDictionaryRadioButton->setChecked(true);
}

void DictionaryForm::setMasterDictionary(rti_dictionary *master)
{
    masterDictionary_ = master;
    masterDictionaryRadioButton->setChecked(true);
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

void DictionaryForm::changeDictionary()
{
    if (masterDictionaryRadioButton->isChecked())
        dictionaryModel->setDictionary(masterDictionary_);
    else
        dictionaryModel->setDictionary(dictionary_);
}

void DictionaryForm::importFromMaster()
{
    if (masterDictionary_ == NULL)
    {
        QMessageBox::warning(this, tr("No Master Dictionary"), tr("Cannot import from master dictionary because "
                                                                  "no master dictionary is loaded. Please import "
                                                                  "a master dictionary and try again."));
        return;
    }

    if (dictionary_ == NULL)
    {
        QMessageBox::warning(this, tr("No Dictionary Selected"), tr("Cannot import from master dictionary because "
                                                                    "no dictionary is currently loaded."));
        return;
    }

    bool up_to_date;
    if (dictionary_->import_dictionary(masterDictionary_, &up_to_date))
        QMessageBox::information(this, tr("Success"), tr("Master dictionary imported successfully."));
}


//
// Private Methods
//
void DictionaryForm::init(rti_dictionary *dict)
{
    masterDictionary_ = NULL;
    dictionary_ = dict;
    if (!dict)
        dictionaryModel = new DictionaryModel(dictionary_);
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
    masterDictionaryRadioButton = new QRadioButton(tr("Master Dictionary"), this);
    masterDictionaryRadioButton->setChecked(true);
    currentDictionaryRadioButton = new QRadioButton(tr("Current Dictionary"), this);
    connect(masterDictionaryRadioButton, SIGNAL(clicked(bool)), this, SLOT(changeDictionary()));
    connect(currentDictionaryRadioButton, SIGNAL(clicked(bool)), this, SLOT(changeDictionary()));
    incompleteWordsCheckBox = new QCheckBox(tr("Show only incomplete words"));
    connect(incompleteWordsCheckBox, SIGNAL(clicked(bool)), this, SLOT(showOnlyIncompleteWords(bool)));
    searchLabel = new QLabel(tr("Search"));
    searchLineEdit = new QLineEdit;
    connect(searchLineEdit, SIGNAL(textChanged(QString)), this, SLOT(search(QString)));
    importFromMasterButton = new QPushButton(tr("Import From Master"));
    connect(importFromMasterButton, SIGNAL(clicked(bool)), this, SLOT(importFromMaster()));
}

void DictionaryForm::layoutInterface()
{
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(dictionaryLabel);
    topLayout->addWidget(masterDictionaryRadioButton);
    topLayout->addWidget(currentDictionaryRadioButton);
    topLayout->addStretch();
    topLayout->addWidget(incompleteWordsCheckBox);
    topLayout->addStretch();
    topLayout->addWidget(searchLabel);
    topLayout->addWidget(searchLineEdit);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(importFromMasterButton);
    bottomLayout->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(dictionaryView);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);
}
