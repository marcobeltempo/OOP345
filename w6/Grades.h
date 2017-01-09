/* OOP345-w5
File: Grades.h | Date:11/05/16 | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "string"

using namespace std;

namespace w6 {
    class Grades {

    private:
        vector <vector <string>> marks;
        string studentID_;
        float  grade_ = 0.00;

    public:
        Grades(char* filename) {

            ifstream in(filename);
            vector <string> tempGrades;

            while (!in.eof()) {

                string line;
                getline(in, line, '\n');
                stringstream is(line);

                is >> studentID_;
                studentID_.empty();
                is.clear();

                is >> grade_ ;

                tempGrades.push_back(studentID_);
                tempGrades.push_back(to_string(grade_)); // convert float to string

                //reserve vector vector size  
                marks.reserve(marks.size() + tempGrades.size());

                // insert the line with studentID_ and grade_
                marks.push_back(tempGrades);

                is.clear();
                tempGrades.clear();
            }
        }

        void displayGrades(ostream& os, string(*letter)(float)) const {

            os << "Student Id | Numerical Grade | Letter Grade " << endl
                << setfill('-') << setw(44) << " " << endl;
            for (size_t i = 0; i < marks.size(); ++i) {

                os << left << setfill(' ') << setw(10) << marks[i][0] << " | "
                    << setw(15)
                    << setprecision(2)
                    << fixed << stof(marks[i][1]) << " | "
                    << setw(10) << letter(stof(marks[i][1]))
                    << " | " << endl;
            }
        }

        ~Grades() {
            marks.clear();
        }

    };
}// END namespace w6
