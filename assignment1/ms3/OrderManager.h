/* OOP345-Assignment 1 - MS3

File: OrderManager.h | Version: MS2.0.1 | Date: 11/24/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
|-------------------------------------------------------------------------------------------|
|M.Beltempo 11/24/16                                                                        |
|___________________________________________________________________________________________| */
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Order.h"

using namespace std;
namespace ms3 {

    class OrderManager {
    private:
        vector<Order> orders;

    public:
        OrderManager(vector<vector<string> >& order);
        void print();
        void graph(string file);
       // void IntegrityCheck(OrderManager& oic);
    };

}  // END namespace ms3