/* OOP345- Workshop 2 - unsigned int, Enumerations, String Class and File I/O 

File Stations.h
Version 1.0
Date 9/27/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095
*/

#pragma once
#include <string>
#include <fstream>

#include "Station.h"

using namespace std;

namespace w2 {

    class Stations{

    private:

        char* _filename;
        int stationsCount;
		string name;
        Station* stationTable;

    public:
        
        Stations(char* filename);
		~Stations();
        void update() const;
        void restock() const;
        void report() const;
       };
}