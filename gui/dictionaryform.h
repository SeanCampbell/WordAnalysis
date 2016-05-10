#ifndef DICTIONARYFORM_H
#define DICTIONARYFORM_H

#include <QWidget>
#include <QMap>
class rti_dictionary;
class DictionaryModel;
class QTableView;
class QLabel;
class QComboBox;
class QCheckBox;
class QPushButton;
class QRadioButton;
class QLineEdit;
class QSortFilterProxyModel;

class DictionaryForm : public QWidget
{
    Q_OBJECT
public:
    explicit DictionaryForm(const QString &wdPath = "", QWidget *parent = 0);
    explicit DictionaryForm(rti_dictionary *dict, const QString &wdPath = "", QWidget *parent = 0);

    void setWorkingDirectoryPath(const QString &wdPath) { workingDirectoryPath_ = wdPath; }
    rti_dictionary *masterDictionary() const { return masterDictionary_; }
    rti_dictionary *dictionary() const { return dictionary_; }

public slots:
    void setDictionary(rti_dictionary *dictionary);
    void setMasterDictionary(rti_dictionary *master);

private slots:
    void search(const QString &searchTerm);
    void showOnlyIncompleteWords(bool incomplete);
    void changeDictionary();
    void importFromMaster();
    void setModified();
    void exportDictionary();

private:
    void init(rti_dictionary *dict, const QString &wdPath);
    void createInterface();
    void layoutInterface();

    // Data
    QString workingDirectoryPath_;
    rti_dictionary *masterDictionary_;
    rti_dictionary *dictionary_;
    DictionaryModel *dictionaryModel;
    QSortFilterProxyModel *proxyModel;

    // GUI
    QTableView *dictionaryView;

    QLabel *dictionaryLabel;
    QRadioButton *masterDictionaryRadioButton;
    QRadioButton *currentDictionaryRadioButton;
    QCheckBox *incompleteWordsCheckBox;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QPushButton *exportDictionaryButton;
    QPushButton *importFromMasterButton;
};

#endif // DICTIONARYFORM_H
