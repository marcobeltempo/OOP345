/* OOP345-Assignment 1 - MS3

File: Order.cpp | Version: MS2.0.1 | Date: 11/24/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/24/16                                                                        |
|___________________________________________________________________________________________|*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Order.h"

namespace ms3 {

    Order::Order(vector<string> &csv) {

        if (csv.size() < 3) {
            cout << "Error: 3 Fields are required for a valid order." << endl;
         
        }
        else {

            for (auto i = csv.begin(); i != csv.end(); ++i) {
                if (is_nameValid(csv[1]) && is_nameValid(csv[0]))
                {
                    customerName_ = csv[0];
                    productName_ = csv[1];
                }
                else
                {
                    cout << "ERROR: Assining a customer name: " << csv[0] << " to the item: " << csv[1] << endl;
                       
                    break;
                }
            }
            if (is_nameValid(csv[0])) {
                for (int i = 2; i < csv.size(); i++) {
                    if (is_nameValid(csv[i])) {
                        itemList_.push_back(csv[i]);

                    }
                }
            }
        }
    }

    void Order::print() {

   
            cout << left << setfill(' ')
                << "| " << setw(14) << customerName_
                << "| " << setw(16) << productName_
                << "| " << setw(1);

            for (auto o : itemList_) {

                cout << "[" << o << "] ";

            }
          

        
    }
    void Order::graph(ostream& os)
    {
        for (auto item : itemList_)
            os << '"' << item << '"' << "->" << '"' << customerName_ << '\n' << productName_ << '"' << ";" << endl;
    }


}  // END namespace ms3