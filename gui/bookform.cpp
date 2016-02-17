#include "bookform.h"
#include <QtWidgets>

#include <iostream>

//
// Constructors
//
BookForm::BookForm(QWidget *parent)
    : QWidget(parent)
{
    init();
    _book = new rti_book();
    updateBookButton->setText(tr("Add Book"));
}


BookForm::BookForm(rti_book *book, bool editable, QWidget *parent)
    : QWidget(parent)
{
    init();
    setEditable(editable);
    setBook(book);
}

//
// Public Methods
//
void BookForm::setBook(rti_book *book)
{
    _book = book;
    isbnLineEdit->setText(QString::fromStdString(book->isbn()));
    titleLineEdit->setText(QString::fromStdString(_book->title()));
    authorLineEdit->setText(QString::fromStdString(_book->author()));
    gradeLevelComboBox->setCurrentText(gradeLevelMap.value(_book->age_range()));
    //contentsTextEdit;
}

void BookForm::setEditable(bool editable)
{
    isbnLineEdit->setReadOnly(!editable);
    titleLineEdit->setReadOnly(!editable);
    authorLineEdit->setReadOnly(!editable);
    contentsTextEdit->setReadOnly(!editable);
}


//
// Private Slots
//
void BookForm::updateBook()
{
    _book->set_isbn(isbnLineEdit->text().toStdString());
    _book->set_title(titleLineEdit->text().toStdString());
    _book->set_author(authorLineEdit->text().toStdString());
    _book->set_age_range(gradeLevelMap.key(gradeLevelComboBox->currentText()));
    close();
}

//
// Private Methods
//
void BookForm::init()
{
    setWindowTitle(tr("Book Form"));

    gradeLevelMap.insert(rti_book::NS, "Nursery");
    gradeLevelMap.insert(rti_book::PK, "Pre-K");
    gradeLevelMap.insert(rti_book::K,  "Kindergartern");
    gradeLevelMap.insert(rti_book::G1, "Grade 1");
    gradeLevelMap.insert(rti_book::G2, "Grade 2");
    gradeLevelMap.insert(rti_book::G3, "Grade 3");
    gradeLevelMap.insert(rti_book::G4, "Grade 4");

    createInterface();
    layoutInterface();
}

void BookForm::createInterface()
{
    isbnLabel = new QLabel(tr("ISBN"));
    isbnLineEdit = new QLineEdit;
    titleLabel = new QLabel(tr("Title"));
    titleLineEdit = new QLineEdit;
    authorLabel = new QLabel(tr("Author"));
    authorLineEdit = new QLineEdit;
    gradeLevelLabel = new QLabel(tr("Grade Level"));
    gradeLevelComboBox = new QComboBox;
    gradeLevelComboBox->addItems(gradeLevelMap.values());
    contentsLabel = new QLabel(tr("Contents"));
    contentsTextEdit = new QTextEdit;
    updateBookButton = new QPushButton(tr("Update Book"));
    connect(updateBookButton, SIGNAL(clicked()), this, SLOT(updateBook()));
}

void BookForm::layoutInterface()
{
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(isbnLabel, 0, 0);
    mainLayout->addWidget(isbnLineEdit, 0, 1);
    mainLayout->addWidget(titleLabel, 1, 0);
    mainLayout->addWidget(titleLineEdit, 1, 1);
    mainLayout->addWidget(authorLabel, 2, 0);
    mainLayout->addWidget(authorLineEdit, 2, 1);
    mainLayout->addWidget(gradeLevelLabel, 3, 0);
    mainLayout->addWidget(gradeLevelComboBox, 3, 1);
    mainLayout->addWidget(contentsLabel,4, 0);
    mainLayout->addWidget(contentsTextEdit, 5, 0, 1, 2);
    mainLayout->addWidget(updateBookButton, 6, 0, 1, 2);
    setLayout(mainLayout);
}
