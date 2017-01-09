/* OOP345-w10
File: SecureData.cpp | Date: 12/14/16  | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"
#include <thread>

namespace w10 {

    void converter(char* t, char key, int n, const Cryptor& c) {
        for (int i = 0; i < n; i++)
            t[i] = c(t[i], key);
    }

    SecureData::SecureData(const char* file, char key) {
        // open text file
        std::fstream input(file, std::ios::in);
        if (!input)
            throw std::string("\n***Failed to open file ") +
            std::string(file) + std::string(" ***\n");

        // copy from file into memory
        nbytes = 0;
        input >> std::noskipws;
        while (input.good()) {
            char c;
            input >> c;
            nbytes++;
        }
        nbytes--;
        input.clear();
        input.seekg(0, std::ios::beg);
        text = new char[nbytes + 1];

        int i = 0;
        while (input.good())
            input >> text[i++];
        text[--i] = '\0';
        std::cout << "\n" << nbytes << " bytes copied from text "
            << file << " into memory (null byte added)\n";
        encoded = false;

        // encode using key
        code(key);
        std::cout << "Data encrypted in memory\n";
    }

    SecureData::~SecureData() {
        delete[] text;
    }

    void SecureData::display(std::ostream& os) const {
        if (text && !encoded)
            os << text << std::endl;
        else if (encoded)
            throw std::string("\n***Data is encoded***\n");
        else
            throw std::string("\n***No data stored***\n");
    }

    void SecureData::code(char key) {
        std::thread t1(converter, text, key, nbytes, Cryptor());

        t1.join();
        encoded = !encoded;
    }

    void SecureData::backup(const char* file) {
        if (!text)
            throw std::string("\n***No data stored***\n");
        else if (!encoded)
            throw std::string("\n***Data is not encoded***\n");
        else {

            std::ofstream myfile;
            myfile.open(file);
            myfile << text;
            myfile.close();
        }
    }

    void SecureData::restore(const char* file, char key) {

        std::ifstream is(file, std::ios::in);

        nbytes = 0;
        is >> std::noskipws;
        while (is.good()) {
            char c;
            is >> c;
            nbytes++;
        }
        nbytes--;
        is.clear();
        is.seekg(0, std::ios::beg);
        text = new char[nbytes + 1];

        int i = 0;
        while (is.good())
            is >> text[i++];
        text[--i] = '\0';

        std::cout << "\n" << nbytes + 1 << " bytes copied from binary file "
            << file << " into memory (null byte included)\n";
        encoded = true;

        // decode using key
        code(key);
        std::cout << "Data decrypted in memory\n\n";

        is.close();
    }

    std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
        sd.display(os);
        return os;
    }
}