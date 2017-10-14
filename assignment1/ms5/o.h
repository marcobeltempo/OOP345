/* OOP345-Assignment 1 - MS5

File: o.h | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <vector>
#include <string>

#include "i.h"
#include"Util.h"

namespace ms5 {

    class Order {

    private:
        std::string customerName_, productName_;
        std::vector<std::string> itemList_;

    public:
        Order() { }
        Order(std::vector<std::string> csv);
        void print();
        void graph(std::ostream& os);
        std::size_t size() { return itemList_.size(); }
        std::string& getOrderItemList(size_t i) { return itemList_[i]; }
        std::string& getCustomerName() { return customerName_; }
        std::string& getProductName() { return productName_; }
    };

    class OrderManager {

    private:
        std::vector<Order> orders;

    public:
        OrderManager(std::vector<std::vector<std::string>>& order);
        void orderItemExist(ItemManager& b);
        void print();
        void graph(std::string file);
        size_t size() { return orders.size(); }
        Order* getOrder(size_t o) { return &orders[o]; }

    };

}//END namespace ms5
