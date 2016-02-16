//:
// \file
// \author Charlene Tsai
// \date June 03 2015
// \verbatim
//   executable to add a new field to the test 
// \endverbatim
//
//  The usage is
//
//    add_test_field 


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
  vul_arg<char *> test ( "-file", "The name for the existing xml file to add extra field." );
  // Parse arguments and make sure the transformation files are set.
  vul_arg_parse( argc, argv);  

  vcl_string filename;
  rti_examination_sptr exam_ptr;
  if (test.set()) {
    exam_ptr = new rti_examination();
    exam_ptr->read_xml(test());
    exam_ptr->write_xml(test());
  }
 
  return 0;
}


