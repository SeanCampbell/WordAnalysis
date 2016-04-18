#include <testlib/testlib_test.h>

#include <vcl_iostream.h>
#include <rti/rti_word.h>
#include <rti/rti_word_sptr.h>
#include <rti/rti_dictionary.h>
#include <rti/rti_dictionary_sptr.h>

namespace
{
  static void test_dic_find()
  {
    rti_dictionary_sptr dictionary = new rti_dictionary();
    int pos;
    if (!dictionary->find(vcl_string("dictionary"), pos)) dictionary->insert(new rti_word("dictionary", 20, "D IH1 K SH AH0 N EH2 R IY0", "dictionary", false), pos);
    if (!dictionary->find(vcl_string("apple"), pos)) dictionary->insert(new rti_word("apple", 10, "AE1 P AH0 L", "apple", false), pos);
    if (!dictionary->find(vcl_string("bear"), pos)) dictionary->insert(new rti_word("bear", 15, "B EH1 R", "bear", false), pos);
    if (!dictionary->find(vcl_string("cherry"), pos)) dictionary->insert(new rti_word("cherry", 15, "CH EH1 R IY0", "cherry", false), pos);
    if (!dictionary->find(vcl_string("baby"), pos)) dictionary->insert(new rti_word("baby", 15, "B EY1 B IY0", "baby", false), pos);
    if (!dictionary->find(vcl_string("error"), pos))  dictionary->insert(new rti_word("error", 15, "EH1 R ER0", "error", false), pos);
    if (!dictionary->find(vcl_string("dictionary"), pos)) dictionary->insert(new rti_word("bear", 15, "B EH1 R", "bear", false), pos);

    int index;
    TEST("Test find function - non-existing \n", !dictionary->find("boss",index) && index == 3, true);
    TEST("Test find function - existing\n", dictionary->find("bear",index) && index == 2, true);
    TEST("Test find function - first\n", dictionary->find("apple",index) && index == 0, true);
    TEST("Test find function - before first\n", !dictionary->find("ale",index) && index == 0, true);
    TEST("Test find function - last\n", dictionary->find("error",index) && index == 5, true);
    TEST("Test find function - after last\n", !dictionary->find("glow",index) && index == 6, true);
  }

  static void test_phonotactic()
  {
    rti_dictionary_sptr dictionary = new rti_dictionary();
    int pos;
    if (!dictionary->find(vcl_string("song"), pos)) dictionary->insert(new rti_word("song", 20, "S AO1 NG", "song", false ), pos);
    if (!dictionary->find(vcl_string("son"), pos)) dictionary->insert(new rti_word("son", 10, "S AH1 N", "son", false), pos);
    if (!dictionary->find(vcl_string("sin"), pos)) dictionary->insert(new rti_word("sin", 15, "S IH1 N", "sin" , false), pos);
    if (!dictionary->find(vcl_string("sit"), pos)) dictionary->insert(new rti_word("sit", 20, "S IH1 T", "sit", false), pos);
    if (!dictionary->find(vcl_string("site"), pos)) dictionary->insert(new rti_word("site", 10, "S AY1 T", "site", false), pos);
    if (!dictionary->find(vcl_string("sing"), pos)) dictionary->insert(new rti_word("sing", 15, "S IH1 NG", "sing", false ), pos);
    if (!dictionary->find(vcl_string("in"), pos)) dictionary->insert(new rti_word("in", 100,  "IH0 N", "bin", false), pos);
    if (!dictionary->find(vcl_string("sits"), pos)) dictionary->insert(new rti_word("sits", 42, "S IH1 T S", "sit PLU", false ), pos);
    if (!dictionary->find(vcl_string("long"), pos)) dictionary->insert(new rti_word("long", 30, "L AO1 NG", "long", false ), pos);
    if (!dictionary->find(vcl_string("along"), pos)) dictionary->insert(new rti_word("along", 120, "AH0 L AO1 NG", "along" , false), pos);
    if (!dictionary->find(vcl_string("blink"), pos)) dictionary->insert(new rti_word("blink", 120, "B L IH1 NG K", "blink", false ), pos);
    if (!dictionary->find(vcl_string("bink"), pos)) dictionary->insert(new rti_word("bink", 120, "B IH1 NG K", "bink" , false ), pos);

    TEST("Test is_up_to_date function\n", dictionary->valid(), true);
    dictionary->compute_PSegAves();
	  dictionary->compute_BiphAves();
    dictionary->compute_neighbors();

    // check if "long" is the neighbor of "along"
    vcl_vector<vcl_string> neighbors = (*dictionary)[0]->neighbors();
    bool found = false;
    for (unsigned int i = 0; i<neighbors.size(); i++) 
      if (neighbors[i].compare("long") == 0) found = true; 
    TEST("Test compute_neighbors function: deletion \n", found, true);

    // check if "blink" is the neighbor of "bink"
    neighbors = (*dictionary)[1]->neighbors();
    found = false;
    for (unsigned int i = 0; i<neighbors.size(); i++) 
      if (neighbors[i].compare("blink") == 0) found = true; 
    TEST("Test compute_neighbors function: addition \n", found, true);

    // check if "song" is the neighbor of "long"
    neighbors = (*dictionary)[4]->neighbors();
    found = false;
    for (unsigned int i = 0; i<neighbors.size(); i++) 
      if (neighbors[i].compare("song") == 0) found = true; 
    TEST("Test compute_neighbors function: replacement \n", found, true);

    dictionary->write_xml("dictionary.xml", true);
    dictionary->read_xml("dictionary.xml");
    dictionary->write_xml("dictionary2.xml", false);

    rti_dictionary_sptr dic2 = new rti_dictionary();
    TEST("Test dictionary xml write: \n",dictionary->write_xml("dictionary.xml", true)==XML_SUCCESS, true);
    TEST("Test dictionary xml read: \n",dic2->read_xml("dictionary.xml")==XML_SUCCESS, true);
    TEST("Test dictionary xml write: \n",dic2->write_xml("dictionary2.xml", false)==XML_SUCCESS, true);
    TEST("Test dictionary Get Word:\n",  dictionary->get("sing")->spelling()=="sing", true);
    TEST("Test dictionary Get Word:\n",  dictionary->get("read")==NULL, true);    
  }
}
static void test_dictionary()
{
  test_dic_find();
  test_phonotactic();
}

TESTMAIN(test_dictionary);
