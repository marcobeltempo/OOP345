/* OOP345- Workshop 3 - Copy and Move Semantics

File Text.cpp
Version 1.0
Date 10/10/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095
*/

#include <fstream>
#include <iostream>
#include <string>

#include "Text.h"

using namespace std;

namespace w3 {

    Text::Text(char * filename) : count(0), lineTable(nullptr) {

        fstream is(filename, ios::in);

        if (is.is_open()) {

            string line;

            while (getline(is, line)) {

                count++;
            }
            cout << "File " << filename << " has " << count << " lines." << endl;

            lineTable = new string[count];

            is.clear(); // reset the END-OF-FILE error state
            is.seekg(0, ios_base::beg);// position file at begininig

            for (size_t i = 0; i < count; i++) {

                getline(is, lineTable[i]);
            }

            is.close();
        }
        else {

            cerr << "Cannot open filename -->" << filename << "<--" << endl;
            exit(1);
        }
    }


    Text& Text::operator = (const Text& rhs) {

        if (this != &rhs) {

            delete[] lineTable;
            count = rhs.count;
            lineTable = new string[count];

            for (size_t i = 0; i < count; i++) {

                lineTable[i] = rhs.lineTable[i];
            }
        }
        return *this;
    }

    Text::Text(Text&& rhs) : count(0), lineTable(nullptr) { 

        if (this != &rhs) {

            *this = move(rhs);
        }
    }
    Text& Text::operator = (Text&& rhs) {

        if (this != &rhs) {

            delete[] lineTable;

            //steal brains/ memory address
            count = rhs.count;
            lineTable = rhs.lineTable;

            // turn into zombie
            rhs.count = 0;
            rhs.lineTable = nullptr;

        }
        return *this; //treat as right value

    }

    Text::Text(const Text& rhs) : count(0), lineTable(nullptr) { *this = rhs; }
}