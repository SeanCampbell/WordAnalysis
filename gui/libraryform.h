#ifndef LIBRARYFORM_H
#define LIBRARYFORM_H

#include "rti/rti_book.h"
#include "librarymodel.h"
#include <QMap>
#include <QWidget>
class rti_literature;
class LibraryModel;
class QTableView;
class QLabel;
class QComboBox;
class QCheckBox;
class QLineEdit;
class QPushButton;
class QSortFilterProxyModel;

class LibraryForm : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryForm(QWidget *parent = 0);
    explicit LibraryForm(rti_literature *library, QWidget *parent = 0);

    void setLibrary(rti_literature *library);
    rti_literature *library() { return libraryModel->library(); }

signals:
    void createDictionaryAndFrequencyListRequested(QList<rti_book *> books);

private slots:
    void selectBooksWithGradeLevel(const QString &gradeLevel);
    void removeSelectedBooks();
    void search(const QString &searchTerm);

    void addBook();
    void createDictionaryAndFrequencyList();

private:
    void init(rti_literature *library);
    void createInterface();
    void layoutInterface();

    // Data
    LibraryModel *libraryModel;
    QSortFilterProxyModel *proxyModel;

    // GUI
    QTableView *libraryView;

    QCheckBox *selectAllCheckBox;
    QLabel *selectGradeLevelLabel;
    QComboBox *selectGradeLevelComboBox;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;

    QPushButton *addBookButton;
    QPushButton *removeBooksButton;
    QPushButton *createDictionaryAndFrequencyListButton;
};

#endif // LIBRARYFORM_H
