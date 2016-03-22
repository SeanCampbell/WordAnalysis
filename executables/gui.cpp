#include <QApplication>
#include "gui/bookform.h"
#include "gui/dictionaryform.h"
#include "gui/libraryform.h"
#include "gui/mainwindow.h"
#include "rti/rti_book.h"
#include "rti/rti_book_sptr.h"
#include "rti/rti_dictionary.h"
#include "rti/rti_dictionary_sptr.h"
#include "rti/rti_literature.h"
#include "rti/rti_literature_sptr.h"
#include "rti/rti_word.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //rti_book book("First In Line", "FIL Author", rti_book::G1, "first-in-line.txt");
    //BookForm form(&book, true);
    //form.show();


    rti_dictionary *d1 = new rti_dictionary;
    int pos;
    if (!d1->find(vcl_string("dictionary"), pos)) d1->insert(new rti_word("dictionary", 20, "D IH1 K SH AH0 N EH2 R IY0", "dictionary", false), pos);
    if (!d1->find(vcl_string("apple"), pos)) d1->insert(new rti_word("apple", 10, "AE1 P AH0 L", "apple", false), pos);
    if (!d1->find(vcl_string("bear"), pos)) d1->insert(new rti_word("bear", 15, "B EH1 R", "bear", false), pos);
    if (!d1->find(vcl_string("cherry"), pos)) d1->insert(new rti_word("cherry", 15, "CH EH1 R IY0", "cherry", false), pos);
    if (!d1->find(vcl_string("baby"), pos)) d1->insert(new rti_word("baby", 15, "B EY1 B IY0", "baby", false), pos);
    if (!d1->find(vcl_string("error"), pos))  d1->insert(new rti_word("error", 15, "EH1 R ER0", "error", false), pos);
    if (!d1->find(vcl_string("dictionary"), pos)) d1->insert(new rti_word("bear", 15, "B EH1 R", "bear", false), pos);

    rti_dictionary *d2 = new rti_dictionary;
    if (!d2->find(vcl_string("song"), pos)) d2->insert(new rti_word("song", 20, "S AO1 NG", "song", false ), pos);
    if (!d2->find(vcl_string("son"), pos)) d2->insert(new rti_word("son", 10, "S AH1 N", "son", false), pos);
    if (!d2->find(vcl_string("sin"), pos)) d2->insert(new rti_word("sin", 15, "S IH1 N", "sin" , false), pos);
    if (!d2->find(vcl_string("sit"), pos)) d2->insert(new rti_word("sit", 20, "S IH1 T", "sit", false), pos);
    if (!d2->find(vcl_string("site"), pos)) d2->insert(new rti_word("site", 10, "S AY1 T", "site", false), pos);
    if (!d2->find(vcl_string("sing"), pos)) d2->insert(new rti_word("sing", 15, "S IH1 NG", "sing", false ), pos);
    if (!d2->find(vcl_string("in"), pos)) d2->insert(new rti_word("in", 100,  "IH0 N", "bin", false), pos);
    if (!d2->find(vcl_string("sits"), pos)) d2->insert(new rti_word("sits", 42, "S IH1 T S", "sit PLU", false ), pos);
    if (!d2->find(vcl_string("long"), pos)) d2->insert(new rti_word("long", 30, "L AO1 NG", "long", false ), pos);
    if (!d2->find(vcl_string("along"), pos)) d2->insert(new rti_word("along", 120, "AH0 L AO1 NG", "along" , false), pos);
    if (!d2->find(vcl_string("blink"), pos)) d2->insert(new rti_word("blink", 120, "B L IH1 NG K", "blink", false ), pos);
    if (!d2->find(vcl_string("bink"), pos)) d2->insert(new rti_word("bink", 120, "B IH1 NG K", "bink" , false ), pos);


    QMap<QString, rti_dictionary *> dMap;
    //dMap.insert("Dictionary 1", d1);
    dMap.insert("Dictionary 2", d2);
    DictionaryForm dictForm;//(dMap);
    dictForm.addDictionary("Name", d1);
    //dictForm.show();

/*
    rti_book *book = new rti_book("012-3456789012", "First Book","Charlene Tsai", rti_book::PK, "input_file.txt");
    rti_literature *lit = new rti_literature();
    int index;
    if (!lit->find(book->title(),index)) lit->insert(book, index);
    rti_book *book2 = new rti_book("210-9876543210", "cat","Marlene Zakierski", rti_book::PK, "input_file.txt");
    if (!lit->find(book2->title(),index)) lit->insert(book2, index);
    LibraryForm libForm(lit);
    libForm.show();
*/
    MainWindow mainWin;
    mainWin.show();

    return app.exec();
}
