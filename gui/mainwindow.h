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

private slots:
    void importLibrary();
    void exportLibrary();
    void importMasterDictionary();
    void exportMasterDictionary();
    void loadWordFrequencyList();
    void displayMorphemes() const;
    void displayArpabets() const;
    void displayFunctionWords() const;

    void createDictionary(QList<rti_book*> books);
    void createFrequencyList(QList<rti_book*> books);

private:
    void popupImage(const QString &fileName) const;
    void setupInterface();
    void createMenus();

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
    QAction *loadWordFrequencyListAction;
    QAction *quitAction;
    QMenu *viewMenu;
    QAction *displayMorphemesAction;
    QAction *displayArpabetsAction;
    QAction *displayFunctionWordsAction;
};

#endif // MAINWINDOW_H
