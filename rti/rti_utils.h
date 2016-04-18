#ifndef RTI_UTIL
#define RTI_UTIL

#include <vcl_string.h>
#include <emulation/vcl_pair.h>

#include "rti_literature.h"
#include "rti_dictionary.h"
#include "rti_word_frequency_list.h"

namespace rti_utils
{
    std::string join(std::vector<std::string> v, std::string delimiter);
    vcl_string trim(const vcl_string& str);
    bool import_cmu_dictionary(vcl_string cmu_filename, vcl_vector<vcl_pair<vcl_string, vcl_string> >& arpabets);
    bool find_arpabet(vcl_string spelling, const vcl_vector<vcl_pair<vcl_string, vcl_string> >& cmu_arpabets, vcl_string& arpabet);
    rti_dictionary *build_dictionary(rti_literature *literature, rti_dictionary *old_dict,
                                     vcl_vector<vcl_pair<vcl_string, vcl_string> > cmu_arpabets, bool *up_to_date);

    rti_word_frequency_list *generate_word_frequency_list_from_literature(rti_literature *literature, int frequencyThreshold);
}

#endif // RTI_UTIL

