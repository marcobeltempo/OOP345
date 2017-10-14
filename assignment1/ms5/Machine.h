/* OOP345-Assignment 1 - MS5
File: Machine.h | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include <iostream>
#include <queue>

#include "t.h"
#include "Job.h"

namespace ms5 {

    class Machine : public Task {

    private: int inEdges_;
             std::queue < Job > inQueue;
             bool install_;
             bool remove_;

    public: Machine() : inEdges_(0) {}
            Machine(Task * t) : Task(*t),
                inEdges_(0) {}

            bool isSource() {
                return inEdges_ == 0;
            }
            bool isSink() {
                return getPassed().empty();
            }
            bool isSingelton() {
                return isSource() && isSink();
            }
            bool getInstall() {
                return install_;
            }
            bool getRemove() {
                return remove_;
            }
            void incoming() {
                inEdges_++;
            }
            size_t inQueueSize() {
                return inQueue.size();
            }
            void newJob(Job j) {
                inQueue.push(std::move(j));
            }

            Job getJob() {

                Job j = std::move(inQueue.front());
                inQueue.pop();
                return j;
            }
    
    };

} //END namespace ms5