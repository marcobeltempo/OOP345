/* OOP345-Assignment 1 - MS4

File: i.h | Version: MS4.0.1 | Date: 11/30/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */


#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "t.h"
#include "Util.h"
using namespace std;

namespace ms4 {

    class Item {

    private:
        string itemName_, installerTask_, removerTask_, seqCode_, description_;
   
    public:
        Item(vector <string>  csv);
        void print();
        void graph(ostream& os);
        string& getItemName() { return itemName_; }
        string& getInstaller() { return installerTask_; }
        string& getRemover() { return removerTask_; }
    };

    class ItemManager {

    private:
        vector<Item> items;

    public:
        ItemManager(vector<vector<string> >& task);
        void print();
        void graph(string file);
        void validItem(TaskManager& t);
        size_t size() { return items.size(); }
        Item* findItem(string&  itemName);
        Item* getItem(size_t i) { return &items[i]; }

    };

}//END namespace ms4