//:
// \file
// \author Charlene Tsai
// \date June 03 2015
// \verbatim
//   Executable to add a book to the literature. 
// \endverbatim
//
//  The usage is
//
//    expand_literature -lit literature.xml
//
//  where:
//    - lit literature     The xml file containing all the books in the literature
//
//  Action:
//    1. Add the books to the literature


#include <vcl_vector.h>
#include <vcl_algorithm.h>
#include <vcl_string.h>
#include <vcl_sstream.h>
#include <vcl_fstream.h>

#include <vul/vul_arg.h>
#include <vul/vul_string.h>
#include <vul/vul_reg_exp.h>

#include <rti/rti_word.h>
#include <rti/rti_book.h>
#include <rti/rti_book_sptr.h>
#include <rti/rti_literature.h>
#include <rti/rti_literature_sptr.h>

int
main( int argc, char** argv )
{
  //  Build arguments
  vul_arg<char *> lit ( "-file", "The existing xml file containing all the books in the literature." );
 
  // Parse arguments and make sure the transformation files are set.
  vul_arg_parse( argc, argv);
  rti_literature_sptr literature = new rti_literature();
  vcl_string lit_name;
  if (!lit.set()) {
    vcl_cout<<"Provide the name for the NEW literature with extention xml, e.g. literture.xml: "<<vcl_endl;
    vcl_getline(vcl_cin,lit_name);
  }
  else { //read in from the existing literature
    lit_name = lit();
    literature->read_xml(lit());
  }

  bool quit = false;
  vcl_string choice;
  while (!quit) {
    // Get other information about the book
    vcl_string title, author, book_file;
    vcl_string age;
    rti_book::AGE age_range;
    vcl_cout<<"Book title: ";
    vcl_getline(vcl_cin,title);
    vcl_cout<<"First author: ";
    vcl_getline(vcl_cin,author);
    vcl_cout<<"Age range (NS, PK, K, G1, G2, G3, G4): ";
    vcl_getline(vcl_cin,age);
    vul_string_upcase(age);
    if (age == vcl_string("NS")) age_range = rti_book::NS;
    else if  (age == vcl_string("PK")) age_range = rti_book::PK;
    else if (age == vcl_string("K")) age_range = rti_book::K;
    else if (age == vcl_string("G1")) age_range = rti_book::G1;
    else if (age == vcl_string("G2")) age_range = rti_book::G2;
    else if (age == vcl_string("G3")) age_range = rti_book::G3;
    else age_range = rti_book::G4;

    vcl_cout<<"Book filename: ";
    vcl_getline(vcl_cin,book_file);  
    vcl_ifstream file;
    file.open(book_file); //make sure the book exist
    while (!file) {
      vcl_cout<<"ERROR: The file not found"<<vcl_endl;
      vcl_cout<<"Book filename: ";
      vcl_getline(vcl_cin,book_file);  
      file.open(book_file);
    } 

    //Add the book to the literature
    rti_book_sptr book = new rti_book(title, author, age_range, book_file);
    int pos;
    if (!literature->find(title, pos)) literature->insert(book, pos); 
    else {
      vcl_cout<<"\""<<(*literature)[pos]->title()<<"\" will be replaced"<<vcl_endl;
      literature->replace(book, pos);
    }

    vcl_cout<<"Add another book? (y/n) ";
    vcl_getline(vcl_cin,choice);
    if (choice=="y") quit = false;
    else quit = true;  

    literature->write_xml(lit_name);
  }

  return 0;
}


