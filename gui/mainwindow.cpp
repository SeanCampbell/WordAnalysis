#include "libraryform.h"
#include "dictionaryform.h"
#include "wordfrequencyform.h"
#include "rti/rti_literature.h"
#include "rti/rti_utils.h"
#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupInterface();
    setWindowTitle(tr("Word Analysis"));
    QSettings settings("Iona College", "Word Frequency Analysis");
    workingDirectoryPath = settings.value("workingDirectoryPath").toString();
}


//
// Private Slots
//
void MainWindow::importLibrary()
{
    QString libraryFilePath = QFileDialog::getOpenFileName(this, tr("Choose library file to import..."),
                                                           workingDirectoryPath, "XML files (*.xml)");
    if (!libraryFilePath.isEmpty())
    {
        rti_literature *library = new rti_literature;
        library->read_xml(libraryFilePath.toStdString());
        libraryForm->setLibrary(library);
        tabWidget->setCurrentWidget(libraryForm);
    }
}

void MainWindow::exportLibrary()
{
    QString libraryFilePath = QFileDialog::getSaveFileName(this, tr("Choose file to save exported library into..."),
                                                           workingDirectoryPath, "XML files (*.xml)");
    if (!libraryFilePath.isEmpty())
        libraryForm->library()->write_xml(libraryFilePath.toStdString());
}

void MainWindow::importMasterDictionary()
{
    QString masterDictionaryFilePath = QFileDialog::getOpenFileName(this, tr("Choose master dictionary file to import..."),
                                                                    workingDirectoryPath, "XML files (*.xml)");

    if (!masterDictionaryFilePath.isEmpty())
    {
        rti_dictionary *masterDictionary = new rti_dictionary;
        masterDictionary->read_xml(masterDictionaryFilePath.toStdString());
        dictionaryForm->setMasterDictionary(masterDictionary);
        QMessageBox::information(this, tr("Master Dictionary Loaded"), tr("Master dictionary loaded successfully."));
    }
}

void MainWindow::exportMasterDictionary()
{
    QString masterDictionaryFilePath = QFileDialog::getSaveFileName(this, tr("Choose file to save master dictionary into..."),
                                                                    workingDirectoryPath, "XML files (*.xml)");

    if (!masterDictionaryFilePath.isEmpty())
        // boolean value isn't used for anything - should double check why it's there
        dictionaryForm->masterDictionary()->write_xml(masterDictionaryFilePath.toStdString(), true);
}

void MainWindow::displayMorphemes() const
{
    popupImage("morphemes.png");
}

void MainWindow::displayArpabets() const
{
    popupImage("arpabet.png");
}

void MainWindow::displayFunctionWords() const
{
    popupImage("content_and_functions_words_01.png");
    popupImage("content_and_functions_words_02.png");
}

void MainWindow::createDictionaryAndFrequencyList(QList<rti_book *> books)
{
    if (books.isEmpty())
    {
        QMessageBox::information(this, tr("No books selected"),
                                 tr("Unable to create dictionary and word frequency list. "
                                    "No books selected."));
        return;
    }

    createFrequencyList(books);
    if (createDictionary(books))
        tabWidget->setCurrentWidget(dictionaryForm);
}

bool MainWindow::createDictionary(QList<rti_book*> books)
{
    int index;
    rti_literature *library = new rti_literature;
    foreach (rti_book *book, books)
        if (!library->find(book->isbn(), index))
            library->insert(book, index);
    vcl_vector<vcl_pair<vcl_string, vcl_string> > arpabets;
    // TODO: REFERENCE A RESOURCE HERE
    rti_utils::import_cmu_dictionary("cmudict-0.7b.txt", arpabets);
    bool upToDate;

    rti_dictionary *dictionary;
    // Check if user would like to import information from the master dictionary.
    if (QMessageBox::question(this, tr("Import from Master Dictionary"),
                          tr("Would you like to import information from the master dictionary?"))
            == QMessageBox::Yes)
    {
        if (!dictionaryForm->masterDictionary())
        {
            QMessageBox::information(this, tr("No Master Dictionary"), tr("There is no master dictionary set. "
                                     "Please import a master dictionary and try again."));
            return false;
        }
        dictionary = rti_utils::build_dictionary(library, dictionaryForm->masterDictionary(), arpabets, &upToDate);
    }
    else
    {
        dictionary = rti_utils::build_dictionary(library, NULL, arpabets, &upToDate);
    }

    // We have no more need of this. Dispose of it.
    delete library;

    dictionaryForm->setDictionary(dictionary);
    return true;
}

void MainWindow::createFrequencyList(QList<rti_book*> books)
{
    int index;
    rti_literature *library = new rti_literature;
    foreach (rti_book *book, books)
        if (!library->find(book->isbn(), index))
            library->insert(book, index);

    rti_word_frequency_list *wflist = rti_utils::generate_word_frequency_list_from_literature(library, 10);
    // We have no more need of this. Dispose of it.
    delete library;

    // Prompt for a name for the word list.
    wordFrequencyForm->setWordFrequencyList(wflist);
}

void MainWindow::setWorkingDirectoryPath()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Choose working directory..."), workingDirectoryPath);
    if (!path.isEmpty())
    {
        workingDirectoryPath = path;
        QSettings settings("Iona College", "Word Frequency Analysis");
        settings.setValue("workingDirectoryPath", workingDirectoryPath);
    }
}


//
// Private Methods
//
void MainWindow::popupImage(const QString &fileName) const
{
    QPixmap image = QPixmap::fromImage(QImage(fileName));
    QLabel *morphemesLabel = new QLabel;
    morphemesLabel->setPixmap(image);
    morphemesLabel->resize(image.size());
    morphemesLabel->show();
}

void MainWindow::setupInterface()
{
    libraryForm = new LibraryForm;
    connect(libraryForm, SIGNAL(createDictionaryAndFrequencyListRequested(QList<rti_book*>)),
            this, SLOT(createDictionaryAndFrequencyList(QList<rti_book*>)));
    dictionaryForm = new DictionaryForm;
    wordFrequencyForm = new WordFrequencyForm;
    tabWidget = new QTabWidget;

    tabWidget->addTab(libraryForm, tr("Library"));
    tabWidget->addTab(dictionaryForm, tr("Dictionary"));
    tabWidget->addTab(wordFrequencyForm, tr("Word Frequency List"));

    // Stick tab widget in another widget, because
    // otherwise the margins are too small.
    QWidget *centralWidget = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(tabWidget);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    createMenus();
}

void MainWindow::createMenus()
{
    menuBar()->setNativeMenuBar(false);

    fileMenu = menuBar()->addMenu(tr("&File"));
    importLibraryAction = fileMenu->addAction(tr("Import Library"));
    menuBar()->addAction(fileMenu->menuAction());
    connect(importLibraryAction, SIGNAL(triggered(bool)), this, SLOT(importLibrary()));
    exportLibraryAction = fileMenu->addAction(tr("Export Library"));
    connect(exportLibraryAction, SIGNAL(triggered(bool)), this, SLOT(exportLibrary()));
    fileMenu->addSeparator();
    importMasterDictionaryAction = fileMenu->addAction(tr("Import Master Dictionary"));
    connect(importMasterDictionaryAction, SIGNAL(triggered(bool)), this, SLOT(importMasterDictionary()));
    exportMasterDictionaryAction = fileMenu->addAction(tr("Export Master Dictionary"));
    connect(exportMasterDictionaryAction, SIGNAL(triggered(bool)), this, SLOT(exportMasterDictionary()));
    fileMenu->addSeparator();
    setWorkingDirectoryPathAction = fileMenu->addAction(tr("Set Working Directory"));
    connect(setWorkingDirectoryPathAction, SIGNAL(triggered(bool)), this, SLOT(setWorkingDirectoryPath()));
    fileMenu->addSeparator();
    quitAction = fileMenu->addAction(tr("&Quit"));
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(close()));

    lookupTablesMenu = menuBar()->addMenu(tr("&Lookup Tables"));
    displayMorphemesAction = lookupTablesMenu->addAction(tr("Morphemes"));
    connect(displayMorphemesAction, SIGNAL(triggered(bool)), this, SLOT(displayMorphemes()));
    displayArpabetsAction = lookupTablesMenu->addAction(tr("Arpabets"));
    connect(displayArpabetsAction, SIGNAL(triggered(bool)), this, SLOT(displayArpabets()));
    displayFunctionWordsAction = lookupTablesMenu->addAction(tr("Function/Content Word Information"));
    connect(displayFunctionWordsAction, SIGNAL(triggered(bool)), this, SLOT(displayFunctionWords()));
}
