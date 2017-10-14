/* OOP345-Assignment 1 - MS4

File: iot.cpp | Version: MS4.0.1 | Date: 11/30/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include <time.h>;

#include "i.h"
#include "o.h"
#include "t.h"

using namespace ms4;

int main(int argc, char * * argv) {
    clock_t t1, t2; //checks time on program start
    t1 = clock();
    if (argc != 5) {
        cerr << "You must provide 4 arguments." << endl << "Command Line: 'itemFileName' 'orderFileName 'taskFileName' 'delimiter' " << endl;
        return 1;
    }
    else {
        cout << "Processing files..." << endl << endl;
    }

    char delim = argv[4][0];

    vector < vector < string >> item_csv;
    vector < vector < string >> order_csv;
    vector < vector < string >> task_csv;

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

    cout << "!*********************************ERRORS*********************************! " << endl;
    om.orderItemExist(im);
    im.validItem(tm);

    //return the difference of start time and end time
    t2 = clock();
    float diff((float)t2 - (float)t1);
    cout << "\nProgram succesfully completed in " << diff / CLOCKS_PER_SEC << " seconds.\n";

    system("pause");
    return 0;
}