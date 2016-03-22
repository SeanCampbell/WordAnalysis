//:
// \file
// \author Charlene Tsai
// \date  June 2015
// \verbatim
//   Build the dictionary of words in the literature.
// \endverbatim
//
//  The usage is
//
//    build_dictionary -cmu cmu-arpabet -lit literature.xml -old old_dictionary
//
//  where:
//    -cmu cmu-arpabet     The text file from the cmu website
//    -lit literature      The xml file containing all the books in the literature to provide the frequency information
//    -old old_dictionary  The xml file of the old dictionary where information can be imported.
//
//  Action:
//    1. Generate the xml file for the dictionary
//    2. If ?old is set, entries can be copied from the old dictionary

#include <vcl_fstream.h>

#include <vul/vul_arg.h>

#include <rti/rti_literature.h>
#include <rti/rti_literature_sptr.h>
#include <rti/rti_dictionary.h>
#include <rti/rti_dictionary_sptr.h>
#include <rti/rti_utils.h>

int
main( int argc, char** argv )
{
  //  Build arguments
  vul_arg<char *> cmu ("-cmu", "The arpabet file from the CMU website: http://svn.code.sf.net/p/cmusphinx/code/trunk/cmudict/cmudict-0.7b.txt" );
  vul_arg<char *> lit ( "-lit", "The xml file containing all the books in the literature to provide the frequency information" );
  vul_arg<char *> old ( "-old", "The old dictionary where the information can be imported from" );

  //  Parse arguments and make sure the transformation files are set.
  vul_arg_parse( argc, argv);
  vcl_string filename;
  rti_dictionary_sptr old_dict = NULL;
  rti_literature_sptr literature = new rti_literature();
  vcl_vector<vcl_pair<vcl_string, vcl_string> > cmu_arpabets;

  if (!cmu.set()) {
    vcl_cout<<"Missing the arpabet file from the CMU website: http://svn.code.sf.net/p/cmusphinx/code/trunk/cmudict/cmudict-0.7b"<<vcl_endl;
    return 1;
  }
  else {
    if (!rti_utils::import_cmu_dictionary(cmu(), cmu_arpabets))
      return 1;
  }
  if (!lit.set()) {
    vcl_cout<<"Miss the xml file containing all the books in the literature to provide the frequency information"<<vcl_endl;
    return 1;
  }
  else literature->read_xml(lit());
  if (old.set()) {
    old_dict = new rti_dictionary();
    old_dict->read_xml(old());
  }

  vcl_cout<<"The xml filename for the NEW dictionary: ";
  vcl_getline(vcl_cin,filename);
  bool up_to_date = true;

  rti_dictionary *dict = rti_utils::build_dictionary(literature.ptr(), old_dict.ptr(), cmu_arpabets, &up_to_date);

  // Write to the XML
  dict->write_xml(filename, up_to_date);

  return 0;
}


