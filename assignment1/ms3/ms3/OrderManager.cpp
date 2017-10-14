/* OOP345-Assignment 1 - MS3

File: TaskManager.cpp | Version: MS2.0.2 | Date: 11/13/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
|-------------------------------------------------------------------------------------------|
|M.Beltempo 11/13/16 Defined TaskManager functions                                          |
|M.Beltempo 11/18/16 Define One arg constructor stores each instance.                       |
|                    Seperate the print() function.                                         |
|M.Beltempo 11/23/16 Modifed the output display                                             |
|___________________________________________________________________________________________| */

#include "OrderManager.h"

using namespace std;

namespace ms3 {

    OrderManager::OrderManager(vector<vector<string>>& order) {
        int line = 0;
        for (auto& row : order) {
            line++;
            orders.push_back(move(Order(row)));
        }
    }

    void OrderManager::print() {
       cout << " ________________________________________________________________________________________________________ " << endl
            << "|                                 OrderList Ranged Based for Loop                                        |" << endl
            << "|--------------------------------------------------------------------------------------------------------|" << endl
            << "| Customer Name |   Product Name  |                             Items                                    |" << endl
            << "|---------------|-----------------|----------------------------------------------------------------------| "<< endl;

        for (auto o : orders) {
         
            o.print();
             cout << endl;
        }

       cout << "|--------------------------------------------------------------------------------------------------------|" << endl
            << "|                                       End of ranged based for loop                                     |" << endl
            << "|________________________________________________________________________________________________________|" << endl
            << endl;
    }
    void OrderManager::graph(string file)
    {
        ofstream os;
        string gvFile = file + ".gv";
        string pngFile = gvFile;
        os.open(gvFile);

        os << "digraph order" << " {" << endl;

        for (auto order : orders)
            order.graph(os);

        os << "}";
        os.close();

        string cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe -Tpng " + gvFile + " > " + pngFile + ".png";
       
        system(cmd.c_str()); //execute graphiz command 
    }

}//END namespace ms3