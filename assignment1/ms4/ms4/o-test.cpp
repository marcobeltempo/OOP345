/* OOP345-Assignment 1 - MS4

File: o-test.cpp | Version: MS4.0.3 | Date: 11/06/16 | Author: Marco Beltempo |
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

#include "o.h"

using namespace ms4;

int main(int argc, char** argv) {

    if (argc != 3) {
        cerr << "You must provide 2 arguments." << endl
            << "Command Line: 'orderfile' 'taskfile' " << endl;
        return 1;
    }
    else {
        cout << "Processing file..." << endl << endl;
    }
    cout << "Order File: " << argv[1] << endl
         << "Field Delimiter: " << argv[2][0] << endl
         << endl;

    vector<vector<string>> order_csv;
    csvReader(argv[1], argv[2][0], order_csv);
    OrderManager om = OrderManager(order_csv);
    om.print();
    om.graph(argv[1]);
    om.getOrderList();

    system("pause");
    return 0;
}