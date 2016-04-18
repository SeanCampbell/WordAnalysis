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

class WordFrequencyForm : public QWidget
{
    public:
        explicit WordFrequencyForm(QWidget *parent = 0);
        //explicit LibraryForm(rti_word_frequency_list *list, QWidget *parent = 0);

        void setGeneratedWordFrequencyList(rti_word_frequency_list *list);
        void setInputtedWordFrequencyList(rti_word_frequency_list *list);
        rti_word_frequency_list *generatedWordFrequencyList() const { return generatedWordFrequencyList_; }
        rti_word_frequency_list *inputtedWordFrequencyList() const { return inputtedWordFrequencyList_; }

    private:
        void createInterface();
        void layoutInterface();

        // Data
        rti_word_frequency_list *generatedWordFrequencyList_;
        rti_word_frequency_list *inputtedWordFrequencyList_;
        WordFrequencyModel *wordFrequencyModels[NUMBER_OF_GRADE_GROUPS];
        QSortFilterProxyModel *proxyModels[NUMBER_OF_GRADE_GROUPS];

        // GUI
        QLabel *wordFrequencyListLabel;
        QComboBox *wordFrequencyListComboBox;
        QLabel *searchLabel;
        QLineEdit *searchLineEdit;
        QTabWidget *gradeLevelTabWidget;
        QTableView *wordFrequencyViews[NUMBER_OF_GRADE_GROUPS];
};

#endif // WORDFREQUENCYFORM_H
