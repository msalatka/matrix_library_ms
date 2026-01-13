#include <iostream>
#include "lib/Matrix.hpp"

int main() {
    std::cout << "Matrix Library demo\n\n";

    // 1. Tworzenie ms::Matrix<>
    ms::Matrix<double> A(3, 3, 0.0);
    ms::Matrix<double> B(3, 3, 1.0);

    for (size_t i = 0; i < 3; ++i) {
        A(i, i) = 1.0;
        B(i, (i + 1) % 3) = 2.0;
    }

    std::cout << "Matrix A:\n" << A << "\n";
    std::cout << "Matrix B:\n" << B << "\n";

    // 2. Macierze ms::SquareMatrix<>, ms::IdentityMatrix<>
    ms::SquareMatrix<double> S(4, 9.9);
    ms::IdentityMatrix<double> I(3);

    std::cout << "Square matrix S:\n" << S << "\n";
    std::cout << "Identity matrix I:\n" << I << "\n";

    // 3. Operacje arytmetyczne
    ms::Matrix<double> C = A * 2.5 + I;
    ms::Matrix<double> D = B - A;

    std::cout << "C = A * 2.5 + I:\n" << C << "\n";
    std::cout << "D = B - A:\n" << D << "\n";

    // 4. Mnożenie macierzy
    ms::Matrix<double> E(2, 3, 1.0);
    ms::Matrix<double> F(3, 2, 2.0);

    ms::Matrix<double> G = E * F;
    std::cout << "E * F:\n" << G << "\n";

    // 5. Obsługa wyjątków
    try {
        ms::Matrix<double> invalid(0, 3);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    try {
        A(5, 0) = 1.0;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
