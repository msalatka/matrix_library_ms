#pragma once
#include "SquareMatrix.hpp"

namespace ms {

/**
 * @class IdentityMatrix
 * @brief Macierz jednostkowa dziedzicząca po SquareMatrix
 *
 * Każdy element diagonalny ma wartość 1, pozostałe elementy mają wartość 0
 *
 * @param T Typ elementów macierzy - musi być arytmetyczny (std::is_arithmetic_v<T>)
 */
template<typename T>
requires std::is_arithmetic_v<T>
class IdentityMatrix : public SquareMatrix<T> {
public:
    /**
     * @brief Konstruktor tworzący macierz jednostkową o zadanym rozmiarze
     * 
     * @param size Rozmiar macierzy kwadratowej
     */
    explicit IdentityMatrix(size_t size) : SquareMatrix<T>(size, T{})
    {
        for (size_t i = 0; i < this->rows(); ++i)
            (*this)(i, i) = T{1};
    }
};

}
