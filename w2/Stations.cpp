/* OOP345- Workshop 2 - unsigned int, Enumerations, String Class and File I/O 

File Stations.cpp
Version 1.0
Date 9/27/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095
*/

#include <iostream> 
#include <fstream> 
#include <string> 
#include <cctype> 
#include <iomanip>

#include "Stations.h"
#include "Station.h"

using namespace std;

namespace w2 {

  Stations::Stations(char * filename) {

    fstream is(filename);

    //is.open(filename, ios::in);

    if (!is.is_open()) {

      cerr << "Cannot open data file -->" << filename << "<--" << endl;

    }
    string line;

    is >> stationsCount;

    is.ignore(2, ';');

    cout << "Station Count = " << stationsCount << endl;

    stationTable = new Station[stationsCount];

    string stationName;

    unsigned sPass = 0, aPass = 0;

    for (size_t i = 0; i < stationsCount; i++) {

      getline(is, stationName, ';');
      is >> sPass;
      is >> aPass;

      stationTable[i].set(stationName, sPass, aPass);
    }

    is.close();
  }

  void Stations::update() const {

    cout << "Passes Sold :" << endl << "-------------";
    for (int i = 0; i < stationsCount; i++) {
      int student, adult;
      cout << stationTable[i].getName();
      cout << endl;
      cout << "Student Passes sold : ";
      cin >> student;
      cout << "Adult   Passes sold : ";
      cin >> adult;

      stationTable[i].update(STUDENT_PASS, -student);
      stationTable[i].update(ADULT_PASS, -adult);
    }

  }
  void Stations::restock() const {

    cout << "Passes Added :" << endl << "--------------" << endl;

    for (int i = 0; i < stationsCount; i++) {

      int s, a;

      cout << stationTable[i].getName() << endl;
      cout << "Student Passes added : ";
      cin >> s;
      cout << "Adult   Passes added : ";
      cin >> a;
      stationTable[i].update(STUDENT_PASS, s);
      stationTable[i].update(ADULT_PASS, a);
    }
  }
  void Stations::report() const {

    cout << "Passes in Stock : Student Adult" << endl;
    cout << "-------------------------------" << endl;

    for (int i = 0; i < stationsCount; i++) {

      cout << left << setw(19) << stationTable[i].getName() << setw(6) << stationTable[i].inStock(STUDENT_PASS) << setw(6) << stationTable[i].inStock(ADULT_PASS) << endl;
    }
  }

  Stations::~Stations() {

    if (stationTable) {
      delete[] stationTable;
      stationTable = nullptr;
    }
  }

}//close w2 namespace