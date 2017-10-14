/* OOP345-Assignment 1 - MS1

File CSVReader.cpp
Version MS1.0.1
Date 11/06/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
|M.Beltempo 11/06/16 Defined a csvReader function along with a indicies, range base for,    |
|                    and conventional print functions.                                      |
|___________________________________________________________________________________________|
*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Task.h"

namespace ms1 {



    //Trim any leading charecters/whitespace
    string & trim(string & s, char trimChar = ' ');
    string & trim(string & s, char trimChar) {
        while (!s.empty() && s[0] == trimChar)
            s.erase(0, 1);

        while (!s.empty() && s[s.size() - 1] == trimChar)
            s.erase(s.size() - 1, 1);

        return s;
    }

    void csvReader(char * filename, char delim, vector <vector <string> > & file) {

        ifstream is(filename);
        if (is) {
            string row;
            vector < string > fields;

            while (getline(is, row)) {
                auto cr = row.find('\r');
                if (cr != string::npos)
                    row.erase(cr, 1);

                string col;
                for (size_t i = 0; i < row.size(); i++) {

                    if (row[i] == '"') {
                        col += row[i]; // copy 1st "
                        for (i++; i < row.size(); i++) {
                            col += row[i];
                            if (row[i] == '"') // found 2nd "
                                break;
                        }
                    }
                    else

                        if (row[i] != delim) {
                            col += row[i];
                        }
                        else {
                            trim(col);
                            fields.push_back(col);
                            col.clear();
                        }
                }
                trim(col);
                fields.push_back(col);
                file.push_back(fields);
                fields.clear();
            }
            is.close();
        }
        else {
            cerr << "Error: Cannot Open File " << filename << "\n";
        }
    }

    void rangedBase_print(const vector <vector <string> > & file) {
            
        int row_num = 0;

        cout << " ______________________________________________ " << endl
             << "|       Entering the ranged based for loop     |" << endl
             << "|----------------------------------------------|" << endl;


        for (auto const & row : file) {           
            for (auto const & col : row) {
               
                cout << left << "|  " << setw(4) << row_num << "| " << setw(38) << col;
            }
            cout << right << "|" << endl;
            ++row_num;
        }
       cout << "|----------------------------------------------|" << endl
            << "|          End of ranged based for loop        |" << endl
            << "|______________________________________________|" << endl
            << endl;
    }

    void indicies_print(const vector < vector <string> > & file) {

        vector <vector <string> > ::const_iterator row;
        vector <string> ::const_iterator col;
        int row_num = 0;

        cout << " ______________________________________________ " << endl
             << "|           Entering the indicies loop         |" << endl
             << "|----------------------------------------------|" << endl;

        for (row = file.begin(); row != file.end(); ++row) {      
            for (col = row->begin(); col != row->end(); ++col) {
                     
                cout << left << "|  " << setw(4) << row_num << "| " << setw(38) << (*col);
            }
            cout << right << "|" << endl;
            ++row_num;
        }
       cout << "|----------------------------------------------|" << endl
            << "|             End of indicies loop             |" << endl
            << "|______________________________________________|" << endl
            << endl;
    }

    void conventional_print(const vector < vector <string> > & file) {

        cout << " ______________________________________________ " << endl;
        cout << "|        Entering the conventional loop        |" << endl;
        cout << "|----------------------------------------------|" << endl;

        for (size_t row = 0; row < file.size(); ++row) {
            for (size_t col = 0; col < file[row].size(); ++col) {
                                
                cout << left << "|  " <<setw(4) << row << "| " << setw(38) << file[row][col];
            }
            cout << right <<  "|"   << endl;
        }
        cout << "|----------------------------------------------|" << endl
             << "|           End of conventional loop           |" << endl 
             << "|______________________________________________|" << endl
             << endl;

    }

}//END Namespace MS1