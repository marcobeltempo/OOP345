/* OOP345-Assignment 1 - MS4

File: t.cpp | Version: MS4.0.1 | Date: 11/30/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include "t.h"

namespace ms4 {

    /*---Begin Task Class Functions---*/

    Task::Task(vector < string > csv) : slots_("1") {

        switch (csv.size()) {
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
                cout << endl << "ERROR: Assinging passed task name." << endl;
            }
        case 2:
            if (is_slotValid(csv[1])) {
                slots_ = csv[1];
            }
            else {
                cout << "ERROR: Assinging slot." << endl;
            }
        case 1:
            if (is_nameValid(csv[0])) {
                name_ = csv[0];
            }
            else {
                cout << "ERROR: Assinging task name." << endl;
            }
            break;
        default:
            cout << "ERROR: A task requires 1-4 fields." << endl;
        }
    }

    void Task::print() {

        cout << left << "|  " << setw(4) << slots_ << "| " << setw(20) << name_ << "| " << setw(20) << passed_ << "| " << setw(20) << failed_ << setw(20) << "|" << endl;
    }

    void Task::graph(ostream & os) {

        if (!passed_.empty())
            os << '"' << name_ << '"' << "->" << '"' << passed_ << '"' << " [color=green];" << endl;
        if (!failed_.empty())
            os << '"' << name_ << '"' << "->" << '"' << failed_ << '"' << " [color=red];" << endl;

        if (passed_.empty() && failed_.empty())
            os << '"' << name_ << '"' << " [shape=box];" << endl;
    }

    /*-!-End Tak Class Functions-!-*/

    /*---Begin TaskManager Class Functions---*/

    TaskManager::TaskManager(vector < vector < string >> & task) {
        int line = 0;
        for (auto row : task) {
            line++;
            tasks.push_back(move(Task(row)));
        }
    }

    Task* TaskManager::findTask(string & taskName) {

        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i].getTaskName() == taskName) {
                return &tasks[i];
            }
        }
        return nullptr;
    }

    void TaskManager::validTask() {

        cout << endl;

        for (auto t : tasks) {

            if (!t.getPassed().empty() && findTask(t.getPassed()) == nullptr) {
                cout << "Task " + t.getTaskName() + " references a Pass task but " + t.getPassed() + " does't exist." << endl;
            }
            if (!t.getFailed().empty() && findTask(t.getFailed()) == nullptr) {
                cout << "Task " + t.getTaskName() + " references Pass task but " + t.getFailed() + " doesn't exist." << endl;
            }
        }
    }

    void TaskManager::print() {

      cout << setw(73) << setfill('_') << " " << endl
            << "|                     Task List Ranged based for Loop                    |" << endl
            << "|" << setw(72) << setfill('-') << "" << "|" << setfill(' ') << endl
            << "| Slot |        Task         |        Passed       |        Failed       |" << endl
            << "|------|---------------------|---------------------|---------------------|" << endl;

        for (auto t : tasks) {
            t.print();
        }

        cout << "|" << setw(72) << setfill('-') << "" << "|" << endl
             << "|                      End of ranged based for loop                      |" << endl
             << "|" << setw(72) << setfill('_') << "" << "|" << endl
             << endl;

  
    }

    void TaskManager::graph(string file) {

        ofstream tsk;
        string gvFile = file + ".gv";
        string pngFile = gvFile;
        tsk.open(gvFile);

        tsk << "digraph task" << " {" << endl;

        for (auto task : tasks)
            task.graph(tsk);

        tsk << "}";
        tsk.close();

        // linux command
        // string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;

        //windows command
        string cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe -Tpng " + gvFile + " > " + pngFile + ".png";

        system(cmd.c_str()); //execute graphiz command 
    }

    /*-!-End TaskManager Class Functions-!-*/

} // END namespace ms4