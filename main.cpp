#include <iostream>
#include "multitable.hpp"

int main() {
    std::string mulTabStr;
    std::string line;
    while (std::getline(std::cin, line)) {
        mulTabStr += " " + line;
    }

    multitable mulTab(mulTabStr);
    std::cout << mulTab.to_string() << std::endl;

    // (ab)c =?= a(bc)
    for (std::size_t i = 0; i < mulTab.size(); ++i) {
    for (std::size_t j = 0; j < mulTab.size(); ++j) {
    for (std::size_t k = 0; k < mulTab.size(); ++k) {
        std::string a = mulTab[i];
        std::string b = mulTab[j];
        std::string c = mulTab[k];

        std::string ab = mulTab.mult(a, b);
        std::string bc = mulTab.mult(b, c);

        std::string ab_c = mulTab.mult(ab, c);
        std::string a_bc = mulTab.mult(a, bc);
        
        if (ab_c != a_bc) {
            std::cout << "not commutative." << std::endl;
            return 0;
        }
    }}}

    std::cout << "commutative." << std::endl;
    return 0;
}