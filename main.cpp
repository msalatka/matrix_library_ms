#include <iostream>
#include "lib/Matrix.hpp"

int main() {
    ms::DenseMatrix<int> A(3,3,4);
    ms::SquareMatrix<int> B(3,1);

    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;

    auto C = A + B;
    std::cout << "C = A + B:\n" << C;

    auto D = A * 3;
    std::cout << "D = A * 3:\n" << D;

    ms::IdentityMatrix<int> I(3);
    std::cout << "I (identity):\n" << I;

    auto E = I * 5;
    std::cout << "E = I * 5:\n" << E;

    return 0;
}
