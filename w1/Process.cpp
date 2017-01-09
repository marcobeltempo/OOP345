#include <iostream>

#include "Process.h"
#include "CString.h"

void process(char *s) {

    //	cout << "Process(" << s << ")" << endl;

    w1::CString cs(s);
    std::cout << cs << "\n";

}