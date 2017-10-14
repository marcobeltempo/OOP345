/* OOP345-Assignment 1 - MS4

File: t.h | Version: MS4.0.1 | Date: 11/30/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

#include"Util.h"

using namespace std;
namespace ms4 {

    class Task {

    private:
        string name_, slots_, passed_, failed_;

    public:
        Task() { }
        Task(vector <string>  csv);
        void print();
        void graph(ostream& os);
        string& getTaskName() { return name_; }
        string& getPassed() { return passed_; }
        string& getFailed() { return failed_; }

    };

    class TaskManager {

    private:
        vector<Task> tasks;

    public:
        TaskManager(vector<vector<string> >& task);
        void print();
        void graph(string file);
        void validTask();
        size_t size() { return tasks.size(); }
        Task* findTask(string&  taskName);
        Task* getTask(size_t t) { return &tasks[t]; }

    };

}//END namespace ms4