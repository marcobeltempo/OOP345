/* OOP345-Assignment 1 - MS4

File: o.h | Version: MS4.0.1 | Date: 11/30/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

#include "i.h"
#include"Util.h"

using namespace std;

namespace ms4 {

    class Order {

    private:
        string customerName_, productName_;
        vector<string> itemList_;

    public:
        Order() { }
        Order(vector<string> csv);
        void print();
        void graph(ostream& os);
        size_t size() { return itemList_.size(); }
        string& getOrderItemList(size_t i) { return itemList_[i]; }
        string& getCustomerName() { return customerName_; }
        string& getProductName() { return productName_; }
    };

    class OrderManager {

    private:
        vector<Order> orders;

    public:
        OrderManager(vector<vector<string>>& order);
        void orderItemExist(ItemManager& b);
        void print();
        void graph(string file);
        size_t size() { return orders.size(); }
        Order* getOrder(size_t o) { return &orders[o]; }

    };

}//END namespace ms4