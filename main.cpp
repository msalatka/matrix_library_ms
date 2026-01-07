#include <iostream>
#include "DenseMatrix.hpp"
#include "SquareMatrix.hpp"  
int main() {
    ms::DenseMatrix<char> m(2,2,'a');
    ms::SquareMatrix<int> n(10,1);
    std::cout << n << std::endl;

}