#include "libraryform.h"
#include <QtWidgets>

LibraryForm::LibraryForm(QWidget *parent) : QWidget(parent)
{
    gradeLevelMap.insert(rti_book::NS, "Nursery");
    gradeLevelMap.insert(rti_book::PK, "Pre-K");
    gradeLevelMap.insert(rti_book::K,  "Kindergartern");
    gradeLevelMap.insert(rti_book::G1, "Grade 1");
    gradeLevelMap.insert(rti_book::G2, "Grade 2");
    gradeLevelMap.insert(rti_book::G3, "Grade 3");
    gradeLevelMap.insert(rti_book::G4, "Grade 4");

    //libraryModel = new LibraryModel;
    proxyModel = new QSortFilterProxyModel;
    proxyModel->setSourceModel(NULL);//libraryModel);

    createInterface();
    layoutInterface();
}


//
// Private Slots
//
void LibraryForm::selectBooksWithGradeLevel(const QString &gradeLevel)
{

}

void LibraryForm::search(const QString &searchTerm)
{
    proxyModel->setFilterRegExp(searchTerm);
    proxyModel->setFilterKeyColumn(-1);
}

void LibraryForm::addBook()
{

}

void LibraryForm::editBook()
{

}

void LibraryForm::viewBook()
{

}

void LibraryForm::createDictionary()
{

}

void LibraryForm::createFrequencyList()
{

}


//
// Private Methods
//
void LibraryForm::createInterface()
{
    libraryView = new QTableView;
    libraryView->setModel(proxyModel);
    libraryView->setSortingEnabled(true);

    selectGradeLevelLabel = new QLabel(tr("Select all books in grade level"));
    selectGradeLevelComboBox = new QComboBox;
    selectGradeLevelComboBox->addItem("-");
    selectGradeLevelComboBox->addItems(gradeLevelMap.values());
    connect(selectGradeLevelComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectBooksWithGradeLevel(QString)));
    searchLabel = new QLabel(tr("Search"));
    searchLineEdit = new QLineEdit;
    connect(searchLineEdit, SIGNAL(textChanged(QString)), this, SLOT(search(QString)));

    addBookButton = new QPushButton(tr("Add Book"));
    editBookButton = new QPushButton(tr("Edit Book"));
    viewBookButton = new QPushButton(tr("View Book"));
    createDictionaryButton = new QPushButton(tr("Create Dictionary"));
    createFrequencyListButton = new QPushButton(tr("Create Frequency List"));
}

void LibraryForm::layoutInterface()
{
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(selectGradeLevelLabel);
    topLayout->addWidget(selectGradeLevelComboBox);
    topLayout->addStretch();
    topLayout->addWidget(searchLabel);
    topLayout->addWidget(searchLineEdit);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(addBookButton);
    bottomLayout->addWidget(editBookButton);
    bottomLayout->addWidget(viewBookButton);
    bottomLayout->addStretch();
    bottomLayout->addWidget(createDictionaryButton);
    bottomLayout->addWidget(createFrequencyListButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(libraryView);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);
}
