/* OOP345-Assignment 1 - MS2

File: TaskManager.h | Version: MS2.0.1 | Date: 11/13/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
|-------------------------------------------------------------------------------------------|
|M.Beltempo 11/13/16 Defined TaskManager functions                                          |
|M.Beltempo 11/18/16 Revised constructor and removed unecessary functions.                  |
|                    Declared the print() function.                                         |
|___________________________________________________________________________________________| */
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Task.h"

using namespace std;
namespace ms2 {

    class TaskManager {
    private:
        vector<Task> tasks;

    public:
        TaskManager(vector<vector<string> >& task);
        void print();
    };

}  // END NAMESPACE MS2