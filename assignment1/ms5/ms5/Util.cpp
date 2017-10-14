/* OOP345-Assignment 1 - MS5
File: util.cpp | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "Util.h"

namespace ms5 {

    std::string& trim(std::string& string) {

        while (!string.empty() && isspace(string[0])) {
            string.erase(0, 1);
        }
        while (!string.empty() && isspace(string[string.size() - 1])) {
            string.erase(string.size() - 1, 1);
        }
        return string;
    }
     //read in a csv file 
    void csvReader(std::string filename, char delimiter, std::vector <std::vector<std::string> > &data) {

        std::ifstream is(filename.c_str());

        if (is.is_open()) {

            std::string s;

            while (std::getline(is, s)) {

                auto c = s.find("\r");

                if (c != std::string::npos) {
                    s.erase(c, 1);
                }

                std::string field;
                for (size_t i = 0; i < s.size(); i++) {
#ifdef PROCESS_DOUBLE_QUOTES
                    if (s[i] == '"') {
                        field += s[i];       
                        for (i++; i < s.size(); i++) {
                            field += s[i];
                            if (s[i] == '"')   
                                break;
                        }
                    }
                }
#endif
                std::stringstream ss(s);
                std::vector <std::string> fields;
         
				if (delimiter == ',' ) {
				while (getline(ss, field, delimiter)) {
					trim(field);
					fields.push_back(field);
				}
                data.push_back(fields);
            }
        }
		else {
			std::cerr << "Cannot open the file: '" << filename << "'" << std::endl;
		}
        else {
            std::cerr << "Cannot open the file: '" << filename <<"'" << std::endl;
        }
    }
    //validates a task nama
    bool is_nameValid(const std::string& taskName) {
        if (taskName.empty()) {
            return false;
        }

        for (auto tasks : taskName) {
            //can contain spaces, is alphanumeric, have an underscore, not empty
            if (isspace(tasks) || isalnum(tasks) || tasks == '_'  || tasks =='-' && tasks != ' ') {
                continue;
            }
            return false;
        }
        return true;
    }

    // checks to see that a slot value is numeric
    bool is_slotValid(const std::string& slots) {
        if (slots.empty()) {
            return false;
        }
        for (auto chr : slots) {
            if (isdigit(chr)) {
                continue;
            }
            return false;
        }
        return true;
    }

}  // END namespace ms5

