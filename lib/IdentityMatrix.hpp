#pragma once
#include "SquareMatrix.hpp"

namespace ms {

template<typename T>
class IdentityMatrix : public SquareMatrix<T> {
public:
    explicit IdentityMatrix(size_t size) : SquareMatrix<T>(size) {
        for (size_t i = 0; i < this->rows(); ++i)
            (*this)(i,i) = T{1};
    }
};

} // namespace ms
