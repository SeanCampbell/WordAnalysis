#include <testlib/testlib_test.h>

#include <vcl_iostream.h>
#include <vcl_cassert.h>
#include <rti/rti_examination.h>
#include <rti/rti_examination_sptr.h>
#include <rti/rti_question.h>
#include <rti/rti_question_sptr.h>
#include <rti/rti_question_multiple_choice.h>

namespace
{
  static void test_xml()
  {
    rti_examination_sptr exam = new rti_examination("NY-3-2006");
    rti_question_sptr sa_q = new rti_question(LW, "Give two examples from the story that show Emma likes to garden.", 2, 2);
    rti_question_sptr mc_q = new rti_question_multiple_choice(R,"The chart below shows events from the article." , 1, 'A');

    rti_question_multiple_choice* mc_ptr = dynamic_cast<rti_question_multiple_choice*>(mc_q.as_pointer());
    assert(mc_ptr);

    mc_ptr->add_choice('a', "The robin builds a nest.");
    mc_ptr->add_choice('B', "The robin looks for a tree.");
    mc_ptr->add_choice('c', "The robin feeds the babies.");
    mc_ptr->add_choice('D', "The robin\'s babies hatch.");

    exam->add_question(sa_q);
    exam->add_question(mc_q);

    rti_examination_sptr exam2 = new rti_examination(); 
    TEST("Test examination xml write: \n",exam->write_xml("NY-3-2006.xml")==XML_SUCCESS, true);
    TEST("Test examination xml read: \n",exam2->read_xml("NY-3-2006.xml")==XML_SUCCESS, true);
    TEST("Test examination xml write: \n",exam2->write_xml("NY-3-2006-2.xml")==XML_SUCCESS, true);
  }

  static void test_multiple_choice()
  {
    rti_question_sptr mc_q = new rti_question_multiple_choice(R,"The chart below shows events from the article." , 1, 'A');
    rti_question_multiple_choice* mc_ptr = dynamic_cast<rti_question_multiple_choice*>(mc_q.as_pointer());
    assert(mc_ptr);
    
    mc_ptr->add_choice('a', "The robin builds a nest.");
    mc_ptr->add_choice('B', "The robin looks for a tree.");
    mc_ptr->add_choice('c', "The robin feeds the babies.");
    mc_ptr->add_choice('D', "The robin\'s babies hatch.");

    vcl_string text;
    TEST("Test multiple_choice correct_answer: \n",mc_ptr->correct_answer('a'), true);
    TEST("Test multiple_choice get_choice: \n",mc_ptr->get_choice('d', text) && text == "The robin\'s babies hatch." , true);
  }
}
static void test_examination()
{
  test_xml();
  test_multiple_choice();
}

TESTMAIN(test_examination);
