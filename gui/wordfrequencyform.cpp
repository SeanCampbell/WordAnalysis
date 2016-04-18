#include "rti/rti_word_frequency_list.h"
#include "wordfrequencyform.h"
#include <QtWidgets>

WordFrequencyForm::WordFrequencyForm(QWidget *parent)
    : QWidget(parent)
{
    for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
        wordFrequencyModels[i] = new WordFrequencyModel;

    createInterface();
    layoutInterface();
}


//
// Public Methods
//
void WordFrequencyForm::setGeneratedWordFrequencyList(rti_word_frequency_list *list)
{
    generatedWordFrequencyList_ = list;
    wordFrequencyModels[0]->setGeneratedList(list->words_in_grade_level(rti_book::NS));
    wordFrequencyModels[1]->setGeneratedList(list->words_in_grade_level(rti_book::G1));
    wordFrequencyModels[2]->setGeneratedList(list->words_in_grade_level(rti_book::G2));
    wordFrequencyModels[3]->setGeneratedList(list->words_in_grade_level(rti_book::G3));
    wordFrequencyModels[4]->setGeneratedList(list->words_in_grade_level(rti_book::G4));
}

void WordFrequencyForm::setInputtedWordFrequencyList(rti_word_frequency_list *list)
{
    inputtedWordFrequencyList_ = list;
    wordFrequencyModels[0]->setInputtedList(list->words_in_grade_level(rti_book::NS));
    wordFrequencyModels[1]->setInputtedList(list->words_in_grade_level(rti_book::G1));
    wordFrequencyModels[2]->setInputtedList(list->words_in_grade_level(rti_book::G2));
    wordFrequencyModels[3]->setInputtedList(list->words_in_grade_level(rti_book::G3));
    wordFrequencyModels[4]->setInputtedList(list->words_in_grade_level(rti_book::G4));
}


//
// Private Methods
//
void WordFrequencyForm::createInterface()
{
    wordFrequencyListLabel = new QLabel(tr("Word Frequency List"));
    wordFrequencyListComboBox = new QComboBox;

    for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
    {
        wordFrequencyViews[i] = new QTableView;
        wordFrequencyViews[i]->setModel(wordFrequencyModels[i]);
    }
    gradeLevelTabWidget = new QTabWidget;
    gradeLevelTabWidget->addTab(wordFrequencyViews[0], tr("Nursery/Pre-K/Kindergarten"));
    gradeLevelTabWidget->addTab(wordFrequencyViews[1], tr("Grade 1"));
    gradeLevelTabWidget->addTab(wordFrequencyViews[2], tr("Grade 2"));
    gradeLevelTabWidget->addTab(wordFrequencyViews[3], tr("Grade 3"));
    gradeLevelTabWidget->addTab(wordFrequencyViews[4], tr("Grade 4"));

    searchLabel = new QLabel(tr("Search"));
    searchLineEdit = new QLineEdit;
}

void WordFrequencyForm::layoutInterface()
{
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(wordFrequencyListLabel);
    topLayout->addWidget(wordFrequencyListComboBox);
    topLayout->addStretch();
    //topLayout->addWidget(searchLabel);
    //topLayout->addWidget(searchLineEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(gradeLevelTabWidget);
    setLayout(mainLayout);
}
