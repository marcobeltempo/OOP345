/* OOP345-Assignment 1 - MS5

File: t.h | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <vector>
#include <string>

#include"Util.h"

namespace ms5 {

    class Task {

    private:
        std::string name_, slots_, passed_, failed_;

    public:
        Task() { }
        Task(std::vector <std::string>  csv);
        void print();
        void graph(std::ostream& os);
        std::string& getTaskName() { return name_; }
        std::string& getPassed() { return passed_; }
        std::string& getFailed() { return failed_; }
        std::string& getSlots() { return slots_; }
    };

    class TaskManager {

    private:
        std::vector<Task> tasks;

    public:
        TaskManager(std::vector<std::vector<std::string> >& task);
        void print();
        void graph(std::string file);
        void validTask();
        size_t size() { return tasks.size(); }
        Task* findTask(std::string&  taskName);
        Task* getTask(std::size_t t) { return &tasks[t]; }

    };

}//END namespace ms5
