/* OOP345-Assignment 1 - MS5
File: ms5_main.cpp | Version: MS5.0.1 | Date:12/05/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
//#include <time.h>

#include "i.h"
#include "o.h"
#include "t.h"
#include "Factory.h"

using namespace ms5;

int main(int argc, char * * argv) {

    clock_t t1, t2; //checks time on program start
    t1 = clock();

    if (argc != 5) {
        std::cerr << "You must provide 4 arguments.\n Command Line: 'itemFileName' 'orderFileName 'taskFileName' 'delimiter' \n";
        return 1;
    }
    else {
        std::cout << "Processing files...\n" << std::endl;
    }

    char delim = argv[4][0];

    std::vector < std::vector < std::string >> item_csv;
    std::vector < std::vector < std::string >> order_csv;
    std::vector < std::vector < std::string >> task_csv;

    csvReader(argv[1], delim, item_csv);
    csvReader(argv[2], delim, order_csv);
    csvReader(argv[3], delim, task_csv);

    ItemManager im = ItemManager(item_csv);
    OrderManager om = OrderManager(order_csv);
    TaskManager tm = TaskManager(task_csv);

    im.print();
    om.print();
    tm.print();

    im.graph(argv[1]);
    om.graph(argv[2]);

    tm.graph(argv[3]);
    Factory factory(im, om, tm);

    std::cout << "!*********************************ERRORS*********************************!\n";
 
    om.orderItemExist(im);
    im.validItem(tm);

    //return the difference of start time and end time
    t2 = clock();
    float diff((float)t2 - (float)t1);
    std::cout << "\nProgram succesfully completed in " << diff / CLOCKS_PER_SEC << " seconds.\n";

    return 0;
}