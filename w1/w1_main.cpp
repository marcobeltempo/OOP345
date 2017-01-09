#include <iostream>
#include <cstring>

#include "CString.h"
#include "Process.h"

using namespace std;

int main(int argc, char* argv[]) {

    /* cout << "argc= " << argc << endl;
    for (int arg = 0; arg < argc; arg++){

    cout << "arg[" << arg << "]= --> " << argv [arg] << "\n";

    }*/

    std::cout << "Commnd Line : ";
    for (int arg = 0; arg < argc; arg++) {

        cout << " " << argv[arg];

    }

    cout << "\n";

    if (argc == 1) // no arguments
    {

        cerr << "Insufficent number of arguments (Min. 1)" << "\n";
        return 1;
    }

    cout << "Maximum number of charecters stored: " << MAX_CHAR << endl;

    for (int arg = 0; arg < argc; arg++) {

        process(argv[arg]);

    }
}