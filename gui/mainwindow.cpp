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
}


//
// Private Slots
//
void MainWindow::importLibrary()
{
    QString libraryFilePath = QFileDialog::getOpenFileName(this, tr("Choose library file to import..."),
                                                           "", "XML files (*.xml)");
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
                                                           "", "XML files (*.xml)");
    if (!libraryFilePath.isEmpty())
        libraryForm->library()->write_xml(libraryFilePath.toStdString());
}

void MainWindow::importMasterDictionary()
{
    QString masterDictionaryFilePath = QFileDialog::getOpenFileName(this, tr("Choose master dictionary file to import..."),
                                                                    "", "XML files (*.xml)");

    if (!masterDictionaryFilePath.isEmpty())
    {
        rti_dictionary *masterDictionary = new rti_dictionary;
        masterDictionary->read_xml(masterDictionaryFilePath.toStdString());
        dictionaryForm->setMasterDictionary(masterDictionary);
        tabWidget->setCurrentWidget(dictionaryForm);
    }
}

void MainWindow::exportMasterDictionary()
{
    QString masterDictionaryFilePath = QFileDialog::getSaveFileName(this, tr("Choose file to save master dictionary into..."),
                                                                    "", "XML files (*.xml)");

    if (!masterDictionaryFilePath.isEmpty())
        // boolean value isn't used for anything - should double check why it's there
        dictionaryForm->masterDictionary()->write_xml(masterDictionaryFilePath.toStdString(), true);
}

void MainWindow::displayMorphemes() const
{

}


void MainWindow::createDictionary(QList<rti_book*> books)
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
    rti_dictionary *dictionary = rti_utils::build_dictionary(library, dictionaryForm->masterDictionary(), arpabets, &upToDate);
    // We have no more need of this. Dispose of it.
    delete library;

    // Prompt for a name for the dictionary.
    QString masterDictionaryMessage = dictionaryForm->masterDictionary() != NULL
            ? "Some missing information imported from master dictionary.\n\n"
            : "";
    QString dictionaryName = QInputDialog::getText(this, tr("Dictionary Name"), tr("%1Give a name to the dictionary:").arg(masterDictionaryMessage));
    if (!dictionaryName.isEmpty())
    {
        dictionaryForm->addDictionary(dictionaryName, dictionary);
        tabWidget->setCurrentWidget(dictionaryForm);
    }
}

void MainWindow::createFrequencyList(QList<rti_book*> books)
{

}


//
// Private Methods
//
void MainWindow::setupInterface()
{
    libraryForm = new LibraryForm;
    connect(libraryForm, SIGNAL(createDictionaryRequested(QList<rti_book*>)),
            this, SLOT(createDictionary(QList<rti_book*>)));
    dictionaryForm = new DictionaryForm;
    wordFrequencyForm = new WordFrequencyForm;
    tabWidget = new QTabWidget;

    tabWidget->addTab(libraryForm, tr("Library"));
    tabWidget->addTab(dictionaryForm, tr("Dictionary"));
    tabWidget->addTab(wordFrequencyForm, tr("Word Frequency"));

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
    quitAction = fileMenu->addAction(tr("&Quit"));
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(close()));

    viewMenu = menuBar()->addMenu(tr("&View"));
    displayMorphemesAction = viewMenu->addAction(tr("Display Morphemes"));
    connect(displayMorphemesAction, SIGNAL(triggered(bool)), this, SLOT(displayMorphemes()));
}
