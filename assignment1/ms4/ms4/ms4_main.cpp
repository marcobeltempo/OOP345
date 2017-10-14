/* OOP345-Assignment 1 - MS3

File: ms2_main.cpp | Version: MS2.0.3 | Date: 11/06/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
 __________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/06/16 Defined a csvReader function along with a indicies, range base for,    |
|                    and conventional print functions.                                      |
|M.Beltempo 11/13/16 Created a TaskManager object for testing                               |
|M.Beltempo          Displayed testTM with ibject display function                          |
|___________________________________________________________________________________________| */

#include <iostream>
#include <string>
#include <vector>
#include "TaskManager.h"
#include "ItemManager.h"
#include "OrderManager.h"

using namespace ms4;

int main(int argc, char** argv) {

    vector<vector<string>> task_csv;
    vector<vector<string>> item_csv;
    vector<vector<string>> order_csv;

    if (argc != 5) {
        cerr << "You must provide 6 arguments" << endl
            << "Command Line: "
            << "Arg1= Filename Arg2= File Delimiter" << endl;
        return 1;
    }

    string task_filename =argv[1];
    string item_filename =  argv[2];
    string order_filename = argv[3];
    char delim = argv[4][0];

   cout << "Task File: " << argv[1] << endl
        << "Item File: " << argv[2] << endl
        << "Order File: " << argv[3] << endl
        << "Field Delimiter: " << argv[4][0] << endl
        << endl;

    csvReader(task_filename, delim, task_csv);
    csvReader(item_filename, delim, item_csv);
    csvReader(order_filename, delim, order_csv);

    TaskManager tm = TaskManager(task_csv);
    ItemManager im = ItemManager(item_csv);
    OrderManager om = OrderManager(order_csv);

  tm.print();
  im.print();
  om.print();
  tm.graph(task_filename);
  im.graph(item_filename);
  om.graph(order_filename);
  system("pause");
  return 0;
}