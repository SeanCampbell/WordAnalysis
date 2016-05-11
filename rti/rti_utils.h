//:
// \file
// \author Sean Campbell
// \date   March 2016
// \modified-by Brandon Gratta - April 2016

#ifndef RTI_UTIL
#define RTI_UTIL

#include <vcl_string.h>
#include <emulation/vcl_pair.h>
#include "rti_literature.h"
#include "rti_dictionary.h"
#include "rti_word_frequency_list.h"

namespace rti_utils
{
    vcl_string join(vcl_vector<vcl_string> v, vcl_string delimiter);
    vcl_string trim(const vcl_string& str);
    bool import_cmu_dictionary(vcl_string cmu_filename, vcl_vector<vcl_pair<vcl_string, vcl_string> >& arpabets);
    bool find_arpabet(vcl_string spelling, const vcl_vector<vcl_pair<vcl_string, vcl_string> >& cmu_arpabets, vcl_string& arpabet);
    rti_dictionary *build_dictionary(rti_literature *literature, rti_dictionary *old_dict,
                                     vcl_vector<vcl_pair<vcl_string, vcl_string> > cmu_arpabets, bool *up_to_date);

    rti_word_frequency_list *generate_word_frequency_list_from_literature(rti_literature *literature, double frequencyThreshold);

    vcl_vector<vcl_string> get_difference(vcl_vector<vcl_string> l1, vcl_vector<vcl_string> l2);
    vcl_vector<vcl_string> get_intersection(vcl_vector<vcl_string> l1, vcl_vector<vcl_string> l2);
}

#endif // RTI_UTIL

