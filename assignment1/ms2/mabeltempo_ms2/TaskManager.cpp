/* OOP345-Assignment 1 - MS2

File: TaskManager.cpp | Version: MS2.0.1 | Date: 11/13/16 | Author: Marco Beltempo |
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

#include "TaskManager.h"

using namespace std;

namespace ms2 {

    TaskManager::TaskManager(vector<vector<string>>& task) {
        int line = 0;
        for (auto& row : task) {
            line++;
            tasks.push_back(move(Task(row)));
        }
    }

     void TaskManager::print() {
       cout << " ________________________________________________________________________" << endl
            << "|                     Task List Ranged based for Loop                    |" << endl
            << "|------------------------------------------------------------------------|" << endl
            << "| Slot |        Task         |        Passed       |        Failed       |" << endl
            << "|------|---------------------|---------------------|---------------------|" << endl;
  
            for (auto t : tasks) {
                t.print();
            }
        
           cout << "|------------------------------------------------------------------------|" << endl
                << "|                      End of ranged based for loop                      |" << endl
                << "|________________________________________________________________________|" << endl
                << endl;
    }

}//END namespace ms2