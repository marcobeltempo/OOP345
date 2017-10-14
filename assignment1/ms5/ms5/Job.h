/* OOP345-Assignment 1 - MS5

File: Job.h | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include "o.h"

namespace ms5 {

    class Job : public Order {

    private: std::vector < bool > installed;

    public: Job() {};
            Job(Order * o) : Order(*o) {
                installed.resize(size());
                for (size_t i = 0; i < size(); i++) {
                    //intialize entire vector to false
                    installed[i] = false;
                }
            }
            bool Installed(size_t i) {
                return installed[i];
            }

            void Installed(size_t i, bool value) {
                installed[i] = value;
            }

    };
}