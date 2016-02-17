#include <testlib/testlib_test.h>

#include <vcl_iostream.h>
#include <rti/rti_word.h>
#include <rti/rti_word_sptr.h>
#include <vul/vul_reg_exp.h>
#include <rti/rti_assessment.h>
#include <rti/rti_assessment_sptr.h>

namespace
{
  static void test_xml()
  {
    rti_assessment_sptr assessment = new rti_assessment("C-5-2015","NY-4-2006","Sept" );
    assessment->add_record("S1","AaCHD2B0c");
    assessment->add_record("S2","BcCdD0B0c");

    rti_assessment_sptr assessment2 = new rti_assessment();
    TEST("Test assessment xml write: \n",assessment->write_xml("assessment.xml")==XML_SUCCESS, true);
    TEST("Test assessment xml read: \n",assessment2->read_xml("assessment.xml")==XML_SUCCESS, true);
    TEST("Test assessment xml write: \n",assessment2->write_xml("assessment2.xml")==XML_SUCCESS, true);
  
  }

}

static void test_assessment()
{
  test_xml();

}

TESTMAIN(test_assessment);
