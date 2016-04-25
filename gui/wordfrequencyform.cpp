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
// Public Slots
//
bool WordFrequencyForm::addWordFrequencyList(const QString &name, rti_word_frequency_list *list)
{
    if (!frequencyListMap.contains(name))
    {
        frequencyListMap.insert(name, list);
        wordFrequencyListComboBox->addItem(name);
        wordFrequencyListComboBox->setCurrentText(name);
        compareListComboBox->addItem(name);
        return true;
    }
    return false;
}

//
// Private Slots
//
void WordFrequencyForm::changeWordList(const QString &listName)
{
    if (frequencyListMap.contains(listName))
    {
        rti_word_frequency_list *frequencyList = frequencyListMap.value(listName);
        for (int i = 0; i < 5; i++)
        {
            wordFrequencyModels[i]->setGeneratedList(frequencyList->most_frequent_words_in_grade_level((rti_book::AGE)(i+2), numberOfMostFrequentWordsSpinBox->value()));
            wordFrequencyViews[i]->resizeColumnsToContents();
        }

    }
    else
    {
        std::vector<std::string> emptyList;
        for (int i = 0; i < 5; i++)
            wordFrequencyModels[i]->setGeneratedList(emptyList);
    }
}

void WordFrequencyForm::changeCompareWordList(const QString &listName)
{
    if (frequencyListMap.contains(listName))
    {
        rti_word_frequency_list *frequencyList = frequencyListMap.value(listName);
        for (int i = 0; i < 5; i++)
        {
            wordFrequencyModels[i]->setInputtedList(frequencyList->most_frequent_words_in_grade_level((rti_book::AGE)(i+2), numberOfMostFrequentWordsSpinBox->value()));
            wordFrequencyViews[i]->resizeColumnsToContents();
        }

    }
    else
    {
        std::vector<std::string> emptyList;
        for (int i = 0; i < 5; i++)
            wordFrequencyModels[i]->setInputtedList(emptyList);
    }
}

void WordFrequencyForm::updateGeneratedList(int num)
{
    rti_word_frequency_list *frequencyList = frequencyListMap.value(wordFrequencyListComboBox->currentText());
    if (frequencyList)
    {
        for (int i = 0; i < 5; i++)
        {
            wordFrequencyModels[i]->setGeneratedList(frequencyList->most_frequent_words_in_grade_level((rti_book::AGE)(i+2), num));
            wordFrequencyViews[i]->resizeColumnsToContents();
        }
    }
}

void WordFrequencyForm::updateInputtedList(int num)
{
    rti_word_frequency_list *frequencyList = frequencyListMap.value(compareListComboBox->currentText());
    if (frequencyList)
    {
        for (int i = 0; i < 5; i++)
        {
            wordFrequencyModels[i]->setInputtedList(frequencyList->most_frequent_words_in_grade_level((rti_book::AGE)(i+2), num));
            wordFrequencyViews[i]->resizeColumnsToContents();
        }
    }
}


//
// Private Methods
//
void WordFrequencyForm::createInterface()
{
    wordFrequencyListLabel = new QLabel(tr("Word Frequency List"));
    wordFrequencyListComboBox = new QComboBox;
    connect(wordFrequencyListComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(changeWordList(QString)));
    compareListLabel = new QLabel(tr("Compare to"));
    compareListComboBox = new QComboBox;
    connect(compareListComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(changeCompareWordList(QString)));

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

    numberOfMostFrequentWordsLabel = new QLabel(tr("Number of most frequent words:"));
    numberOfMostFrequentWordsSpinBox = new QSpinBox;
    numberOfMostFrequentWordsSpinBox->setRange(1, 100);
    numberOfMostFrequentWordsSpinBox->setValue(50);
    connect(numberOfMostFrequentWordsSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateGeneratedList(int)));
    connect(numberOfMostFrequentWordsSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateInputtedList(int)));
}

void WordFrequencyForm::layoutInterface()
{
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(wordFrequencyListLabel);
    topLayout->addWidget(wordFrequencyListComboBox);
    topLayout->addWidget(compareListLabel);
    topLayout->addWidget(compareListComboBox);
    topLayout->addStretch();
    topLayout->addWidget(numberOfMostFrequentWordsLabel);
    topLayout->addWidget(numberOfMostFrequentWordsSpinBox);
    //topLayout->addWidget(searchLabel);
    //topLayout->addWidget(searchLineEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(gradeLevelTabWidget);
    setLayout(mainLayout);
}
