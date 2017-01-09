/* OOP345- Workshop 3 - Copy and Move Semantics

File Text.h
Version 1.0
Date 10/10/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095
*/

#pragma once 

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace w3 {

    class Text {

    private:

        size_t count; // size_t adapts to machine compiled on
        string* lineTable;

    public:
        size_t size() const { return count; }
        Text(char * filename);
        Text() : count(0), lineTable(nullptr) {  }
        Text(const Text& rhs);
        Text& operator = (const Text& rhs);
        Text(Text&& rhs);
        Text& operator = (Text&& rhs);
        ~Text() { delete[] lineTable; }


    };
}//  end namespace w3
