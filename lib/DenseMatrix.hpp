#pragma once
#include "Matrix.hpp"
#include <vector>
#include <stdexcept>

namespace ms {

template<typename T>
class DenseMatrix : public Matrix<DenseMatrix<T>, T> {
protected:
    size_t m_rows;
    size_t m_columns;
    std::vector<T> m_data;

public:
    DenseMatrix() = delete;

    DenseMatrix(size_t rows, size_t columns, const T& value = T{})
        : m_rows(rows), m_columns(columns), m_data(rows * columns, value)
    {
        if (rows == 0 || columns == 0)
            throw std::invalid_argument("Matrix dimensions must be > 0");
    }

    size_t rows() const { return m_rows; }
    size_t columns() const { return m_columns; }

    T& operator()(size_t r, size_t c) {
        return m_data[r * m_columns + c];
    }

    const T& operator()(size_t r, size_t c) const {
        return m_data[r * m_columns + c];
    }
};

} // namespace ms
