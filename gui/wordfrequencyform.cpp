#include "rti/rti_word_frequency_list.h"
#include "rti/rti_utils.h"
#include "wordfrequencyform.h"
#include <QtWidgets>

WordFrequencyForm::WordFrequencyForm(const QString &wdPath, QWidget *parent)
    : QWidget(parent)
{
    for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
        wordFrequencyModels[i] = new WordFrequencyModel;

    workingDirectoryPath = wdPath;
    createInterface();
    layoutInterface();
}


//
// Public Slots
//
void WordFrequencyForm::setWordFrequencyList(rti_word_frequency_list *list)
{
    wordFrequencyList_ = list;
    if (wordFrequencyList_ != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            wordFrequencyModels[i]->setGeneratedList(wordFrequencyList_->most_frequent_words_in_grade_level((rti_book::AGE)(i+2), numberOfMostFrequentWordsSpinBox->value()));
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

void WordFrequencyForm::setCompareWordFrequencyList(rti_word_frequency_list *list)
{
    compareWordFrequencyList_ = list;
    if (compareWordFrequencyList_ != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            wordFrequencyModels[i]->setInputtedList(compareWordFrequencyList_->words_in_grade_level((rti_book::AGE)(i+2)));
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


//
// Private Slots
//
void WordFrequencyForm::updateGeneratedList(int num)
{
    if (wordFrequencyList_)
    {
        for (int i = 0; i < 5; i++)
        {
            wordFrequencyModels[i]->setGeneratedList(wordFrequencyList_->most_frequent_words_in_grade_level((rti_book::AGE)(i+2), num));
            wordFrequencyViews[i]->resizeColumnsToContents();
        }
    }
}

void WordFrequencyForm::browseForFrequencyList()
{
    QString frequencyListFilePath = QFileDialog::getOpenFileName(this, tr("Choose word frequency list to laod..."),
                                                                 workingDirectoryPath, "Text files (*.txt)");

    if (!frequencyListFilePath.isEmpty())
    {
        rti_word_frequency_list *wflist = new rti_word_frequency_list;
        QFile listFile(frequencyListFilePath);
        if (!listFile.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, tr("Error Opening File"), tr("There was an error opening the file."));
            return;
        }
        compareListNameLabel->setText(QFileInfo(listFile.fileName()).fileName());
        QTextStream in(&listFile);
        int gradeLevel = 0;
        while (!in.atEnd())
        {
            // Only take the first five lines.
            if (gradeLevel < 5)
            {
                QStringList words = in.readLine().split(" ");
                foreach (QString word, words)
                    // Add word at the threshold so that we know it will be counted as a
                    // most frequent word.
                    wflist->add_word_in_grade_level(word.toStdString(), wflist->threshold(), (rti_book::AGE)(gradeLevel+2));
            }
            else
                break;
            gradeLevel++;
        }
        wflist->update_most_frequent_words();
        setCompareWordFrequencyList(wflist);
    }
}

void WordFrequencyForm::exportFrequencyList()
{
    if (!wordFrequencyList_)
    {
        QMessageBox::information(this, tr("Unable to export frequency list"),
                                 tr("Unable to export frequency list. There is no list to export."));
        return;
    }

    QString wflistFilePath = QFileDialog::getSaveFileName(this, tr("Save word frequency list file..."),
                             workingDirectoryPath, tr("Text files (*.txt)"));
    QFile wflistFile(wflistFilePath);
    if (!wflistFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, tr("Error Opening File"), tr("There was an error opening the file."));
        return;
    }
    QTextStream stream(&wflistFile);
    for (int i = 0; i < 5; i++)
        stream << QString::fromStdString(rti_utils::join(wordFrequencyList_->most_frequent_words_in_grade_level((rti_book::AGE)(i+2), numberOfMostFrequentWordsSpinBox->value()), " ")) << "\n";
    wflistFile.close();
}


//
// Private Methods
//
void WordFrequencyForm::createInterface()
{
    compareListLabel = new QLabel(tr("Compare to"));
    compareListNameLabel = new QLabel;
    browseButton = new QPushButton(tr("Browse"));
    connect(browseButton, SIGNAL(clicked(bool)), this, SLOT(browseForFrequencyList()));

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

    exportFrequencyListButton = new QPushButton(tr("Export Word Frequency List"));
    connect(exportFrequencyListButton, SIGNAL(clicked(bool)), this, SLOT(exportFrequencyList()));
}

void WordFrequencyForm::layoutInterface()
{
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(compareListLabel);
    topLayout->addWidget(compareListNameLabel);
    topLayout->addWidget(browseButton);
    topLayout->addStretch();
    topLayout->addWidget(numberOfMostFrequentWordsLabel);
    topLayout->addWidget(numberOfMostFrequentWordsSpinBox);
    //topLayout->addWidget(searchLabel);
    //topLayout->addWidget(searchLineEdit);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(exportFrequencyListButton);
    bottomLayout->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(gradeLevelTabWidget);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);
}
