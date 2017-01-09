/* OOP345-w7
File: Product.h | Date: 11/17/16  | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include "iProduct.h"

namespace w7 {

    class Product : public iProduct {

    private:
        int num_;
        double cost_;

    public:
        Product(int num, double cost) : num_(num), cost_(cost) { }
        double getCharge() const { return cost_; }
        void display(ostream&) const;
    };

}// END namespace w7