#ifndef _CSTRING_H_
#define _CSTRING_H_


#define MAX_CHAR 3

namespace w1 {

    class CString {

        char data[MAX_CHAR + 1];

    public:

        CString(char* s);
        void display(std::ostream& os);

    };

    std::ostream& operator <<(std::ostream& os, CString cs);

}

#endif // !_CSTRING_H_
