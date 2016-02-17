//:
// \file
// \author Charlene Tsai
// \date May 04 2012
// \verbatim
//   Executable to generate a set of mask images, each being a white image of the same size as the original image. 
// \endverbatim

//: Executable to generate a set of mask images by taking every pixel as in the mask.  
//
//  The usage is
//
//    generate_simple_mask_images filename_mask 
//
//  where
//    filename_mask        Images with the given mask/pattern in the filename will have mask images ending with the given suffix generated.
//
//  Optional arguments:
//    -input_dir           The directory where the original images are found. Default is "./"
//    -output_dir          The directory where the mask images should be dumped. Default is "./" 
//    -mask_suffix         The suffix to be appended to the original image name. Default is "_mask.png"

#include <vcl_vector.h>
#include <vcl_string.h>

#include <vul/vul_arg.h>
#include <vul/vul_file.h>
#include <vul/vul_reg_exp.h>
#include <vul/vul_file_iterator.h>

#include <vil/vil_load.h>
#include <vil/vil_save.h>
#include <vil/vil_rgb.h>
#include <vil/vil_image_view.h>

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
  vul_arg<char *> filename_mask ( 0, "Images with the given mask/pattern (regular expression) in the filename will have mask images ending with the given suffix generated. The default suffix is _mask.png" );
  vul_arg<char *> input_dir ("-input_dir", "The directory where the original images are found. Default is ./ ", "./");
  vul_arg<char *> output_dir ("-output_dir", "The directory where the mask images should be dumped. Default is ./", "./");
  vul_arg<char *> suffix ("-mask_suffix", "The suffix to be appended to the original image name. Default is _mask.png", "_mask.png");

  //  Parse arguments and make sure the transformation files are set.
  vul_arg_parse( argc, argv);

  // STEP 1: read in images
  vcl_vector< vcl_string > image_files;
  vcl_vector< vil_image_resource_sptr > images;
  vcl_vector<vil_image_view<vxl_byte> > masks;

  // make sure the directory paths have a ending "/"
  vul_reg_exp end_slash( ".*[/\\]$" );
  vcl_string input_path = input_dir();
  if ( !end_slash.find( input_dir() ) ) 
    input_path = input_path + vcl_string("/");

  // Get all the image file names
  vcl_string pattern = input_path + vcl_string(filename_mask());
  for (vul_file_iterator fn=pattern; fn; ++fn) {
    vcl_string file_name = fn();
    replace('\\', '/', file_name);
    image_files.push_back(file_name);
    images.push_back( vil_load_image_resource(file_name.c_str()) );
  }
  
  
  // Step2: for each image, get the image dimensions, create a new
  // image, fill the image with 255, and write out the mask image
  vcl_string output_path = output_dir();
  if ( !end_slash.find( input_dir() ) ) 
    output_path = output_path + vcl_string("/");
  
  for (unsigned int i=0; i<images.size(); i++) {
    vcl_string file_name = vul_file::strip_directory(image_files[i]);
    file_name = output_path + file_name + suffix();
    int ni = images[i]->ni();
    int nj = images[i]->nj();
    vil_image_view<vxl_byte> mask_image;
    mask_image.set_size(ni,nj,1);
    mask_image.fill(vxl_byte(255));
    vil_save(mask_image, file_name.c_str());
  }
}


