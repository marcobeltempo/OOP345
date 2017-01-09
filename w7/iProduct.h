/* OOP345-w7
File: iProduct.h | Date: 11/17/16 | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <iostream>
#include <fstream>

using namespace std;
namespace w7 {

    class iProduct {

    public:
        virtual double getCharge() const = 0;
        virtual void display(ostream&) const = 0;
    };

    ostream& operator<< (ostream&, const iProduct*);
    iProduct* readProduct(ifstream&);

}// END namespace w7