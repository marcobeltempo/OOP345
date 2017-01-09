// Workshop 8 - STL Algorithms
 // w8.cpp

 #include <iostream>
 #include <iomanip>
 #include <fstream>
 #include <string>
 #include "DataTable.h"

 const int FW = 7;
 const int ND = 2;

 int main(int argc, char** argv) {
     cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         cout << argv[i] << ' ';
     }
     cout << endl;
     if (argc != 2 && argc != 3) {
         cerr << argv[0] << ": incorrect number of arguments\n"; 
         cerr << "Usage: " << argv[0] << " file_name [p]\n";
         return 1;
     }
     ifstream dataFile(argv[1]);
     if (!dataFile) {
         cerr << "\n***Failed to open file " << argv[1] << "***\n";
         return 2;
     }

     try {
         w8::DataTable<float> data(dataFile, FW, ND);
         if (argc == 3) {
             cout << "\nData Values\n===========\n";
             cout << data << endl;
         }
         float m, c;
         data.regression(m, c);
         cout << "\nStatistics\n==========\n";
         cout << fixed << setprecision(ND);
         cout << "y mean    = " << setw(FW) << data.mean() <<
          "\ny sigma   = " << setw(FW) << data.sigma() <<
          "\ny median  = " << setw(FW) << data.median() << endl; 
         cout << "slope     = " << setw(FW) << m <<
          "\nintercept = " << setw(FW) << c << endl;
     }
     catch (string& msg) {
         cout << msg << endl;
         return 3;
     }

     cout << "\nPress any key to continue ... ";
     cin.get();
 }