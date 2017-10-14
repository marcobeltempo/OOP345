/* OOP345-Assignment 1 - MS5
File: t.cpp | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "t.h"

namespace ms5 {

    /*---Begin Task Class Functions---*/

    Task::Task(std::vector < std::string > csv) : slots_("1") {

        switch (csv.size()) {
        case 4:
            if (is_nameValid(csv[3])) {
                failed_ = csv[3];
            }
            else {
                std::cout << "\nERROR: Assinging failed task name. \n";
            }
        case 3:
            if (is_nameValid(csv[2])) {
                passed_ = csv[2];
            }
            else {
                std::cout << "\nERROR: Assinging passed task name.\n";
            }
        case 2:
            if (is_slotValid(csv[1])) {
                slots_ = csv[1];
            }
            else {
                std::cout << "ERROR: Assinging slot.\n";
            }
        case 1:
            if (is_nameValid(csv[0])) {
                name_ = csv[0];
            }
            else {
                std::cout << "ERROR: Assinging task name.\n";
            }
            break;
        default:
            std::cout << "ERROR: A task requires 1-4 fields.\n";
        }
    }

    void Task::print() {

        std::cout << std::left << "|  " << std::setw(4) << slots_ << "| " << std::setw(20) << name_ << "| " << std::setw(20) << passed_ << "| " << std::setw(20) << failed_ << std::setw(20) << "|" << std::endl;
    }

    void Task::graph(std::ostream & os) {

        if (!passed_.empty())
            os << '"' << name_ << '"' << "->" << '"' << passed_ << '"' << " [color=green];" << std::endl;
        if (!failed_.empty())
            os << '"' << name_ << '"' << "->" << '"' << failed_ << '"' << " [color=red];" << std::endl;

        if (passed_.empty() && failed_.empty())
            os << '"' << name_ << '"' << " [shape=box];" << std::endl;
    }

    /*-!-End Tak Class Functions-!-*/

    /*---Begin TaskManager Class Functions---*/

    TaskManager::TaskManager(std::vector < std::vector < std::string >> & task) {
        int line = 0;
        for (auto row : task) {
            line++;
            tasks.push_back(std::move(Task(row)));
        }
    }

    Task* TaskManager::findTask(std::string& taskName) {

        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i].getTaskName() == taskName) {
                return &tasks[i];
            }
        }
        return nullptr;
    }

    void TaskManager::validTask() {

        std::cout << "\n";

        for (auto t : tasks) {

            if (!t.getPassed().empty() && findTask(t.getPassed()) == nullptr) {
                std::cout << "Task " + t.getTaskName() + " references a Pass task but " + t.getPassed() + " does't exist.\n";
            }
            if (!t.getFailed().empty() && findTask(t.getFailed()) == nullptr) {
                std::cout << "Task " + t.getTaskName() + " references Pass task but " + t.getFailed() + " doesn't exist.\n";
            }
        }
    }

    void TaskManager::print() {

        std::cout << std::setw(72) << std::setfill('_') << "" << std::endl
            << "|                     Task List Ranged based for Loop                    |" << std::endl
            << "|" << std::setw(72) << std::setfill('-') << "" << "|" << std::setfill(' ') <<  std::endl
            << "| Slot |        Task         |        Passed       |        Failed       |" << std::endl
            << "|------|---------------------|---------------------|---------------------|" << std::endl;

        for (auto t : tasks) {
            t.print();
        }

   std::cout << "|" << std::setw(72) << std::setfill('-') << " " << "|" << std::endl
             << "|                      End of ranged based for loop                      |" << std::endl
             << "|" << std::setw(72) << std::setfill('_') << "" << "|" << std::endl
             << std::endl;
    }

    void TaskManager::graph(std::string file) {

        std::ofstream tsk;
        std::string gvFile = file + ".gv";
		std::string pngFile = gvFile + ".png";
        tsk.open(gvFile);

        tsk << "digraph task" << " {" << std::endl;

        for (auto task : tasks)
            task.graph(tsk);

        tsk << "}";
        tsk.close();

        // linux command
        // string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;

        //windows command
        std::string cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe -Tpng " + gvFile + " > " + pngFile + ".png";

        system(cmd.c_str()); //execute graphiz command 
    }

    /*-!-End TaskManager Class Functions-!-*/

} // END namespace ms5
