#pragma once
#include <iostream>

namespace ms {

template<typename Derived, typename T>
class Matrix {
public:
    // CRTP helper
    Derived& derived() { return *static_cast<Derived*>(this); }
    const Derived& derived() const { return *static_cast<const Derived*>(this); }

    // CRTP operators, działają dla wszystkich klas dziedziczących
    Derived operator+(const Derived& other) const {
        check_same_size(other);
        Derived result = derived();
        for (size_t i = 0; i < rows(); ++i)
            for (size_t j = 0; j < columns(); ++j)
                result(i, j) = (*this)(i, j) + other(i, j);
        return result;
    }

    Derived operator-(const Derived& other) const {
        check_same_size(other);
        Derived result = derived();
        for (size_t i = 0; i < rows(); ++i)
            for (size_t j = 0; j < columns(); ++j)
                result(i, j) = (*this)(i, j) - other(i, j);
        return result;
    }

    Derived operator*(const T& scalar) const {
        Derived result = derived();
        for (size_t i = 0; i < rows(); ++i)
            for (size_t j = 0; j < columns(); ++j)
                result(i, j) = (*this)(i, j) * scalar;
        return result;
    }

    friend Derived operator*(const T& scalar, const Matrix& mat) {
        return mat * scalar;
    }

protected:
    void check_same_size(const Derived& other) const {
        if (rows() != other.rows() || columns() != other.columns())
            throw std::invalid_argument("Matrix dimensions must match");
    }

public:
    // te funkcje muszą istnieć w klasie pochodnej
    size_t rows() const { return derived().rows(); }
    size_t columns() const { return derived().columns(); }
    T& operator()(size_t r, size_t c) { return derived()(r,c); }
    const T& operator()(size_t r, size_t c) const { return derived()(r,c); }

    // operator<< działa dla wszystkich klas dziedziczących
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
        for (size_t i = 0; i < mat.rows(); ++i) {
            for (size_t j = 0; j < mat.columns(); ++j) {
                os << mat(i, j);
                if (j + 1 < mat.columns()) os << " ";
            }
            os << '\n';
        }
        return os;
    }
};

} // namespace ms

#include "DenseMatrix.hpp"
#include "SquareMatrix.hpp"
#include "IdentityMatrix.hpp"