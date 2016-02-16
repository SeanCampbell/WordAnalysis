//:
// \file
// \author Charlene Tsai
// \date Aug 28 2014
// \verbatim
//   Executable to generate the transcription file for the phonotactic calculatpr . 
// \endverbatim
//
//  The usage is
//
//    generate_transcription_file input_text_file 
//
//  where
//    input_text_file    The file containing all the words in book or piece of text to be transcribed. The output has the same name as the input file, but with .csv as the extension


#include <vcl_vector.h>
#include <vcl_algorithm.h>
#include <vcl_string.h>
#include <vcl_fstream.h>

#include <vul/vul_arg.h>
#include <vul/vul_string.h>
#include <vul/vul_reg_exp.h>


int
main( int argc, char** argv )
{
  //  Build arguments
  vul_arg<char *> input_file ( 0, " The file containing the text to be transcribed. The output is in .csv format" );
  vul_arg<char *> db_file ( "-db", " The file containing all the entries in the database to automatically complete the known entries in the database (to be implemented)." );
  


  //  Parse arguments and make sure the transformation files are set.
  vul_arg_parse( argc, argv);
  vcl_vector< vcl_string > in_words;
  in_words.reserve(400);
  vul_reg_exp re("([a-zA-Z'_\\-]+)");

  //strip out only words, convert to low cases, and sort
  vcl_ifstream in_file(input_file());
  vcl_string word;
  while (!in_file.eof()) {
    in_file>>word;
	if (re.find(word))
		in_words.push_back(vul_string_downcase(re.match(1)));
  }
  vcl_sort(in_words.begin(),in_words.end());

  //Now do the count and output the result to the output file
  vcl_ofstream output(input_file()+vcl_string(".csv")); //to be changed later
  vcl_cout<<"The result is written to "<<input_file()+vcl_string(".csv")<<vcl_endl;

  output<<"Word ,\t Arpabet ,\t Morpheme ,\t Core/Fringe ,\t Content/Function ,\t Word Count "<<vcl_endl;
  word = in_words[0];
  int count = 1;
  for (int i = 1; i<in_words.size(); i++) {
	  if (word == in_words[i]) count ++;
	  else {
		  output<<word<<",\t ,\t ,\t ,\t ,\t"<<count<<vcl_endl;
		  word = in_words[i];
		  count = 1;
	  }
  }
  output<<word<<",\t ,\t ,\t ,\t ,\t"<<count<<vcl_endl;  //for the last word
}


