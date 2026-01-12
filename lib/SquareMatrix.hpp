#pragma once
#include "Matrix.hpp"

namespace ms {

/**
 * @class SquareMatrix
 * @brief Macierz kwadratowa dziedzicząca po Matrix
 *
 *
 * @tparam T Typ elementów macierzy.
 */
template<typename T>
class SquareMatrix : public Matrix<T> {
public:
    /**
     * @brief Konstruktor tworzący macierz kwadratową wypełnioną wartością.
     * 
     * @param size Rozmiar macierzy (liczba wierszy i kolumn)
     * @param value Wartość początkowa elementów (domyślnie T{})
     */
    explicit SquareMatrix(size_t size, const T& value = T{}) : Matrix<T>(size, size, value) {}

};

} 