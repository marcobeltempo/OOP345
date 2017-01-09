/* OOP345-w6
File: w6.cpp | Date:11/05/16 | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include <iostream>
#include "Grades.h"
using namespace w6;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << argv[0] <<
            ": incorrect number of arguments\n";
        std::cerr << "Usage: " << argv[0] << " file_name\n";
        return 1;
    }

    Grades grades(argv[1]);

    auto letter = [](float num_grade) {

        string letter_grade;
        return
            num_grade >= 90 ? letter_grade = "A+":
            num_grade >= 80 ? letter_grade = "A" :
            num_grade >= 75 ? letter_grade = "B+":
            num_grade >= 70 ? letter_grade = "B" :
            num_grade >= 65 ? letter_grade = "C+":
            num_grade >= 60 ? letter_grade = "C" :
            num_grade >= 55 ? letter_grade = "D+":
            num_grade >= 50 ? letter_grade = "D" :
                              letter_grade = "F" ;
    };

    grades.displayGrades(std::cout, letter);

    std::cout << "Press any key to continue ... ";
    std::cin.get();
}