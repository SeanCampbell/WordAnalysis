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
    explicit DictionaryForm(QWidget *parent = 0);
    explicit DictionaryForm(rti_dictionary *dict, QWidget *parent);

    rti_dictionary *masterDictionary() const { return masterDictionary_; }

public slots:
    void setDictionary(rti_dictionary *dictionary);
    void setMasterDictionary(rti_dictionary *master);

private slots:
    void search(const QString &searchTerm);
    void showOnlyIncompleteWords(bool incomplete);
    void changeDictionary();
    void importFromMaster();

private:
    void init(rti_dictionary *dict);
    void createInterface();
    void layoutInterface();

    // Data
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
    QPushButton *importFromMasterButton;
};

#endif // DICTIONARYFORM_H
