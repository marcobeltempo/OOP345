
#include <iostream>
#include <cstring>

#include "CString.h"

namespace w1 {

    CString::CString(char* s) {

        if (!s) {


            data[0] = '\0';

        }
        else {
            strncpy_s(data, s, MAX_CHAR);
            data[MAX_CHAR] = '\0';
        }

    }

    void CString::display(std::ostream& os) {

        os << data;

    }

   
    std::ostream& operator <<(std::ostream& os, CString cs) {

        static int count = 0;

        os << count << ": ";
        count++;

        cs.display(os);

        return os;
    }

} // Namespace w1


