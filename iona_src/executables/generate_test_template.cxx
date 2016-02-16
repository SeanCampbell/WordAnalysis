//:
// \file
// \author Charlene Tsai
// \date June 03 2015
// \verbatim
//   generate test with empty xml records
// \endverbatim
//
//  The usage is
//
//    annotate_test 


#include <vcl_vector.h>
#include <vcl_algorithm.h>
#include <vcl_string.h>
#include <vcl_sstream.h>
#include <vcl_fstream.h>
#include <vcl_cassert.h>

#include <vul/vul_arg.h>
#include <vul/vul_string.h>
#include <vul/vul_reg_exp.h>

#include <rti/rti_question_multiple_choice.h>
#include <rti/rti_examination_sptr.h>
#include <rti/rti_examination.h>

int
main( int argc, char** argv )
{
  vcl_string fghj;
  vcl_string filename;
  rti_examination_sptr exam_ptr;
  vcl_string title;
  vcl_cout<<"Examination ID, e.g. NY-4-2006 (for NY 4th grade ELA in 2006): ";
  vcl_getline(vcl_cin,title);
  exam_ptr = new rti_examination(title);
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
  exam_ptr->write_xml(filename);

  return 0;
}


