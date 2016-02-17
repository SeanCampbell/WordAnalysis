#include <QApplication>
#include "gui/bookform.h"
#include "rti/rti_book.h"
#include "rti/rti_book_sptr.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rti_book book("First In Line", "FIL Author", rti_book::G1, "first-in-line.txt");

    BookForm form(&book, true);
    form.show();

    return app.exec();
}
