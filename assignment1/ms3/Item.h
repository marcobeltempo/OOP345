/* OOP345-Assignment 1 - MS3

File: Item.h | Version: MS2.0.1 | Date: 11/23/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
 ___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo                                                                                 |
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

    class Item {

        private:
            string itemName_, installerTask_, removerTask_, seqCode_, description_;

        public:
            Item(vector <string> & csv);
            void print();
            void graph(ostream& os);

    };

}//END namespace ms3