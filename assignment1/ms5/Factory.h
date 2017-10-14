/* OOP345-Assignment 1 - MS5
File: Factory.h | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include "i.h"
#include "o.h"
#include "t.h"
#include "Machine.h"

namespace ms5 {

    class Factory {

    private:
        std::vector < Machine > machines;

    public:

        Factory(ItemManager & im, OrderManager & om, TaskManager & tm) {

            srand(time(0));

            for (size_t i = 0; i < tm.size(); i++) {

                //Loading the machines
                machines.push_back(std::move(Machine(tm.getTask(i))));
            }

            //Lambda function that searches for the current machine
            auto FindMachine = [&](std::string n) -> Machine *{
                for (size_t i = 0; i < machines.size(); i++) {
                    if (machines[i].getTaskName() == n) {
                        return &machines[i];
                        return nullptr;
                    }
                }
            };

            /* If the task has pass or fail edges are loaded into the queue. */

            for (auto m : machines) {
                std::string passed = m.getPassed();
                std::string failed = m.getFailed();
                if (!passed.empty()) {
                    FindMachine(passed)->incoming();
                }
                if (!failed.empty()) {
                    FindMachine(failed)->incoming();
                }
            }

            /* Finding source nodes */
            int source = -1;
            for (size_t m = 0; m < machines.size(); m++) {

                std::cout << "\n" << m << ": " << machines[m].getTaskName() << " ";
                if (machines[m].isSingelton()) {
                    std::cout << " is a Singelton ";
                }
                else {
                    if (machines[m].isSource()) {
                        std::cout << " is a Source ";
                    }
                    if (source == -1) {
                        source = m;
                    }
                    else {
                        std::cout << "contains multiple sources. Revise the data files.";
                    }
                }
                    //Checks for empty task pass
                    if (machines[m].isSink()) {
                        std::cout << " is a Sink ";
                    }
                }
            

            //Loads all jobs into the queue

            for (size_t o = 0; o < om.size(); o++) {
                machines[source].newJob(Job(om.getOrder(o)));
            }
         
            int time = 0;

            while (true) {

                std::cout << "\nTime elapsed: " << time << std::endl;

                bool done = true;
                for (auto m : machines) {
                    if (m.inQueueSize()) {
                        done = false;
                        break; //Break to bottom of machine loop
                    }
                }

                if (done) {

                    std::cout << "\n Jobs Complete. \n";
                    break;
                }
                //Find incomplete jobs
                for (auto & m : machines) { //Start machine loop
                    if (m.inQueueSize() == 0) {
                        continue;
                    }

                    Job j = m.getJob();

              std::cout << "\nCustomer: " << j.getCustomerName() << std::endl
                        << "Product: " << j.getProductName() << std::endl
                        << "Task Status: " << m.getTaskName() << std::endl << std::endl;

                    if (m.isSink()) {
                        std::cout << "Job arrived at " << m.getTaskName() << " a sink and has nothing to do.\nJob exiting system.\n";
                        done = false;
                        break;  
                    }

                    bool worked = false;

                    if (m.getInstall()) {
                        std::cout << m.getTaskName() << " is an installer.\n";

                        for (size_t i = 0; i < j.size(); i++) {
                            if (j.Installed(i)) {
                                continue;
                            }
                            std::string itemName = j.getOrderItemList(i);
                            Item * itemPtr = im.findItem(itemName);

                            if (m.getTaskName() == itemPtr -> getInstaller()) {
                                j.Installed(i, true);
                                worked = true;
                                time += stoi(m.getSlots());
                                std::cout << m.getTaskName() << " installed " << itemName << ".\n";
                                break;
                            }
                        }
                    }
                    if (m.getRemove()) {
                        std::cout << m.getTaskName() << " is a remover.\n";

                        for (int i = j.size() - 1; i > 0; --i) {
                            if (!j.Installed(i)) {
                                continue;
                            }
                            std::string itemName = j.getOrderItemList(i);
                            Item * itemPtr = im.findItem(itemName);

                            if (m.getTaskName() == itemPtr -> getRemover()) {
                                j.Installed(i, false); // 
                                worked = true; 
                                time += stoi(m.getSlots());

                                std::cout << m.getTaskName() << " removed " << itemName << ".\n";
                                break;
                            }
                        }
                    }
                    //Lambda function moves the current Job machine to the passed machine queue
                    auto MovePass = [&] {
                        std::string pass = m.getPassed();
                        std::cout << "Moving job to pass machine " << pass << ".\n";
                        for (auto & m2 : machines) {

                            if (m2.getTaskName() == pass) {
                                m2.newJob(j);
                                break;
                            }
                        }
                    };

                    //Lambda function moves current Job to machine failed queue
                    auto MoveFail = [&] {
                        std::string fail = m.getFailed();
                        std::cout << "Moving job to fail machine " << fail << ".\n";
                        for (auto & m2 : machines) {

                            if (m2.getTaskName() == fail) {
                                m2.newJob(j);
                                break;
                            }
                        }
                    };

                    if (!worked || m.getFailed().empty() | rand() & 1 ) {//flip a coin *rand()
                        MovePass();
                        continue;
                    }
                    else {
                        MoveFail();
                        continue;
                    }
                } //end of machine loop
            } //end of time loop
            std::cout << "Viable Factory Simulation is Complete! \n" << std::endl;
        }

    }; //end of factory class
}//END namespace ms5