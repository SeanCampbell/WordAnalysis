#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class DictionaryForm;
class LibraryForm;

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
    void displayMorphemes() const;

    void createDictionary(QList<rti_book*> books);
    void createFrequencyList(QList<rti_book*> books);

private:
    void setupInterface();
    void createMenus();

    // GUI
    DictionaryForm *dictionaryForm;
    LibraryForm *libraryForm;
    QTabWidget *tabWidget;
    QMenu *fileMenu;
    QAction *importLibraryAction;
    QAction *exportLibraryAction;
    QAction *importMasterDictionaryAction;
    QAction *exportMasterDictionaryAction;
    QAction *quitAction;
    QMenu *viewMenu;
    QAction *displayMorphemesAction;
};

#endif // MAINWINDOW_H
