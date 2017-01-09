/* OOP345-w5
File: Message.h | Date:11/03/16 | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once
#include <fstream>
#include <iostream>

using namespace std;

namespace w5 {

    class Message {

    private:
        string username_;
        string reply_to_;
        string message_;

    public:
        //Message();
        Message(ifstream& in, char c);
        bool empty() const { return username_.empty() || message_.empty(); }
        void display(ostream& os) const;
    };
}//w5