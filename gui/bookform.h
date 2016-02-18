#ifndef BOOKFORM_H
#define BOOKFORM_H

#include "rti/rti_book.h"
#include <QWidget>
#include <QLineEdit>
class QLabel;
class QTextEdit;
class QComboBox;
class QPushButton;

class BookForm : public QWidget
{
    Q_OBJECT

public:
    explicit BookForm(QWidget *parent = 0);
    explicit BookForm(rti_book *book, bool editable = false, QWidget *parent = 0);

    // Accessors
    rti_book *book() const { return _book; }
    bool isEditable() const { return !isbnLineEdit->isReadOnly(); }

    // Mutators
    void setBook(rti_book *book);
    void setEditable(bool editable);

private slots:
    void updateBook();

private:
    void init();
    void createInterface();
    void layoutInterface();

    // Data
    bool _isEditable;
    rti_book *_book;
    QMap<rti_book::AGE, QString> gradeLevelMap;

    // GUI
    QLabel *isbnLabel;
    QLineEdit *isbnLineEdit;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *authorLabel;
    QLineEdit *authorLineEdit;
    QLabel *gradeLevelLabel;
    QComboBox *gradeLevelComboBox;
    QLabel *contentsLabel;
    QTextEdit *contentsTextEdit;
    QPushButton *updateBookButton;
};

#endif // BOOKFORM_H
