#include <iostream>
#include "DenseMatrix.hpp"   
int main() {
    ms::DenseMatrix<char> m(2,2,'a');
    std::cout << m << std::endl;

}