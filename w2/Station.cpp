/* OOP345- Workshop 2 - unsigned int, Enumerations, String Class and File I/O 

File Station.cpp
Version 1.0
Date 9/27/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095
*/

#include <iostream>
#include <string>
#include <fstream>

#include "Station.h"

using namespace std;

namespace w2 {

  Station::Station() {

    _stationName = "";
    passes[STUDENT_PASS] = 0;
    passes[ADULT_PASS] = 0;
  }

  void Station::set(const string & stationName, unsigned studentPass, unsigned adultPass) {

    _stationName = stationName;
    passes[STUDENT_PASS] = studentPass;
    passes[ADULT_PASS] = adultPass;
  }

  //updates the number of passes - sold if negative, added if positive
  void Station::update(PassType pt, int qty) {

    passes[pt] += qty;
  }

  unsigned Station::inStock(PassType pt) const {

    return passes[pt];

  }

  const string & Station::getName() const {

    return _stationName;

  }

  Station::~Station() {

  }

}