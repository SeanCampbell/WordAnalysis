#include "rti/rti_word_frequency_list.h"
#include "rti/rti_utils.h"
#include "wordfrequencyform.h"
#include <QtWidgets>

WordFrequencyForm::WordFrequencyForm(const QString &wdPath, QWidget *parent)
    : QWidget(parent)
{
    for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
        wordFrequencyModels[i] = new WordFrequencyModel;

    workingDirectoryPath_ = wdPath;
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
        wordFrequencyList_->set_threshold(numberOfMostFrequentWordsSpinBox->value());
        wordFrequencyList_->update_most_frequent_words();
        for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
        {
            wordFrequencyModels[i]->setGeneratedList(wordFrequencyList_->most_frequent_words_in_grade_level((rti_book::AGE)(i+2), numberOfMostFrequentWordsSpinBox->value()));
            wordFrequencyViews[i]->resizeColumnsToContents();
        }
        for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
        {
            double *normalizedFrequencies = wordFrequencyList_->normalized_frequencies_in_grade_level((rti_book::AGE)(i+2));
            for (int j = 0; j < NUMBER_OF_GRADE_GROUPS; j++)
            {
                QString labelValue = tr("%1%").arg(normalizedFrequencies[j]*100, 6, 'f', 2);
                gradeLevelFrequencyValueLabels[i*NUMBER_OF_GRADE_GROUPS+j]->setText(labelValue);
            }
            delete normalizedFrequencies;
        }
        setWindowModified(true);
    }
    else
    {
        std::vector<std::string> emptyList;
        for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
            wordFrequencyModels[i]->setGeneratedList(emptyList);
        for (int i = 0; i < NUMBER_OF_GRADE_GROUPS*NUMBER_OF_GRADE_GROUPS; i++)
            gradeLevelFrequencyValueLabels[i]->setText("");
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
        wordFrequencyList_->set_threshold(num);
        wordFrequencyList_->update_most_frequent_words();
        for (int i = 0; i < 5; i++)
        {
            wordFrequencyModels[i]->setGeneratedList(wordFrequencyList_->most_frequent_words_in_grade_level((rti_book::AGE)(i+2), num));
            wordFrequencyViews[i]->resizeColumnsToContents();
        }
        setWindowModified(true);
    }
}

void WordFrequencyForm::browseForFrequencyList()
{
    QString frequencyListFilePath = QFileDialog::getOpenFileName(this, tr("Choose word frequency list to laod..."),
                                                                 workingDirectoryPath_, "Text files (*.txt)");

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
                             workingDirectoryPath_, tr("XML files (*.xml)"));
    if (!wflistFilePath.isEmpty())
    {
        wordFrequencyList_->write_xml(wflistFilePath.toStdString());
        setWindowModified(false);
    }
}


//
// Private Methods
//
QWidget *WordFrequencyForm::createTabWidgetPanel(int index) const
{
    QWidget *tabPanel = new QWidget;

    QWidget *frequencyPanel = new QWidget;
    QGridLayout *frequencyLayout = new QGridLayout;
    frequencyLayout->addWidget(gradeLevelFrequencyDescriptionLabels[index], 0, 0, 2, 1);
    for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
    {
        frequencyLayout->addWidget(gradeLevelFrequencyLabels[index*NUMBER_OF_GRADE_GROUPS+i], i+1, 0);
        frequencyLayout->addWidget(gradeLevelFrequencyValueLabels[index*NUMBER_OF_GRADE_GROUPS+i], i+1, 1);
    }
    frequencyPanel->setLayout(frequencyLayout);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(wordFrequencyViews[index]);
    layout->addWidget(frequencyPanel);
    tabPanel->setLayout(layout);
    return tabPanel;

}

void WordFrequencyForm::createInterface()
{
    compareListLabel = new QLabel(tr("Compare to"));
    compareListNameLabel = new QLabel;
    browseButton = new QPushButton(tr("Browse"));
    connect(browseButton, SIGNAL(clicked(bool)), this, SLOT(browseForFrequencyList()));

    for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
        gradeLevelFrequencyDescriptionLabels[i] = new QLabel(tr("Frequency of words from each grade level:"));

    for (int i = 0; i < NUMBER_OF_GRADE_GROUPS*NUMBER_OF_GRADE_GROUPS; i += NUMBER_OF_GRADE_GROUPS)
    {
        gradeLevelFrequencyLabels[i]   = new QLabel(tr("Nursery/Pre-K/Kindergarten:"));
        gradeLevelFrequencyLabels[i+1] = new QLabel(tr("Grade 1:"));
        gradeLevelFrequencyLabels[i+2] = new QLabel(tr("Grade 2:"));
        gradeLevelFrequencyLabels[i+3] = new QLabel(tr("Grade 3:"));
        gradeLevelFrequencyLabels[i+4] = new QLabel(tr("Grade 4:"));
        for (int j = i; j < i + NUMBER_OF_GRADE_GROUPS; j++)
            gradeLevelFrequencyValueLabels[j] = new QLabel;
    }

    for (int i = 0; i < NUMBER_OF_GRADE_GROUPS; i++)
    {
        wordFrequencyViews[i] = new QTableView;
        wordFrequencyViews[i]->setModel(wordFrequencyModels[i]);
    }
    gradeLevelTabWidget = new QTabWidget;
    gradeLevelTabWidget->addTab(createTabWidgetPanel(0), tr("Nursery/Pre-K/Kindergarten"));
    gradeLevelTabWidget->addTab(createTabWidgetPanel(1), tr("Grade 1"));
    gradeLevelTabWidget->addTab(createTabWidgetPanel(2), tr("Grade 2"));
    gradeLevelTabWidget->addTab(createTabWidgetPanel(3), tr("Grade 3"));
    gradeLevelTabWidget->addTab(createTabWidgetPanel(4), tr("Grade 4"));

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
