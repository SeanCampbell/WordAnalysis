#ifndef WORDFREQUENCYFORM_H
#define WORDFREQUENCYFORM_H

#define NUMBER_OF_GRADE_GROUPS 5

#include "wordfrequencymodel.h"
#include <QWidget>
#include <QSortFilterProxyModel>
class QComboBox;
class QTabWidget;
class QTableView;
class QLabel;
class QLineEdit;
class QSpinBox;

class WordFrequencyForm : public QWidget
{
        Q_OBJECT
    public:
        explicit WordFrequencyForm(QWidget *parent = 0);
        //explicit LibraryForm(rti_word_frequency_list *list, QWidget *parent = 0);

    public slots:
        bool addWordFrequencyList(const QString &name, rti_word_frequency_list *list);

    private slots:
        void changeWordList(const QString &listName);
        void changeCompareWordList(const QString &listName);
        void updateGeneratedList(int num);
        void updateInputtedList(int num);

    private:
        void createInterface();
        void layoutInterface();

        // Data
        rti_word_frequency_list *generatedWordFrequencyList_;
        rti_word_frequency_list *inputtedWordFrequencyList_;
        QMap<QString, rti_word_frequency_list*> frequencyListMap;
        WordFrequencyModel *wordFrequencyModels[NUMBER_OF_GRADE_GROUPS];
        QSortFilterProxyModel *proxyModels[NUMBER_OF_GRADE_GROUPS];

        // GUI
        QLabel *wordFrequencyListLabel;
        QComboBox *wordFrequencyListComboBox;
        QLabel *compareListLabel;
        QComboBox *compareListComboBox;
        QLabel *searchLabel;
        QLineEdit *searchLineEdit;
        QLabel *numberOfMostFrequentWordsLabel;
        QSpinBox *numberOfMostFrequentWordsSpinBox;
        QTabWidget *gradeLevelTabWidget;
        QTableView *wordFrequencyViews[NUMBER_OF_GRADE_GROUPS];
};

#endif // WORDFREQUENCYFORM_H
