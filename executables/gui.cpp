#include <QApplication>
#include "gui/bookform.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    BookForm form;
    form.show();

    return app.exec();
}
