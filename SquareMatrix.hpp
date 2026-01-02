#pragma once
#include "DenseMatrix.hpp"

namespace ms{
template<typename T>
class SquareMatrix : public DenseMatrix<T>{
public:
    explicit SquareMatrix(size_t num, const T& val) : DenseMatrix(num, num, val) {}

     size_t size() const { return this->rows(); }
};
}