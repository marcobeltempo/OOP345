/* OOP345-Assignment 1 - MS4

File: util.cpp | Version: MS4.0.1 | Date: 11/30/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "util.h"

using namespace std;
namespace ms4 {

    string& trim(string& string) {

        while (!string.empty() && isspace(string[0])) {
            string.erase(0, 1);
        }
        while (!string.empty() && isspace(string[string.size() - 1])) {
            string.erase(string.size() - 1, 1);
        }
        return string;
    }
     //read in a csv file 
    void csvReader(string filename, char delimiter, vector <vector<string> > &data) {

        ifstream is(filename.c_str());

        if (is.is_open()) {

            string s;

            while (getline(is, s)) {

                auto c = s.find("\r");

                if (c != string::npos) {
                    s.erase(c, 1);
                }

                string field;
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
                stringstream ss(s);
                vector <string> fields;
         
                while (getline(ss, field, delimiter)) {
                    trim(field);
                    fields.push_back(field);
                }
                data.push_back(fields);
            }
        }
        else {
            cerr << "Cannot open the file: '" << filename <<"'" << endl;
        }
    }
    //validates a task nama
    bool is_nameValid(const string& taskName) {
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
    bool is_slotValid(const string& slots) {
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

}  // END namespace ms4