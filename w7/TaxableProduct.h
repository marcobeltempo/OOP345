/* OOP345-w7
File: TaxableProduct.h | Date: 11/17/16 | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */

#pragma once

#include "Product.h"
#define HST 0.13
#define PST 0.08

namespace w7 {

    class TaxableProduct : public Product {

    private:
        double tax;

    public:
        TaxableProduct(int n, double c, double t) : Product(n, c), tax(t) {}
        double getCharge() const { return Product::getCharge() * (tax); } //return charge w/ tax

        void display(ostream& os) const {
            Product::display(os);
            os << (tax == HST ? " HST" : " PST");
        }
    };

}// END namespace w7