#pragma once
#include <vector>
#include <stdexcept>
#include "Matrix.hpp"
namespace ms {
// size_t jest unsigned więc brak ujemnych indeksów
template <typename T>
class DenseMatrix : public Matrix<T> {
private:
    size_t m_rows;
    size_t m_columns;
    std::vector<T> m_data;
protected:
    DenseMatrix() {}
public:

    size_t rows() const override {
        return m_rows;
    }
    size_t columns() const override {
        return m_columns;
    }
/*          KONSTRUKTORY        */

    //DenseMatrix() = delete;

    DenseMatrix(size_t rows, size_t columns, const T& value) :  m_rows(rows), m_columns(columns), m_data(rows * columns, value) {
        if (rows == 0 || columns == 0){
            throw std::invalid_argument("Matrix dimensions must be greater than zero!");
        }
    }

    DenseMatrix(size_t rows, size_t columns) : DenseMatrix(rows,columns,T{}) {}

/*          PRZECIĄŻENIA OPERATORÓW         */

    T& operator()(size_t row, size_t column) {
        if (row >= m_rows || column >= m_columns) {
            throw std::out_of_range("Matrix index out of range");
        }
        return m_data[row * m_columns + column];
    }

    const T& operator()(size_t row, size_t column) const {
        if (row >= m_rows || column >= m_columns) {
            throw std::out_of_range("Matrix index out of range");
        }
        return m_data[row * m_columns + column];
    }

    friend std::ostream& operator<<(std::ostream& os, const DenseMatrix<T>& matrix) {
        for (size_t row = 0; row < matrix.m_rows; ++row) {
            for (size_t column = 0; column < matrix.m_columns; ++column) {
                os << matrix(row, column);
                if (column + 1 < matrix.m_columns)
                    os << " ";
            }
            os << '\n';
        }
        return os;
    }
};

} 