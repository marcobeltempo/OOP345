/* OOP345-w5
File: Notifications.cpp | Date:11/03/16 | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */
#include "Notifications.h"

namespace w5 {

    Notifications& Notifications::operator=(const Notifications& rhs)// - copy assignment operator
    {
        if (this != &rhs) {
            message_manager = rhs.message_manager;
        }
        return *this;
    }

    Notifications::Notifications(Notifications&& rhs) // move constructor
    {
        message_manager = rhs.message_manager;
        rhs.message_manager.clear();
    }

    Notifications&& Notifications::operator=(Notifications&& rhs)// - move assignment operator
    {
        if (this != &rhs) {
            message_manager = move(rhs.message_manager);
        }
        return move(*this);
    }

    //- inserts the Message objects to the os ostream
    void Notifications::display(ostream& os) const
    {
        for (auto m = message_manager.begin(); m != message_manager.end(); m++) {
            m->display(os);
            cout << endl;
        }

    }

    Notifications::~Notifications() //destructor 
    {
        message_manager.clear();
    }

}//w5