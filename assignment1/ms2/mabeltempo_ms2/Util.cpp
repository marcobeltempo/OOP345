/* OOP345-Assignment 1 - MS2

File: Util.cpp | Version: MS2.0.1 | Date: 11/13/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
__________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/18/16 Relocated implementations of, trim and csvReader functions from Task.  |
|M.Beltempo 11/23/16 Define bool functions to validate task names and slot vlaues.          |
|___________________________________________________________________________________________| */
#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
namespace ms2 {

    string& trim(string& s, char trimChar = ' ');
    string& trim(string& s, char trimChar) {
        while (!s.empty() && s[0] == trimChar) s.erase(0, 1);

        while (!s.empty() && s[s.size() - 1] == trimChar) s.erase(s.size() - 1, 1);

        return s;
    }

    void csvReader(char* filename, char delim, vector<vector<string> >& file) {
        ifstream is(filename);
        if (is) {
            string row;
            vector<string> fields;

            while (getline(is, row)) {
                auto cr = row.find('\r');
                if (cr != string::npos) row.erase(cr, 1);

                string col;
                for (size_t i = 0; i < row.size(); i++) {
                    if (row[i] == '"') {
                        col += row[i];  // copy 1st "
                        for (i++; i < row.size(); i++) {
                            col += row[i];
                            if (row[i] == '"')  // found 2nd "
                                break;
                        }
                    }
                    else

                        if (row[i] != delim) {
                            col += row[i];
                        }
                        else {
                            trim(col);
                            fields.push_back(col);
                            col.clear();
                        }
                }
                trim(col);
                fields.push_back(col);
                file.push_back(fields);
                fields.clear();
            }
            is.close();
        }
        else {
            cerr << "Error: Cannot Open File " << filename << "\n";
        }
    }

    bool is_nameValid(const string& taskName) {
        if (taskName.empty()) {
            return false;
        }

        for (auto tasks : taskName) {
            if (isspace(tasks) || isalnum(tasks) || tasks == '_') {
                continue;
            }
            return false;
        }
        return true;
    }

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

}  // END namespace ms2