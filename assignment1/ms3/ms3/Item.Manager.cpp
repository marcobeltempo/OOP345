/* OOP345-Assignment 1 - MS3

File: ItemManager.cpp | Version: MS2.0.1 | Date: 11/23/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
|-------------------------------------------------------------------------------------------|
|M.Beltempo 11/23/16                                                                        |
|___________________________________________________________________________________________| */

#include "ItemManager.h"

using namespace std;

namespace ms3 {

    ItemManager::ItemManager(vector<vector<string>>& item) {
        int line = 0;
        for (auto& row : item) {
            line++;
            items.push_back(move(Item(row)));
        }
    }

    void ItemManager::print() {
        cout << setw(111) << setfill('_') << " " << endl;
        cout << "|                                         Item List Ranged based for Loop                                     |" << endl;
        cout << "|" << setw(109) << setfill('-') << "" ; cout <<  "|" << endl;
        cout << "|         Item        |    Installer Task    |     Remover Task     | Code |            Description           |" << endl
             << "|---------------------|----------------------|----------------------|------|----------------------------------|" << endl;
        
            for (auto i : items) {
            i.print();
        }

       cout << "|-------------------------------------------------------------------------------------------------------------|" << endl
            << "|                                     End of Item List Ranged based for Loop                                  |" << endl
            << "|_____________________________________________________________________________________________________________|" << endl
            << endl;
    }

    void ItemManager::graph(string file)
    {
        ofstream itm;
        string gvFile = file + ".gv";
        string pngFile = gvFile;
        itm.open(gvFile);

        itm << "digraph order" << " {" << endl;

        for (auto item : items)
            item.graph(itm);

        itm << "}";
        itm.close();

        // uncomment when on linux
        //string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;
        // uncomment when on windows

        string cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe -Tpng " + gvFile + " > " + pngFile + ".png";

        system(cmd.c_str());
    }
}//END namespace ms3