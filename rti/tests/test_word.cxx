#include <testlib/testlib_test.h>

#include <vcl_iostream.h>
#include <rti/rti_word.h>
#include <rti/rti_word_sptr.h>
#include <vul/vul_reg_exp.h>

namespace
{
  static void test_word_calc_syllables()
  {
    rti_word_sptr word = new rti_word("dictionary", 20, "D IH1 K SH AH0 N EH2 R IY0", "dictionary", false );
    TEST("Test calc_syllables function\n", 4==word->syllables(), true);
  }

  static void test_reg_exp()
  {
   //take care of deletion and substritution
   
    rti_word_sptr word = new rti_word("dictionary", 20, "D IH1 K SH AH0 N EH2 R IY0", "dictionary", false );
    vcl_vector<vcl_string> phonemes = word->phonemes();      
    for (unsigned int j = 0; j<phonemes.size(); j++) {
    // produce the regular expression with the given phoneme replace with a * 
      vcl_string reg_exp_str;
      for (unsigned int k = 0; k<phonemes.size(); k++) {
        if (k==j) reg_exp_str = reg_exp_str + vcl_string(".*") ;
        else {
          reg_exp_str = reg_exp_str + phonemes[k];
          if (k!=phonemes.size()-1) reg_exp_str = reg_exp_str+vcl_string(" "); 
        }
      }
      vcl_cout<<"reg_exp "<<j<<" "<<reg_exp_str<<vcl_endl;
      vcl_string test_str1("D IH K SH AH N EH R ");
      vul_reg_exp re(reg_exp_str.c_str());
      if (re.find(test_str1.c_str())) 
        vcl_cout<<"match found"<<vcl_endl;
      else vcl_cout<<"no match found"<<vcl_endl;
    }  
    
    /*
    // take care of insertion
    rti_word_sptr word = new rti_word("dictionary", "D IH1 K SH AH0 N EH2 R IY0", "", false, 20 );
    vcl_vector<vcl_string> phonemes = word->phonemes();      
    // produce the regular expression with the given phoneme replace with a * 
    vcl_string reg_exp_str(".*");
    for (unsigned int k = 0; k<phonemes.size(); k++) {
      reg_exp_str = reg_exp_str + phonemes[k]+vcl_string(".*");
    }
 
      vcl_cout<<"reg_exp "<<reg_exp_str<<vcl_endl;
      vcl_string test_str1("D IH IH K SH AH N EH R IY");
      vul_reg_exp re(reg_exp_str.c_str());
      if (re.find(test_str1.c_str())) 
        vcl_cout<<"match found"<<vcl_endl;
      else vcl_cout<<"no match found"<<vcl_endl;
      */
    /*
    vcl_string reg_exp_str = "D .* K SH AH N EH R IY";
    vcl_string test_str1("D IH K SH AH N EH R IY");
    vul_reg_exp re(reg_exp_str.c_str());
    if (re.find(test_str1.c_str())) 
      vcl_cout<<"match found"<<vcl_endl;
    else vcl_cout<<"no match found"<<vcl_endl;
    */
  }    

}

static void test_word()
{
  test_word_calc_syllables();
  //test_reg_exp();
}

TESTMAIN(test_word);
