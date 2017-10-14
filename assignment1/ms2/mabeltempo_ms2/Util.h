/* OOP345-Assignment 1 - MS2

File: Util.h | Version: MS2.0.1 | Date: 11/13/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095
 __________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/18/16 Declared utility functions, trim and csvReader functions from Task.    | 
|M.Beltempo 11/23/16 Declared bool functions to validate task names and slot vlaues.        |
|___________________________________________________________________________________________| */

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
namespace ms2 {

   string & trim(string & s, char trimChar);
   void csvReader(char* filename, char delim, vector <vector <string> > & file);
   bool is_nameValid(const string& taskName);
   bool is_slotValid(const string& slots);

}//END namespace ms2