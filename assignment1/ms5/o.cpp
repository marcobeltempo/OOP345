/* OOP345-Assignment 1 - MS5

File: o.cpp | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "o.h"


namespace ms5 {

    /*---Begin Order Class Functions---*/

    Order::Order(std::vector < std::string > csv) {

        if (csv.size() < 3) { // 3 fields are required for a valid order
            std::cout << "ERROR: 3 Fields are required for a valid order.\n";

        }
        else {

            if (is_nameValid(csv[1])) {

                productName_ = csv[1];
            }
            else {
                std::cout << "ERROR: Invalid product name: '" + csv[1] + "' . '\n' ";
            }

            if (is_nameValid(csv[0])) {

                customerName_ = csv[0];
            }
            else {
                std::cout << "ERROR: Invalid customer name: '" << csv[0] << "' .\n";
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

        std::cout << std::left << std::setfill(' ') << "| " << std::setw(19) << customerName_ << "| " << std::setw(20) << productName_ << "| " << std::setw(1);

        for (auto o : itemList_) {
            std::cout << "[" << o << "] ";
        }
    }

    void Order::graph(std::ostream & os) {
        for (auto item : itemList_)
            os << '"' << item << '"' << "->" << '"' << customerName_ << '\n' << productName_ << '"' << ";\n";
    }
    /*-!-End Order Class Functions-!-*/

    /*---Begin OrderManager Class Functions---*/

    OrderManager::OrderManager(std::vector < std::vector < std::string >> & order) {

        for (auto row : order) {
            orders.push_back(std::move(Order(row)));
        }
    }

    void OrderManager::orderItemExist(ItemManager & b) {

        for (auto order : orders) {
            for (size_t i = 0; i < order.size(); i++) {
                if (b.findItem(order.getOrderItemList(i)) == nullptr)
                    std::cout << (order.getCustomerName() + " ordered a " +
                        order.getProductName() + " containing the item " + order.getOrderItemList(i) +
                        " which doesn't exist.\n");
            }
        }
    }

    void OrderManager::print() {

        std::cout << std::setw(114) << std::setfill('_') << " " << std::endl
            << "|                                            Order List Ranged based for Loop                                     |" << std::endl
            << "|    Customer Name   |     Product Name    |                             Items                                    |\n"
            << "|--------------------|---------------------|----------------------------------------------------------------------|\n";

        for (auto o : orders) {

            o.print();
            std::cout << "\n";
        }

        std::cout << "|" << std::setw(113) << std::setfill('-') << "" << "|\n"
            << "|                                     End of Item List Ranged based for Loop                                      |\n"
            << "|" << std::setw(113) << std::setfill('_') << "" << "|" << ""
            << std::endl;
    }

    void OrderManager::graph(std::string file) {

        std::ofstream os;
        std::string gvFile = file + ".gv";
        std::string pngFile = gvFile + ".png";
        os.open(gvFile);

        os << "digraph order" << " {\n";

        for (auto order : orders)
            order.graph(os);

        os << "}";
        os.close();

        // linux command
        // std::string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;

        //windows command
        std::string cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe -Tpng " + gvFile + " > " + pngFile + ".png";

        system(cmd.c_str()); //execute graphiz command 
    }
    /*-!-End OrderManager Class Functions-!-*/

} // END namespace ms5