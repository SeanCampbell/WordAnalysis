//:
// \file
// \author Charlene Tsai
// \date June 03 2015
// \verbatim
//   generate the test with the essays and either empty questions or imported from an exisiting test.
// \endverbatim
// 


#include <vcl_vector.h>
#include <vcl_algorithm.h>
#include <vcl_string.h>
#include <vcl_sstream.h>
#include <vcl_fstream.h>
#include <vcl_cassert.h>

#include <vul/vul_arg.h>
#include <vul/vul_string.h>
#include <vul/vul_reg_exp.h>
#include <vul/vul_file.h>

#include <rti/rti_question_multiple_choice.h>
#include <rti/rti_examination_sptr.h>
#include <rti/rti_examination.h>
#include <rti/rti_examination_complete.h>

int
main( int argc, char** argv )
{
  //  Build arguments
  vul_arg<char *> old ("-file", "The existing test without the essays. Questions will be imported directly from the test." );

  vul_arg_parse( argc, argv);
  vcl_string filename;
  rti_examination_sptr exam_ptr;

  //read in the questions from the existing file or generate the empty questions
  if (old.set()) { 
    filename = vcl_string("complete_")+vul_file::strip_directory(old());
    rti_examination_sptr old_exam_ptr = new rti_examination();
    old_exam_ptr->read_xml(old());
    exam_ptr = new rti_examination_complete(old_exam_ptr->id());
    unsigned int size = old_exam_ptr->size();
    for (unsigned int i = 0; i<size; i++) {
      exam_ptr->add_question((*old_exam_ptr)[i]);
    }
  }
  else {
    vcl_string fghj;
    vcl_string title;
    vcl_cout<<"Examination ID, e.g. NY-4-2006 (for NY 4th grade ELA in 2006): ";
    vcl_getline(vcl_cin,title);
    exam_ptr = new rti_examination_complete(title);
    filename = title+vcl_string(".xml");
    int total;
    vcl_cout<<"Total number of questions: ";
    vcl_cin>>total;
    vcl_cout<<"fghj choices? (y/n) ";
    vcl_cin>>fghj;

    int count = 0;
    bool quit = false;
    while (count<total) {
      rti_question_sptr q_ptr;
      vcl_string q_type;
      Q_TYPE type;
      int std = 0;
      if (count<28) {
        type = R;
        std = 0;
      }
      else if (count<31) {
        type = LW;
        std = 2;
      }
      else {
        type = RW;
        std = 3;
      }

      vcl_string question = "XXX";

      if (type != R) { //short answer question
        int pts = 4;
        q_ptr = new rti_question(type, question, std, pts);
      }
      else { //multiple-choice question
        q_ptr = new rti_question_multiple_choice(type, question, std, 'X');
        rti_question_multiple_choice* mc_ptr = dynamic_cast<rti_question_multiple_choice*>(q_ptr.as_pointer());
        assert(mc_ptr);
        if (fghj !=  "y" || count%2 == 0) {
          mc_ptr->add_choice('A',"XXX");
          mc_ptr->add_choice('B',"XXX");
          mc_ptr->add_choice('C',"XXX");
          mc_ptr->add_choice('D',"XXX");
        }
        else {
          vcl_string text;
          mc_ptr->add_choice('F',"XXX");
          mc_ptr->add_choice('G',"XXX");
          mc_ptr->add_choice('H',"XXX");
          mc_ptr->add_choice('J',"XXX");
        }
      }
      exam_ptr->add_question(q_ptr);

      count++;
    }

  }

  // Add the essays
  int q_count, total_q_count = 0;
  int e_count;
  vcl_cout<<"Total number of essays: ";
  vcl_cin>>e_count;
  vcl_cin.ignore();
  for (int i = 0; i<e_count; i++) {
    vcl_cout<<"***** Input for essay "<<i+1<<" ***********"<<vcl_endl; 
    vcl_string isbn, title, author, book_file;
    vcl_string age;
    rti_book::AGE age_range;
    vcl_cout<<"Essay ISBN: ";
    vcl_getline(vcl_cin,isbn);
    vcl_cout<<"Essay title: ";
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

    vcl_cout<<"Essay filename: ";
    vcl_getline(vcl_cin,book_file);  
    vcl_ifstream file;
    file.open(book_file);  //make sure the book exist
    while (!file) {
      vcl_cout<<"ERROR: The file not found"<<vcl_endl;
      vcl_cout<<"Essay filename: ";
      vcl_getline(vcl_cin,book_file);  
      file.open(book_file);
    } 
   
    rti_book_sptr essay = new rti_book(isbn, title, author, age_range, book_file);
    vcl_cout<<"Number of questions: ";
    vcl_cin>>q_count;
    vcl_cin.ignore();
    rti_examination_complete* ec_ptr = dynamic_cast<rti_examination_complete*>(exam_ptr.as_pointer());
    assert(ec_ptr);
    ec_ptr->add_essay(essay, q_count);
    total_q_count += q_count;
  }

  if (total_q_count != exam_ptr->size()) 
    vcl_cout<<"ERROR: Numbers do not add up!!!"<<vcl_endl;

  exam_ptr->write_xml(filename);

  return 0;
} 


