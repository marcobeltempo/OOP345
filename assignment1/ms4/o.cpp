/* OOP345-Assignment 1 - MS4

File: o.cpp | Version: MS4.0.1 | Date: 11/30/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include "o.h"

namespace ms4 {

    /*---Begin Order Class Functions---*/

    Order::Order(vector < string > csv) {

        if (csv.size() < 3 ) { // 3 fields are required for a valid order
            cout << "ERROR: 3 Fields are required for a valid order." << endl;

        }
        else {
         
            if (is_nameValid(csv[1])) {

                productName_ = csv[1];
            }
            else {
                cout << "ERROR: Invalid product name: '" << csv[1] << "' ." << endl;
            }

            if (is_nameValid(csv[0])) {

                customerName_ = csv[0];
            }
            else {
                cout << "ERROR: Invalid customer name: '" << csv[0] << "' ." << endl;
            }
            // process multiple items ordered by a customer
            for (size_t i = 2; i < csv.size(); i++) {
                if (is_nameValid(csv[i])) {
                    itemList_.push_back(csv[i]);
                }
            }
        }
    }

    void Order::print() {

        cout << left << setfill(' ') << "| " << setw(19) << customerName_ << "| " << setw(20) << productName_ << "| " << setw(1);

        for (auto o : itemList_) {
            cout << "[" << o << "] ";
        }
    }

    void Order::graph(ostream & os) {
        for (auto item : itemList_)
            os << '"' << item << '"' << "->" << '"' << customerName_ << '\n' << productName_ << '"' << ";" << endl;
    }
    /*-!-End Order Class Functions-!-*/

    /*---Begin OrderManager Class Functions---*/

    OrderManager::OrderManager(vector < vector < string >> & order) {

        for (auto row : order) {
            orders.push_back(move(Order(row)));
        }
    }

    void OrderManager::orderItemExist(ItemManager & b) {

        for (auto order : orders) {
            for (size_t i = 0; i < order.size(); i++) {
                if (b.findItem(order.getOrderItemList(i)) == nullptr) {
                    cout << order.getCustomerName() + " ordered a " +
                        order.getProductName() + " containing the item " + order.getOrderItemList(i) +
                        " which doesn't exist." << endl;
                }
            }
        }
    }
   
    void OrderManager::print() {

       cout << setw(114) << setfill('_') << " " << endl
            << "|                                       OrderList Ranged Based for Loop                                           |" << endl
            << "|" << setw(113) << setfill('-') << "" << "|" << endl
            << "|    Customer Name   |     Product Name    |                             Items                                    |" << endl
            << "|--------------------|---------------------|----------------------------------------------------------------------| " << endl;

        for (auto o : orders) {

            o.print();
            cout << endl;
        }

       cout << "|" << setw(113) << setfill('-') << "" << "|" << endl
            << "|                                     End of Item List Ranged based for Loop                                      |" << endl
            << "|" << setw(113) << setfill('_') << "" << "|" << ""
            << endl;
    }

    void OrderManager::graph(string file) {

        ofstream os;
        string gvFile = file + ".gv";
        string pngFile = gvFile;
        os.open(gvFile);

        os << "digraph order" << " {" << endl;

        for (auto order : orders)
            order.graph(os);

        os << "}";
        os.close();

        // linux command
        // string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;

        //windows command
        string cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe -Tpng " + gvFile + " > " + pngFile + ".png";

        system(cmd.c_str()); //execute graphiz command 
    }
    /*-!-End OrderManager Class Functions-!-*/

} // END namespace ms44