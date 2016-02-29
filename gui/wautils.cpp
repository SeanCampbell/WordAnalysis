#include "wautils.h"

namespace wa_utils
{
    QMap<rti_book::AGE, QString> gradeLevelMap()
    {
        QMap<rti_book::AGE, QString> glMap;
        glMap.insert(rti_book::NS, "Nursery");
        glMap.insert(rti_book::PK, "Pre-K");
        glMap.insert(rti_book::K,  "Kindergarten");
        glMap.insert(rti_book::G1, "Grade 1");
        glMap.insert(rti_book::G2, "Grade 2");
        glMap.insert(rti_book::G3, "Grade 3");
        glMap.insert(rti_book::G4, "Grade 4");
        return glMap;
    }
}

