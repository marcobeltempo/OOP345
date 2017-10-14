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

#include "TaskManager.h"

using namespace std;

namespace ms3 {

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

     void TaskManager::graph(string file)
     {
         ofstream tsk;
         string gvFile = file + ".gv";
         string pngFile = gvFile;
         tsk.open(gvFile);

         tsk << "digraph task" << " {" << endl;

         for (auto task : tasks)
             task.graph(tsk);

         tsk << "}";
         tsk.close();

         // uncomment when on linux
         //string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;
         // uncomment when on windows

         //string cmd = "start C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe Tpng graphs.png"; system(cmd.c_str()); 

         //   string cmd = "C:/\"Program Files (x86)\"/graphviz-2.38/bin/dot.exe -Tpng " + gvFile + " > " + gvFile + ".png";
         string cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe -Tpng " + gvFile + " > " + pngFile + ".png";

         system(cmd.c_str());
     }
}//END namespace ms3