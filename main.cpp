#include <iostream>
#include "DenseMatrix.hpp"   
int main() {
    try {
        ms::DenseMatrix<int> m(15, 5, 1);

        // zapis
        m(0, 0) = 1;
        m(0, 1) = 2;
        m(0, 2) = 3;
        m(1, 0) = 4;
        m(1, 1) = 5;
        m(1, 2) = 6;

        // odczyt
        std::cout <<  m << std::endl;

        // test const
        const ms::DenseMatrix<int>& cm = m;
        std::cout << "\nConst access cm(1,2) = " << cm(1, 2) << "\n";

        // test wyjątku
        std::cout << "\nTrying out-of-range access...\n";
        std::cout << m(1, 0) << "\n";  // powinien polecieć wyjątek
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}