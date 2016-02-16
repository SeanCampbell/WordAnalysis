//:
// \file
// \author Charlene Tsai
// \date June 03 2015
// \verbatim
//   executable to annotate a test 
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
  //  Build arguments
  vul_arg<char *> test ( "-file", "The name for the existing xml file to add more questions." );
  // Parse arguments and make sure the transformation files are set.
  vul_arg_parse( argc, argv);  

  int count;
  vcl_string filename;
  rti_examination_sptr exam_ptr;
  if (test.set()) {
    exam_ptr = new rti_examination();
    exam_ptr->read_xml(test());
    filename = test();
    count = exam_ptr->size()+1;
  }
  else {
    vcl_string title;
    vcl_cout<<"Examination ID, e.g. NY-4-2006 (for NY 4th grade ELA in 2006): ";
    vcl_getline(vcl_cin,title);
    exam_ptr = new rti_examination(title);
    filename = title+vcl_string(".xml");
    count = 1;
  }
  bool quit = false;
  while (!quit) {
    rti_question_sptr q_ptr;
    vcl_string q_type;
    Q_TYPE type;
    vcl_cout<<"Information for Question "<<count<<vcl_endl;
    vcl_cout<<"Type (R/LW/RW): ";
    vcl_getline(vcl_cin,q_type);
    vul_string_upcase(q_type);
    if (q_type == vcl_string("R")) type = R;
    else if (q_type == vcl_string("LW")) type = LW;
    else type = RW;
    int std;
    vcl_cout<<"Standard : ";
    vcl_cin>>std; 
    vcl_cin.ignore();
    vcl_string question;
    vcl_cout<<"Question : ";
    vcl_getline(vcl_cin,question);    
    //vcl_string evidence;
    //vcl_cout<<"Evidence : ";
    //vcl_getline(vcl_cin,evidence);

    if (type != R) { //short answer question
      int pts;
      vcl_cout<<"Points : ";
      vcl_cin>>pts; 
      vcl_cin.ignore();
      q_ptr = new rti_question(type, question, std, pts);
    }
    else { //multiple-choice question
      char ans;
      vcl_cout<<"Answer key: "; //ABCD,FGHJ
      vcl_cin>>ans;      
      vcl_cin.ignore();
      q_ptr = new rti_question_multiple_choice(type, question, std, ans);
      rti_question_multiple_choice* mc_ptr = dynamic_cast<rti_question_multiple_choice*>(q_ptr.as_pointer());
      assert(mc_ptr);
      if (mc_ptr->answer() < 'E') {
        vcl_string text;
        vcl_cout<<"Text for choice A: ";
        vcl_getline(vcl_cin, text);
        mc_ptr->add_choice('A',text);
        vcl_cout<<"Text for choice B: ";
        vcl_getline(vcl_cin, text);
        mc_ptr->add_choice('B',text);
        vcl_cout<<"Text for choice C: ";
        vcl_getline(vcl_cin, text);
        mc_ptr->add_choice('C',text);
        vcl_cout<<"Text for choice D: ";
        vcl_getline(vcl_cin, text);
        mc_ptr->add_choice('D',text);
      }
      else {
        vcl_string text;
        vcl_cout<<"Text for choice F: ";
        vcl_getline(vcl_cin, text);
        mc_ptr->add_choice('F',text);
        vcl_cout<<"Text for choice G: ";
        vcl_getline(vcl_cin, text);
        mc_ptr->add_choice('G',text);
        vcl_cout<<"Text for choice H: ";
        vcl_getline(vcl_cin, text);
        mc_ptr->add_choice('H',text);
        vcl_cout<<"Text for choice J: ";
        vcl_getline(vcl_cin, text);
        mc_ptr->add_choice('J',text);
      }
    }
    exam_ptr->add_question(q_ptr);

    count++;
    vcl_string choice;
    vcl_cout<<"Add another question? (y/n) ";
    vcl_getline(vcl_cin,choice);
    if (choice=="y") quit = false;
    else quit = true;

    exam_ptr->write_xml(filename);
  }
 
  return 0;
}


