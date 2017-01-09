/* OOP345-w
File: Product.cpp | Date: 11/17/16 | Author: Marco Beltempo
Email mabeltempo@myseneca.ca | SID: 031028095 */

#include <iomanip>
#include "Product.h"
#include "TaxableProduct.h"

using namespace std;

namespace w7 {

    iProduct* readProduct(std::ifstream& fs) {

        iProduct *product = nullptr;
        int num;
        double cost;
        char eol;

        fs >> num >> cost;
        eol = fs.get();

        if (eol == ' ') {
            fs >> eol;

            if (eol == 'H') {
                TaxableProduct* tempProduct = new TaxableProduct(num, cost, HST);
                product = tempProduct;
            }

            else if (eol == 'P') {

                TaxableProduct* tempProduct = new TaxableProduct(num, cost, PST);
                product = tempProduct;
            }
        }

        else {
            Product* tempProduct = new Product(num, cost);
            product = tempProduct;
        }

        return product;
    }

    std::ostream& operator<<(std::ostream& os, const iProduct* p) {

        p->display(os);
        return os;
    }

    void Product::display(std::ostream& os) const {
        os << setw(10) << num_ << right << setw(10) << std::fixed << std::setprecision(2)
            << Product::getCharge();
    }

}// END namespace w7