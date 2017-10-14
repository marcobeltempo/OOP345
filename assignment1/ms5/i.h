/* OOP345-Assignment 1 - MS5

File: i.h | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <vector>
#include <string>

#include "t.h"
#include "Util.h"

namespace ms5 {

    class Item {

    private:
        std::string itemName_, installerTask_, removerTask_, seqCode_, description_;
   
    public:
        Item(std::vector <std::string>  csv);
        void print();
        void graph(std::ostream& os);
        std::string& getItemName() { return itemName_; }
        std::string& getInstaller() { return installerTask_; }
        std::string& getRemover() { return removerTask_; }
    };

    class ItemManager {

    private:
        std::vector<Item> items;

    public:
        ItemManager(std::vector<std::vector<std::string> >& task);
        void print();
        void graph(std::string file);
        void validItem(TaskManager& t);
        size_t size() { return items.size(); }
        Item* findItem(std::string&  itemName);
        Item* getItem(size_t i) { return &items[i]; }

    };

}//END namespace ms5
