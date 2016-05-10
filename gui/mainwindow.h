//:
// \file
// \author Sean Campbell
// \date   April 2016

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class LibraryForm;
class DictionaryForm;
class WordFrequencyForm;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void importLibrary();
    void exportLibrary();
    void importMasterDictionary();
    void exportMasterDictionary();
    void displayMorphemes() const;
    void displayArpabets() const;
    void displayFunctionWords() const;

    void createDictionaryAndFrequencyList(QList<rti_book*> books);
    bool createDictionary(QList<rti_book*> books);
    void createFrequencyList(QList<rti_book*> books);

    void setWorkingDirectoryPath();

private:
    void popupImage(const QString &fileName) const;
    void setupInterface();
    void createMenus();

    // Data
    QString workingDirectoryPath;

    // GUI
    DictionaryForm *dictionaryForm;
    LibraryForm *libraryForm;
    WordFrequencyForm *wordFrequencyForm;
    QTabWidget *tabWidget;
    QMenu *fileMenu;
    QAction *importLibraryAction;
    QAction *exportLibraryAction;
    QAction *importMasterDictionaryAction;
    QAction *exportMasterDictionaryAction;
    QAction *setWorkingDirectoryPathAction;
    QAction *quitAction;
    QMenu *lookupTablesMenu;
    QAction *displayMorphemesAction;
    QAction *displayArpabetsAction;
    QAction *displayFunctionWordsAction;
};

#endif // MAINWINDOW_H
