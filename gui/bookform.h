#ifndef BOOKFORM_H
#define BOOKFORM_H

#include <QtWidgets>
#include "rti/rti_book.h"

class BookForm : public QWidget
{
public:
    Q_OBJECT

    BookForm(QWidget *parent = 0);
    BookForm(rti_book *book, bool isEditable = false, QWidget *parent = 0);

    rti_book *book() const { return _book; }
    bool isEditable() const { return _isEditable; }

private slots:
    void updateBook();

private:
    void createInterface();
    void layoutInterface();

    // Data
    bool _isEditable;
    rti_book *_book;

    // GUI
    QLabel *isbnLabel;
    QLineEdit *isbnLineEdit;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *authorLabel;
    QLineEdit *authorLineEdit;
    QLabel *gradeLevelLabel;
    QLineEdit *gradeLevelLineEdit;
    QLabel *contentsLabel;
    QTextEdit *contentsTextArea;
    QPushButton *updateBookButton;
};

#endif // BOOKFORM_H
