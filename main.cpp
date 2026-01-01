#include <iostream>
#include "Matrix.hpp"   
int main() {
    try {
        ms::Matrix<int> m(2, 3, 0);

        // zapis
        m(0, 0) = 1;
        m(0, 1) = 2;
        m(0, 2) = 3;
        m(1, 0) = 4;
        m(1, 1) = 5;
        m(1, 2) = 6;

        // odczyt
        std::cout << "Matrix m:\n";
        for (size_t r = 0; r < 2; ++r) {
            for (size_t c = 0; c < 3; ++c) {
                std::cout << m(r, c) << " ";
            }
            std::cout << "\n";
        }

        // test const
        const ms::Matrix<int>& cm = m;
        std::cout << "\nConst access cm(1,2) = " << cm(1, 2) << "\n";

        // test wyjątku
        std::cout << "\nTrying out-of-range access...\n";
        std::cout << m(2, 0) << "\n";  // powinien polecieć wyjątek
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}