/* OOP345-w5
File: Notifications.h | Date:11/03/16 | Author: Marco Beltempo |
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once
#include <iostream>
#include <vector>

#include "Message.h"

namespace w5 {
    class Notifications
    {

    private:
        int count;
        vector <Message> message_manager;

    public:
        Notifications() { count = 0; message_manager.clear(); }
        Notifications(const Notifications& rhs) : Notifications() {
        message_manager = rhs.message_manager;  }
        Notifications& operator=(const Notifications& rhs);
        Notifications(Notifications&& rhs);
        Notifications&& operator=(Notifications&& rhs);
        ~Notifications();
        void operator+=(const Message& rhs) { message_manager.push_back(rhs); }
        void display(ostream& os) const;
    };
}//w5