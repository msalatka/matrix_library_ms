#pragma once
#include <vector>
#include <stdexcept>
#include "Matrix.hpp"
namespace ms {

template <typename T>
class DenseMatrix : public Matrix {
private:
    size_t m_rows;
    size_t m_columns;
    std::vector<T> m_data;
public:
    DenseMatrix() : m_rows(0), m_columns(0) {}
    DenseMatrix(size_t rows, size_t columns) : m_rows(rows), m_columns(columns), m_data(rows * columns){
        if (rows == 0 || columns == 0){
            throw std::invalid_argument("Matrix dimensions must be greater than zero!");
        }
    }
    DenseMatrix(size_t rows, size_t columns, const T& value) :  m_rows(rows), m_columns(columns), m_data(rows * columns, value) {
        std::fill(m_data.begin(), m_data.end(), value);
    }

    T& operator()(size_t r, size_t c) {
    if (r >= m_rows || c >= m_columns) {
        throw std::out_of_range("Matrix index out of range");
    }
    return m_data[r * m_columns + c];
    }
    const T& operator()(size_t r, size_t c) const {
    if (r >= m_rows || c >= m_columns) {
        throw std::out_of_range("Matrix index out of range");
    }
    return m_data[r * m_columns + c];
}
friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (size_t r = 0; r < matrix.m_rows; ++r) {
        for (size_t c = 0; c < matrix.m_columns; ++c) {
            os << matrix(r, c);
            if (c + 1 < matrix.m_columns)
                os << " ";
        }
        os << '\n';
    }
    return os;
}
    //gettery, settery
};

} // namespace ms