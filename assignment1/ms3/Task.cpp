/* OOP345-Assignment 1 - MS3

File: Task.cpp | Version: MS2.0.3 | Date: 11/06/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
 ___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/06/16 Defined a csvReader function along with a indicies, range base for,    |
|                    and conventional print functions.                                      |
|                    prototypes.                                                            |
|M.Beltempo 11/18/16 Defined the Taskconstructor                                            |
|M.Beltempo 11/23/16 Revised validation on initiation of Task object                        |
|___________________________________________________________________________________________|*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Task.h"

namespace ms3 {

    Task::Task(vector<string> &csv) : slots_("1"){
        switch (csv.size())   {
        case 4:
            if (is_nameValid(csv[3])) {
                failed_ = csv[3];
            }
            else {
                cout << endl << "ERROR: Assinging failed task name." << endl;
              
            }

        case 3:
            if (is_nameValid(csv[2])) {
                passed_ = csv[2];
            }
            else {
                cout << endl << "ERROR: Assinging failed passed task name." << endl;
               
            }
        case 2:
            if (is_slotValid(csv[1])) {
                slots_ = csv[1];
            }
            else {
                cout << endl << "ERROR: Assinging slot." << endl;
            
            }
        case 1:
            if (is_nameValid(csv[0])) {
                name_ = csv[0];
            }
            else {
                cout << endl << "ERROR: Assinging task name." << endl;
                break;
            }
            break;
        default:
            cerr << "Error: Searching for 1-4 Task fields." << endl;
            break;
        }
    }

    void Task::print() {
        cout << left << "|  " << setw(4) << slots_ << "| " << setw(20) << name_
            << "| " << setw(20) << passed_ << "| " << setw(20) << failed_ << setw(20)
            << "|" << endl;
    }
    void Task::graph(ostream& os) {
        if (!passed_.empty())
            os << '"' << name_ << '"' << "->" << '"' << passed_ << '"' << " [color=green];" << std::endl;
        if (!failed_.empty())
            os << '"' << name_ << '"' << "->" << '"' << failed_ << '"' << " [color=red];" << std::endl;


        if (passed_.empty() && failed_.empty())
            os << '"' << name_ << '"' << " [shape=box];" << std::endl;
    }
}  // END namespace ms3