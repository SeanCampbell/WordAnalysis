//:
// \file
// \author Sean Campbell
// \date   February 2016

#ifndef BOOKFORM_H
#define BOOKFORM_H

#include "rti/rti_book.h"
#include <QWidget>
#include <QLineEdit>
class QLabel;
class QComboBox;
class QPushButton;

class BookForm : public QWidget
{
    Q_OBJECT

public:
    explicit BookForm(QWidget *parent = 0);

signals:
    void bookAdded(rti_book *book);

private slots:
    void addBook();
    void browseForBook();
    void validateBookFilePath();

private:
    void createInterface();
    void layoutInterface();

    // GUI
    QLabel *isbnLabel;
    QLineEdit *isbnLineEdit;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *authorLabel;
    QLineEdit *authorLineEdit;
    QLabel *gradeLevelLabel;
    QComboBox *gradeLevelComboBox;
    QLabel *filePathLabel;
    QLineEdit *filePathLineEdit;
    QPushButton *browseButton;
    QPushButton *addBookButton;
};

#endif // BOOKFORM_H
