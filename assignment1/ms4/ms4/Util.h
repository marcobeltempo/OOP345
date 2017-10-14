/* OOP345-Assignment 1 - MS4

File: Util.h | Version: MS4.0.1 | Date: 11/30/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
namespace ms4 {
   
   #define PROCESS_DOUBLE_QUOTES
   
   string& trim(string& string);
   void csvReader(string filename, char delimiter, vector <vector<string> > &data);
   bool is_nameValid(const string& taskName);
   bool is_slotValid(const string& slots);

}//END namespace ms4