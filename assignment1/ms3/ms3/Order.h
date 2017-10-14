/* OOP345-Assignment 1 - MS3

File: Order.h | Version: MS2.0.1 | Date: 11/24/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/24/16                                                                        |
|___________________________________________________________________________________________|
*/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include"Util.h"
using namespace std;

namespace ms3 {

    class Order {

    private:
        string customerName_, productName_;
        vector <string>itemList_;
    public:
        Order(vector <string> & csv);
        void print();
        void graph(ostream& os);
    

    };

}//END namespace ms3