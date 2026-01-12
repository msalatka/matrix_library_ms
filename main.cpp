#include <iostream>
#include <iomanip>
#include <chrono>
#include "lib/Matrix.hpp"

int main() {
    std::cout << "Matrix Library\n\n";

    std::cout << "1. PODSTAWOWE MACIERZE:\n";
    
    ms::Matrix<double> A(3, 3, 0.0);
    ms::Matrix<double> B(3, 3, 1.0);
    
    for (int i = 0; i < 3; ++i) {
        A(i, i) = 1.0;
        B(i, (i + 1) % 3) = 2.0;
    }
    
    std::cout << "A:\n" << A << "\n";
    std::cout << "B:\n" << B << "\n";
    std::cout << "A.size() = " << A.size() << "\n\n";

    std::cout << "2. MACIERZE KWADRATOWE:\n";
    
    ms::SquareMatrix<double> S(4, 9.9);
    ms::IdentityMatrix<double> I(3);
    
    std::cout << "S (4x4):\n" << S << "\n";
    std::cout << "I (3x3):\n" << I << "\n\n";

    std::cout << "3. OPERACJE ARYTMETYCZNE:\n";
    
    ms::Matrix<double> C = A * 2.5 + I; 
    ms::Matrix<double> D = B - A;         
    
    std::cout << "C = A * 2.5 + I:\n" << C << "\n";
    std::cout << "D = B - A:\n" << D << "\n\n";

    std::cout << "4. Multiplying Matrixes:\n";
    std::cout << "====================\n";
    
    ms::Matrix<double> E(2, 3, 1.0);
    ms::Matrix<double> F(3, 2, 2.0);
    
    std::cout << "E (2x3):\n" << E;
    std::cout << "F (3x2):\n" << F;
    
    ms::Matrix<double> G = E * F;
    std::cout << "G = E * F (2x2):\n" << G << "\n\n";

    std::cout << "5. Exception Tests:\n";
    
    try {
        ms::Matrix<double> X(0, 5);
    } catch (const std::exception& e) {
        std::cout << "Zero rows: " << e.what() << "\n";
    }
    
    try {
        A(3, 0) = 99.0;
    } catch (const std::exception& e) {
        std::cout << "Out of range: " << e.what() << "\n";
    }
    
    try {
        ms::Matrix<double> G(2, 3);
        ms::Matrix<double> H(2, 2); 
        G * H;
    } catch (const std::exception& e) {
        std::cout << "✓ Bad dimensions: " << e.what() << "\n";
    }
    return 0;
}
