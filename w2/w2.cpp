/* OOP345- Workshop 2 - unsigned int, Enumerations, String Class and File I/O 

File w2.cpp
Version 1.0
Date 9/27/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095

*/

#include <iostream>
#include "Stations.h"

int main(int argc, char* argv[]) {
    std::cout << "\nCommand Line : ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 2) {
        std::cerr << "\nIncorrect number of arguments\n";
        return 1;
    }
    w2::Stations stations(argv[1]);
    stations.update();
    stations.restock();
    stations.report();
    return 0;
}