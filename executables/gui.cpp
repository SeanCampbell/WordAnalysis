#include <QApplication>
#include "gui/bookform.h"
#include "gui/dictionaryform.h"
#include "rti/rti_book.h"
#include "rti/rti_book_sptr.h"
#include "rti/rti_dictionary.h"
#include "rti/rti_dictionary_sptr.h"
#include "rti/rti_word.h"


#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //rti_book book("First In Line", "FIL Author", rti_book::G1, "first-in-line.txt");
    //BookForm form(&book, true);
    //form.show();

    rti_dictionary *dictionary = new rti_dictionary();
    int pos;
    if (!dictionary->find(vcl_string("dictionary"), pos)) dictionary->insert(new rti_word("dictionary", 20, "D IH1 K SH AH0 N EH2 R IY0", "dictionary", false), pos);
    if (!dictionary->find(vcl_string("apple"), pos)) dictionary->insert(new rti_word("apple", 10, "AE1 P AH0 L", "apple", false), pos);
    if (!dictionary->find(vcl_string("bear"), pos)) dictionary->insert(new rti_word("bear", 15, "B EH1 R", "bear", false), pos);
    if (!dictionary->find(vcl_string("cherry"), pos)) dictionary->insert(new rti_word("cherry", 15, "CH EH1 R IY0", "cherry", false), pos);
    if (!dictionary->find(vcl_string("baby"), pos)) dictionary->insert(new rti_word("baby", 15, "B EY1 B IY0", "baby", false), pos);
    if (!dictionary->find(vcl_string("error"), pos))  dictionary->insert(new rti_word("error", 15, "EH1 R ER0", "error", false), pos);
    if (!dictionary->find(vcl_string("dictionary"), pos)) dictionary->insert(new rti_word("bear", 15, "B EH1 R", "bear", false), pos);
    DictionaryForm dictForm(dictionary);
    dictForm.show();

    return app.exec();
}
