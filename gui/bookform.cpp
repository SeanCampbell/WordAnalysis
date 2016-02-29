#include "wautils.h"
#include "bookform.h"
#include <QtWidgets>

//
// Constructors
//
BookForm::BookForm(QWidget *parent)
    : QWidget(parent)
{
    createInterface();
    layoutInterface();
    setWindowTitle(tr("Add a New Book"));
}


//
// Private Slots
//
void BookForm::addBook()
{
    rti_book *book = new rti_book(isbnLineEdit->text().toStdString(),
                                 titleLineEdit->text().toStdString(),
                                 authorLineEdit->text().toStdString(),
                                 wa_utils::gradeLevelMap().key(gradeLevelComboBox->currentText()),
                                 filePathLineEdit->text().toStdString());
    emit bookAdded(book);
    close();
}

void BookForm::browseForBook()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Choose file with text of book..."),
                                                    "", "Text files (*.txt)");
    if (!filePath.isEmpty())
        filePathLineEdit->setText(filePath);
}

void BookForm::validateBookFilePath()
{
    if (!QFile(filePathLineEdit->text()).exists()) {
        filePathLineEdit->setStyleSheet("* { background-color: yellow; }");
    } else {
        filePathLineEdit->setStyleSheet("* { background-color: white; }");
    }
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
    gradeLevelComboBox = new QComboBox;
    gradeLevelComboBox->addItems(wa_utils::gradeLevelMap().values());
    filePathLabel = new QLabel(tr("File Path"));
    filePathLineEdit = new QLineEdit;
    connect(filePathLineEdit, SIGNAL(textChanged(QString)), this, SLOT(validateBookFilePath()));
    browseButton = new QPushButton(tr("Browse"));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browseForBook()));
    addBookButton = new QPushButton(tr("Add Book"));
    connect(addBookButton, SIGNAL(clicked()), this, SLOT(addBook()));
}

void BookForm::layoutInterface()
{
    QHBoxLayout *filePathLayout = new QHBoxLayout;
    filePathLayout->addWidget(filePathLineEdit);
    filePathLayout->addWidget(browseButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(isbnLabel, 0, 0);
    mainLayout->addWidget(isbnLineEdit, 0, 1);
    mainLayout->addWidget(titleLabel, 1, 0);
    mainLayout->addWidget(titleLineEdit, 1, 1);
    mainLayout->addWidget(authorLabel, 2, 0);
    mainLayout->addWidget(authorLineEdit, 2, 1);
    mainLayout->addWidget(gradeLevelLabel, 3, 0);
    mainLayout->addWidget(gradeLevelComboBox, 3, 1);
    mainLayout->addWidget(filePathLabel, 4, 0);
    mainLayout->addLayout(filePathLayout, 4, 1);
    mainLayout->addWidget(addBookButton, 6, 0, 1, 2);
    setLayout(mainLayout);
}
