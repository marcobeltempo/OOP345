/* OOP345-Assignment 1 - MS4

File: i.cpp | Version: MS4.0.1 | Date: 11/30/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include "i.h"

namespace ms4 {

    /*---Begin Item Class Functions---*/

    Item::Item(vector < string > csv) {

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
                cout << "ERROR: Assinging failed passed item name: " << csv[2] << endl;
            }
        case 2:
            if (is_nameValid(csv[1])) {
                installerTask_ = csv[1];
            }
            else {

                cout << "ERROR: Assinging slot: " << csv[1] << endl;
            }
        case 1:
            if (is_nameValid(csv[0])) 
                itemName_ = csv[0];
           
            else 
                cout << "ERROR: Assinging item name: " << csv[0] << endl;
                break;

        default:
            cerr << "Error: 4-5 Fields are required for a valid Item. Only " << csv.size()
               << " were found" << endl;
        }
    }

    void Item::print() {
        cout << left << setfill(' ') << "| " << setw(24) << itemName_ << "| " << setw(21) << installerTask_ << "| " << setw(20) << removerTask_ << " | " << setw(5) << seqCode_ << "| " << setw(32) << description_ << " |" << endl;
    }

    void Item::graph(ostream & os) {
        os << '"' << itemName_ << '"' << "->" << '"' << installerTask_ << '"' << " [color=green];" << endl;
        os << '"' << itemName_ << '"' << "->" << '"' << removerTask_ << '"' << " [color=red];" << endl;
    }
    /*-!-End Item Class Functions-!-*/

    /*---Begin ItemManager Class Functions---*/

    //process each row processed from the file into a 2D vector and create Item Objects
    ItemManager::ItemManager(vector < vector < string >> & item) {
        int line = 0;
        for (auto row : item) {
            line++;
            items.push_back(move(Item(row)));
        }
    }

    Item* ItemManager::findItem(string & itemName) {

        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].getItemName() == itemName) {
                return &items[i];
            }
        }
        return nullptr;
    }

    void ItemManager::validItem(TaskManager & t) {
       
        cout << endl;

        for (auto i : items) {
            if (t.findTask(i.getInstaller()) == nullptr) {  //check each task references a installer task
                cout << "Item " + i.getItemName() + " references installer task " +
                    i.getInstaller() + " but it doesn't exist." << endl;
            }

            if (t.findTask(i.getRemover()) == nullptr) {   //check each task references a remover task
                cout << "Item " + i.getItemName() + " references remover task " +
                    i.getRemover() + " but it doesn't exist." << endl;
            }
        }
    }

    void ItemManager::print() {

        cout << " " << setw(114) << setfill('_') << " " << endl;
        cout << "|                                           Item List Ranged based for Loop                                       |" << endl;
        cout << "|" << setw(113) << setfill('-') << "" << "|" << endl;
        cout << "|         Item            |    Installer Task    |     Remover Task     | Code |            Description           |" << endl
             << "|-------------------------|----------------------|----------------------|------|----------------------------------|" << endl;

        for (auto i : items) {
                
            i.print();
        }

      cout  << "|" << setw(113) << setfill('-') << "" << "|" << endl
            << "|                                     End of Item List Ranged based for Loop                                      |" << endl
            << "|" << setw(113) << setfill('_') << "" << "|" << endl 
            << endl;
    }

    void ItemManager::graph(string file) {

        ofstream itm;
        string gvFile = file + ".gv";
        string pngFile = gvFile;
        itm.open(gvFile);

        itm << "digraph order" << " {" << endl;

        for (auto item : items) 

            item.graph(itm);
            itm << "}";
            itm.close();
        
        // linux command
        // string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;

        //windows command
        string cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe -Tpng " + gvFile + " > " + pngFile + ".png";

        system(cmd.c_str()); //execute graphiz command 
    }

    /*-!-End ItemManager Class Functions-!-*/

} // END namespace ms4