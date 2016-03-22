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
class QLineEdit;
class QSortFilterProxyModel;

class DictionaryForm : public QWidget
{
    Q_OBJECT
public:
    explicit DictionaryForm(QWidget *parent = 0);
    explicit DictionaryForm(QMap<QString, rti_dictionary *> dictMap, QWidget *parent = 0);
    explicit DictionaryForm(std::map<std::string, rti_dictionary *> dictMap, QWidget *parent = 0);

    rti_dictionary *masterDictionary() const { return masterDictionary_; }

public slots:
    bool addDictionary(const QString &name, rti_dictionary *dictionary);
    void setMasterDictionary(rti_dictionary *master);

private slots:
    void search(const QString &searchTerm);
    void showOnlyIncompleteWords(bool incomplete);
    void changeDictionary(const QString &dictName);
    void importFromMaster();
    void deleteDictionary();

private:
    void init(QMap<QString, rti_dictionary *> dictMap);
    void createInterface();
    void layoutInterface();

    // Data
    rti_dictionary *masterDictionary_;
    QMap<QString, rti_dictionary *> dictionaryMap;
    DictionaryModel *dictionaryModel;
    QSortFilterProxyModel *proxyModel;

    // GUI
    QTableView *dictionaryView;

    QLabel *dictionaryLabel;
    QComboBox *dictionaryComboBox;
    QCheckBox *incompleteWordsCheckBox;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QPushButton *importFromMasterButton;
    QPushButton *deleteDictionaryButton;
};

#endif // DICTIONARYFORM_H
