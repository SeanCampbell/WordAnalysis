#ifndef LIBRARYFORM_H
#define LIBRARYFORM_H

#include "rti/rti_book.h"
#include <QMap>
#include <QWidget>
class rti_literature;
class LibraryModel;
class QTableView;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class QSortFilterProxyModel;

class LibraryForm : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryForm(QWidget *parent = 0);
    explicit LibraryForm(rti_literature *library, QWidget *parent = 0);

private slots:
    void selectBooksWithGradeLevel(const QString &gradeLevel);
    void search(const QString &searchTerm);

    void addBook();
    void editBook();
    void viewBook();
    void createDictionary();
    void createFrequencyList();

private:
    void init(rti_literature *library);
    void createInterface();
    void layoutInterface();

    // Data
    QMap<rti_book::AGE, QString> gradeLevelMap;
    LibraryModel *libraryModel;
    QSortFilterProxyModel *proxyModel;

    // GUI
    QTableView *libraryView;

    QLabel *selectGradeLevelLabel;
    QComboBox *selectGradeLevelComboBox;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;

    QPushButton *addBookButton;
    QPushButton *editBookButton;
    QPushButton *viewBookButton;
    QPushButton *createDictionaryButton;
    QPushButton *createFrequencyListButton;
};

#endif // LIBRARYFORM_H
