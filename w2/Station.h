/* OOP345- Workshop 2 - unsigned int, Enumerations, String Class and File I/O 

File Station.h
Version 1.0
Date 9/27/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095
*/

#pragma once
#include <string>
#include <fstream>

using namespace std;

namespace w2 {

  enum PassType {
    STUDENT_PASS,
    ADULT_PASS,
    PASS_COUNT
  };

  class Station {

    private:

    string _stationName;
    int passes[PASS_COUNT];

    public:

    Station();
    void set(const string & stationName, unsigned studentPass, unsigned adultPass);
    void update(PassType pt, int qty);
    unsigned inStock(PassType) const;
    const string & getName() const;
    ~Station();

  };

} //Namespace w2