/* OOP345-Assignment 1 - MS3

File: ItemManager.h | Version: MS2.0.1 | Date: 11/23/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
|-------------------------------------------------------------------------------------------|
|M.Beltempo 11/23/16                                                                        |
|___________________________________________________________________________________________| */
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Item.h"

using namespace std;
namespace ms3 {

    class ItemManager {
    private:
        vector<Item> items;

    public:
        ItemManager(vector<vector<string> >& task);
        void print();
        void graph(string file);

    };

}  // END namespace ms3