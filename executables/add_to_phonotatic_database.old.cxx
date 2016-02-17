//:
// \file
// \author Charlene Tsai
// \date Aug 28 2014
// \verbatim
//   Executable to merge two .csv files containing word records . 
// \endverbatim
//
//  The usage is
//
//    generate_transcription_file database new_file 
//
//  where
//    database    containing words in the database. The updated database is written back to the same file with only unique entries
//    new_file    containing words to be merged to the database. 

#include <vcl_vector.h>
#include <vcl_algorithm.h>
#include <vcl_string.h>
#include <vcl_fstream.h>

#include <vul/vul_arg.h>
#include <vul/vul_string.h>
#include <vul/vul_reg_exp.h>

#include <rti/rti_word.h>


// replace instances of 'from' in 's' with 'to'
static unsigned replace(char from, char to, vcl_string &s)
{
  unsigned c = 0;
  for (unsigned i=0; i<s.size(); ++i)
    if (s[i] == from)
    {
      c++;
      s[i] = to;
    }
    return c;
}

int
main( int argc, char** argv )
{
  //  Build arguments
  vul_arg<char *> db_file ( 0, " The database file containing all the entries in the database with comma-delineated fields. The first line is skipped as the heading, and the first 5 fields have to be word, arpabet, morpheme, function/content and core/fringe. The rest of a line is ignored" );
  vul_arg<char *> new_file ( "-db", " The file containing entries to be added to the database. The format is the same as the database" );
  
  //  Parse arguments and make sure the transformation files are set.
  vul_arg_parse( argc, argv);
  vcl_vector<pdt_word_record_sptr> words;
  in_words.reserve(400);
  //vul_reg_exp re("([a-zA-Z\\+\w])");

  //for each line, get the first 6 fields for word, arpabet, morpheme, core/fringe, content/function, word count
  vcl_ifstream in_file(input_file());
  vcl_string word, line;
  in_file.getline(line); //skip the first line since it contains only the heading
  while (!in_file.eof()) {
    in_file.getline(line);
	vcl_cout(line);
  }
}


