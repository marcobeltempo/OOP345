/* OOP345-w7
File: Sale.h | Date: 11/17/16 | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <vector>
#include <iomanip>

#include "Product.h"

using namespace std;

namespace w7 {

    class Sale {

    private:
        vector <iProduct*> products;

    public:
        Sale(const char* filename) {

            ifstream fs(filename, ios::out);

            if (!fs) {
                cout << "There was an error trying to open the file " << filename << endl;
            }
            else {
                while (fs) {
                    products.push_back(readProduct(fs));
                }
            }
        }

        void display(ostream& os) const {

            double total = 0;
            os << "Product No      Cost Taxable" << endl;

            for (auto i = 0; i < products.size(); i++) {

                os << products[i];
                os << endl;
                total += products[i]->getCharge(); //calculate customer total
            }

            os << "     Total" << setw(10) << total << endl;
        }

        ~Sale() { for (auto p : products) delete p; } //destructor

    };

}// END namespace w7