#include "bookform.h"
#include <QtWidgets>

#include <iostream>

BookForm::BookForm(QWidget *parent)
    : QWidget(parent)
{
    _book = NULL;
    _isEditable = true;

    createInterface();
    layoutInterface();

    updateBookButton->setText(tr("Add Book"));
    setWindowTitle(tr("Book Form"));
}


BookForm::BookForm(rti_book *book, bool isEditable, QWidget *parent)
    : QWidget(parent)
{
    _book = book;
    _isEditable = isEditable;

    createInterface();
    layoutInterface();

    setWindowTitle(tr("Book Form"));
}


//
// Private Slots
//
void BookForm::updateBook()
{
    if (_book != NULL)
        delete _book;
    _book = new rti_book(isbnLineEdit->text().toStdString(), titleLineEdit->text().toStdString(),
                         authorLineEdit->text().toStdString(), contentsTextArea->toPlainText().toStdString());
}

//
// Private Methods
//
void BookForm::createInterface()
{
    isbnLabel = new QLabel(tr("ISBN"));
    isbnLineEdit = new QLineEdit;
    titleLabel = new QLabel(tr("Title"));
    titleLineEdit = new QLineEdit;
    authorLabel = new QLabel(tr("Author"));
    authorLineEdit = new QLineEdit;
    gradeLevelLabel = new QLabel(tr("Grade Level"));
    gradeLevelLineEdit = new QLineEdit;
    contentsLabel = new QLabel(tr("Contents"));
    contentsTextArea = new QTextEdit;
    updateBookButton = new QPushButton(tr("Update Book"));
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
    mainLayout->addWidget(gradeLevelLineEdit, 3, 1);
    mainLayout->addWidget(contentsLabel,4, 0);
    mainLayout->addWidget(contentsTextArea, 5, 0, 1, 2);
    mainLayout->addWidget(updateBookButton, 6, 0, 1, 2);
    setLayout(mainLayout);
}
