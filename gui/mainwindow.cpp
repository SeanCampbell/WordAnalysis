#include "dictionaryform.h"
#include "libraryform.h"
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

}

void MainWindow::exportLibrary() const
{

}

void MainWindow::importMasterDictionary()
{

}

void MainWindow::exportMasterDictionary() const
{

}

void MainWindow::displayMorphemes() const
{

}


//
// Private Methods
//
void MainWindow::setupInterface()
{
    dictionaryForm = new DictionaryForm;
    libraryForm = new LibraryForm;
    tabWidget = new QTabWidget;

    tabWidget->addTab(dictionaryForm, tr("Dictionary"));
    tabWidget->addTab(libraryForm, tr("Library"));

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
