#pragma once
#include "DenseMatrix.hpp"

namespace ms {

template<typename T>
class SquareMatrix : public DenseMatrix<T> {
public:
    explicit SquareMatrix(size_t size, const T& value = T{})
        : DenseMatrix<T>(size, size, value) {}

    size_t size() const { return this->rows(); }
};

} // namespace ms
