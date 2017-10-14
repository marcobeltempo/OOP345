/* OOP345-Assignment 1 - MS5

File: i.cpp | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "i.h"

using namespace std;
namespace ms5 {

    /*---Begin Item Class Functions---*/

    Item::Item(std::vector < std::string > csv) {

        switch (csv.size()) {

        case 5:
                description_ = csv[4]; // not required
            
        case 4:
            if (is_slotValid(csv[3])) {

                seqCode_ = csv[3];
       }       
        case 3:
            if (is_nameValid(csv[2])) {
                removerTask_ = csv[2];

            }
            else {
                std::cout << "ERROR: Assinging failed passed item name: " << csv[2] << std::endl;
            }
        case 2:
            if (is_nameValid(csv[1])) {
                installerTask_ = csv[1];
            }
            else {

                std::cout << "ERROR: Assinging slot: " << csv[1] << std::endl;
            }
        case 1:
            if (is_nameValid(csv[0])) 
                itemName_ = csv[0];
           
            else 
                std::cout << "ERROR: Assinging item name: " << csv[0] << std::endl;
                break;

        default:
            std::cerr << "Error: 4-5 Fields are required for a valid Item. Only " << csv.size()
               << " were found" << std::endl;
        }
    }

    void Item::print() {
        std::cout << std::left << std::setfill(' ') << "| " << std::setw(24) << itemName_ << "| " << std::setw(21) << installerTask_ << "| " << std::setw(20) << removerTask_ << " | " << std::setw(5) << seqCode_ << "| " << std::setw(32) << description_ << " |" << std::endl;
    }

    void Item::graph(std::ostream & os) {
        os << '"' << itemName_ << '"' << "->" << '"' << installerTask_ << '"' << " [color=green];" << std::endl;
        os << '"' << itemName_ << '"' << "->" << '"' << removerTask_ << '"' << " [color=red];" << std::endl;
    }
    /*-!-End Item Class Functions-!-*/

    /*---Begin ItemManager Class Functions---*/

    //process each row processed from the file into a 2D vector and create Item Objects
    ItemManager::ItemManager(std::vector <std::vector <std::string >> & item) {
        int line = 0;
        for (auto row : item) {
            line++;
            items.push_back(std::move(Item(row)));
        }
    }

    Item* ItemManager::findItem(std::string& itemName) {

        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].getItemName() == itemName) {
                return &items[i];
            }
        }
        return nullptr;
    }

    void ItemManager::validItem(TaskManager & t) {
       
        std::cout << "\n";
        for (auto i : items) {
            if (t.findTask(i.getInstaller()) == nullptr) {  //check each task references a installer task
                std::cout << "Item " + i.getItemName() + " references installer task " +
                    i.getInstaller() + " but it doesn't exist." << std::endl;
            }

            if (t.findTask(i.getRemover()) == nullptr) {   //check each task references a remover task
                std::cout << "Item " + i.getItemName() + " references remover task " +
                    i.getRemover() + " but it doesn't exist." << std::endl;
            }
        }
    }

    void ItemManager::print() {

        std::cout << " " << std::setw(114) << std::setfill('_') << " " << std::endl;
        std::cout << "|                                           Item List Ranged based for Loop                                       |" << endl;
        std::cout << "|" << std::setw(113) << std::setfill('-') << "" << "|" << std::endl;
        std::cout << "|         Item            |    Installer Task    |     Remover Task     | Code |            Description           |" << endl
             << "|-------------------------|----------------------|----------------------|------|----------------------------------|" << endl;

        for (auto i : items) {
                
            i.print();
        }

        std::cout  << "|" << std::setw(113) << std::setfill('-') << "" << "|" << std::endl
            << "|                                     End of Item List Ranged based for Loop                                      |" << endl
            << "|" << std::setw(113) << std::setfill('_') << "" << "|" << endl
            << endl;
    }

    void ItemManager::graph(std::string file) {

        std::ofstream itm;
        std::string gvFile = file + ".gv";
		std::string pngFile = gvFile + ".png";
		itm.open(gvFile);

        itm << "digraph order" << " {" << std::endl;

        for (auto item : items) 

            item.graph(itm);
            itm << "}";
            itm.close();
        
        // linux command
        // std::string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;

        //windows command
            std::string cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe -Tpng " + gvFile + " > " + pngFile + ".png";

        system(cmd.c_str()); //execute graphiz command 
    }

    /*-!-End ItemManager Class Functions-!-*/

} // END namespace ms5
