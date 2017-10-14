/* OOP345-Assignment 1 - MS3

File: Task.cpp | Version: MS2.0.3 | Date: 11/06/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/06/16                                                                        |
|___________________________________________________________________________________________|*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Item.h"

namespace ms3 {

    Item::Item(vector<string> &csv) {

        
        switch (csv.size()) {

        case 5:
            description_ = csv[4];
        case 4:
            if (is_nameValid(csv[0]) && is_slotValid(csv[3]) && csv.size() > 3) {
                seqCode_ = csv[3];
            }
            else {
                cout << "ERROR: Assinging row : "; for (auto i : csv) {
                    cout << i << ", ";
                }           cout << endl;
                break;
            }

        case 3:
            if (is_nameValid(csv[2])) {
                removerTask_ = csv[2];

            }
            else {
                cout << "ERROR: Assinging failed passed item name: " << csv[2] << endl;
            }
        case 2:
            if ( is_nameValid(csv[1])) {
                installerTask_ = csv[1];
            }
            else {
                cout << "ERROR: Assinging slot: " << csv[1] << endl;
            
            }
        case 1:
            if (is_nameValid(csv[0])) {
                itemName_ = csv[0];

            }
            else {
                cout << "ERROR: Assinging item name: " << csv[0] << endl;
         
            }
            break;
        default:
            cerr << "Error: 4-5 Fields are required for a valid Item." << endl;
            break;
    }
}

    void Item::print() {
        cout << left <<setfill(' ') << "| " << setw(20) << itemName_ << "| " << setw(21) << installerTask_
            << "| " << setw(20) << removerTask_ << " | " << setw(5) << seqCode_
            << "| " << setw(32) << description_ << " |" << endl;
    }

    void Item::graph(ostream& os)
    {
        os << '"' << itemName_ << '"' << "->" << '"' << installerTask_ << '"' << " [color=green];" << endl;
        os << '"' << itemName_ << '"' << "->" << '"' << removerTask_ << '"' << " [color=red];" << endl;
    }
}  // END namespace ms3