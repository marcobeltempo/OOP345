/* OOP345-Assignment 1 - MS3

File: Task.h | Version: MS2.0.3 | Date: 11/06/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095

Revision History
 ___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/06/16 Defined a csvReader, indicies_print, rangedBase_print, iterator_print  |
|                    prototypes.                                                            |
|M.Beltempo 11/18/16 Declared the Task class along with member funcitons and variables      |
|___________________________________________________________________________________________|
*/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include"Util.h"
using namespace std;

namespace ms3 {
    
    class Task {

    private:
        string name_, slots_ , passed_, failed_;

    public:
      
        Task(vector <string> & csv);
        void print();
        void graph(ostream& os);
    };

}//END namespace ms3