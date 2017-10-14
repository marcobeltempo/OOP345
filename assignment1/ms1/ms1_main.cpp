/* OOP345-Assignment 1 - MS1

File ms1_main.cpp
Version MS1.0.1
Date 11/06/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095

Revision History
 __________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/06/16 Implemented test function calls to display file data from command line |
|M.Beltempo 11/07/16 Added print menu                                                       |
|___________________________________________________________________________________________|
*/

#include <algorithm> 
#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Task.h"

using namespace std;
using namespace ms1;

int main(int argc, char ** argv) {
    char * filename;
    char delim;

    if (argc != 3) {
        cerr << "Please provide 3 arguments." << endl;
        cerr << "Usage: " << argv[0] << " file delimiter-char\n";
        return 2;
    }

    filename = "phoneDB2.csv";//argv[1];
    delim = ',';//argv[2][0];

    cout << "Reading " << filename << "..." << endl;
    vector <vector <string> > data;
    csvReader(filename, delim, data);

    int selection;
    bool exit = true;
    do  
  
    {
       cout << "Select an option to print " << filename << ":" << endl
            << "(1) Ranged Based For" << endl
            << "(2) Indicies Loop"    << endl
            << "(3) Iterator Loop"    << endl
            << "(4) Print All"        << endl
            << "(0) Exit"             << endl
            << "> ";
        
        cin >> selection;

        switch (selection) {
    
            case 1:
                rangedBase_print(data);
                cout <<  "Print Complete!" << endl << endl;
                exit = false;
                break;

            case 2:
                indicies_print(data);
                cout << "Print Complete!" << endl << endl;
                exit = false;
                break;

            case 3:
                conventional_print(data);
                cout << "Print Complete!" << endl << endl;
                exit = false;
                break;

            case 4:
                rangedBase_print(data);
                indicies_print(data);
                conventional_print(data); 
                cout << "Print Complete!" << endl << endl;
                exit = false;
                break;

            case 0:
                cout << "Now Exiting!" << endl;
                exit = true;
                break;

            default:
                cout << "Selection between (0-4)" << endl;
                exit = false;
                break;
        }

    } while (!exit);

    return 0;
}