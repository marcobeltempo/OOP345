/* OOP345-Assignment 1 - MS2

File: ms2_main.cpp | Version: MS2.0.2 | Date: 11/06/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
 __________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/06/16 Defined a csvReader function along with a indicies, range base for,    |
|                    and conventional print functions.                                      |
|M.Beltempo 11/13/16 Created a TaskManager object for testing                               |
|M.Beltempo          Displayed testTM with ibject display function                          |
|___________________________________________________________________________________________| */

#include "TaskManager.h"

using namespace ms2;

int main(int argc, char** argv) {
    string filename;
    char delim;
    vector<vector<string>> csv;
    if (argc != 3) {
        cerr << argc << "You must provide 3 aruments" << endl
            << "Command Line: "
            << "Arg1= Filename Arg2= File Delimiter" << endl;
        return 1;
    }
    filename = argv[1];
    delim = argv[2][0];
    cout << "Task File: " << argv[1] << endl
        << "Field Delimiter: " << argv[2][0] << endl
        << endl;

    csvReader(filename, delim, csv);
    TaskManager testTM(csv);
    testTM.print();

    return 0;
}