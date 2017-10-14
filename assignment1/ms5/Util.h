/* OOP345-Assignment 1 - MS5
File: Util.h | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <vector>
#include <string>
#include <fstream>

namespace ms5 {
   
   #define PROCESS_DOUBLE_QUOTES
   
   std::string& trim(std::string& string);
   void csvReader(std::string filename, char delimiter, std::vector <std::vector<std::string> > &data);
   bool is_nameValid(const std::string& taskName);
   bool is_slotValid(const std::string& slots);

}//END namespace ms5
