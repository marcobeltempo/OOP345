/* OOP345-Assignment 1 - MS1

File CSVReader.h
Version MS1.0.1
Date 11/06/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095

Revision History
 ___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/06/16 Defined a csvReader, indicies_print, rangedBase_print, iterator_print  |
|                    prototypes.                                                            |
|___________________________________________________________________________________________|
*/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#define PROCESS_DOUBLE_QUOTES

using namespace std;

namespace ms1 {

    void csvReader(char* filename, char delim, vector< vector<string> > &file);
    void indicies_print(const vector< vector<string> > & file);
    void rangedBase_print(const vector< vector<string> > & file);
    void conventional_print(const vector < vector <string> > & file);

}//END Namespace MS1