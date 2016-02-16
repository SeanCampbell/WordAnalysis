//:
// \file
// \author Charlene Tsai
// \date June 2015
// \verbatim
//   executable to record the results of class assessment
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

#include <rti/rti_assessment_sptr.h>
#include <rti/rti_assessment.h>

int
main( int argc, char** argv )
{
  //  Build arguments
  //vul_arg<char *> file ( "-file", "The name for the existing xml file to add more student records." );
 
  // Parse arguments and make sure the transformation files are set.
  //vul_arg_parse( argc, argv);
  int count;
  int q_count;
  vcl_string class_id, test_id, month, filename;

  rti_assessment_sptr assess_ptr;
  vcl_cout<<"Class ID: ";
  vcl_getline(vcl_cin,class_id);
  vcl_cout<<"Examination ID: ";
  vcl_getline(vcl_cin,test_id);
  vcl_cout<<"Month: ";
  vcl_getline(vcl_cin,month);
  filename = class_id+vcl_string("+")+test_id+vcl_string("+")+month+vcl_string(".xml");
  assess_ptr = new rti_assessment(class_id, test_id, month);  
  vcl_cout<<"class size: ";
  vcl_cin>>count;
  vcl_cout<<"Number of questions: ";
  vcl_cin>>q_count;

  for (int i = 0; i<count; i++) {
    vcl_string student_id, answers;

    //convert the number to a 2 digit stringcd 
    vcl_stringstream convert;
    if (i+1 < 10) {
      convert << 0;
      convert << i+1;
    }
    else convert << i+1;
    student_id = convert.str();

    /*
    vcl_cout<<"Student ID: ";
    vcl_cin>>student_id;
    vcl_cin.ignore();
    */
    //vcl_cout<<"Answers/points: ";
    //vcl_cin>>answers;
    answers = "0";
    for (int j = 0; j<q_count-1; j++ )
      answers = answers+vcl_string("0");

    assess_ptr->add_record(student_id, answers);
  }

  assess_ptr->write_xml(filename);
  return 0;
}


