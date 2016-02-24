#ifndef RTI_UTIL
#define RTI_UTIL

#include <vector>
#include <sstream>

std::string join(std::vector<std::string> v, std::string delimiter)
{
    std::stringstream ss;
    for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it != v.begin())
            ss << delimiter;
        ss << *it;
    }
    return ss.str();
}

#endif // RTI_UTIL

