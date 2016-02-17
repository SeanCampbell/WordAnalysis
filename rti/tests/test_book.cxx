#include <testlib/testlib_test.h>

#include <vcl_iostream.h>
#include <rti/rti_book.h>
#include <rti/rti_book_sptr.h>
#include <emulation/vcl_pair.h>
#include <rti/rti_literature.h>
#include <rti/rti_literature_sptr.h>

namespace
{

  static void test_all()
  {
    rti_book_sptr book = new rti_book("First Book","Charlene Tsai", PK, "input_file.txt");
    rti_literature_sptr lit= new rti_literature();
    int index;
    if (!lit->find(book->title(),index)) lit->insert(book, index);

    rti_book_sptr book2 = new rti_book("cat","Marlene Zakierski", PK, "input_file.txt");
    if (!lit->find(book2->title(),index)) lit->insert(book2, index);

    TEST("Test literature Insertion: \n", (*lit)[0]->title()=="cat", true);
    TEST("Test literature Insertion: \n", (*lit)[1]->title()=="First Book", true);
    vcl_cout<<"number of books = "<<lit->size()<<vcl_endl;
    TEST("Test literature xml write: \n", lit->write_xml("literature.xml")==XML_SUCCESS, true); 
    rti_literature_sptr lit2= new rti_literature();
    TEST("Test literature xml read: \n", lit2->read_xml("literature.xml")==XML_SUCCESS, true);
    TEST("Test literature xml write: \n", lit2->write_xml("literature.xml")==XML_SUCCESS, true);
  }

}
static void test_book()
{
  test_all();
}

TESTMAIN(test_book);
