#pragma once

#include <cstddef>
#include <vector>
#include <stdexcept>
#include <ostream>

namespace ms {

/**
 * @class Matrix
 * @brief Klasa reprezentująca macierz z pełnym wsparciem operatorów
 *
 * Klasa umożliwia dostęp do elementów przez operator() oraz wspiera operacje arytmetyczne: dodawanie, odejmowanie, mnożenie przez skalar oraz wypisywanie macierzy do strumienia
 * @tparam T Typ elementów macierzy
 */
template<typename T>
class Matrix {
private:
    size_t m_rows;
    size_t m_columns;
    std::vector<T> m_data;

    /**
     * @brief Sprawdzenie równości wymiarów macierzy
     *
     * @param other Macierz którą porównujemy
     *
     * @throw std::invalid_argument jeśli wymiary się różnią
     */
    void check_same_size(const Matrix& other) const {
        if (m_rows != other.m_rows || m_columns != other.m_columns) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
    }

public:
    /**
     * @brief Konstruktor tworzący macierz o zadanych wymiarach i opcjonalnej wartości początkowej
     * 
     * @param rows Liczba wierszy (musi być > 0)
     * @param columns Liczba kolumn (musi być > 0)
     * @param value Wartość początkowa elementów (domyślnie T{})
     * 
     * @throw std::invalid_argument jeśli rows lub columns są zerowe
     */
    Matrix(size_t rows, size_t columns, const T& value = T{})
        : m_rows(rows), m_columns(columns), m_data(rows * columns, value) {
        if (rows == 0 || columns == 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than 0");
        }
    }

    /**
     * @brief Getter liczby wierszy macierzy
     *
     * @return Liczba wierszy m_rows
     */
    size_t rows() const { 
        return m_rows; 
    }

    /**
     * @brief Getter liczby kolumn macierzy
     *
     * @return Liczba kolumn m_columns
     */
    size_t columns() const{ 
        return m_columns; 
    }

    /**
    * @brief Zwraca całkowitą liczbę elementów macierzy
    * @return rows() * columns()
    */
    size_t size() const{ 
        return m_rows * m_columns; 
    }

    /**
     * @brief Dostęp do jednego elementu macierzy
     * 
     * @param r Numer wiersza 0 <= rows < rows()
     * @param c Numer kolumny 0 <= columns < columns()
     * @return Referencja do elementu macierzy
     * @throw std::out_of_range jeśli indeks poza zakresem
     */
    T& operator()(size_t rows, size_t columns) {
        if (rows >= m_rows || columns >= m_columns) {
            throw std::out_of_range("Matrix index out of range");
        }
        return m_data[rows * m_columns + columns];
    }

    /**
     * @brief Dostęp do jednego elementu macierzy (const)
     * 
     * @param r Numer wiersza 0 <= r < rows()
     * @param c Numer kolumny 0 <= c < columns()
     * @return Stała referencja do elementu macierzy
     * @throw std::out_of_range jeśli indeks poza zakresem
     */
    const T& operator()(size_t r, size_t c) const {
        if (r >= m_rows || c >= m_columns) {
            throw std::out_of_range("Matrix index out of range");
        }
        return m_data[r * m_columns + c];
    }

    /**
     * @brief Dodawanie dwóch macierzy
     * 
     * @param other Macierz do dodania
     * @return Nowa macierz (this + other)
     * @throw std::invalid_argument jeśli wymiary się różnią
     */
    Matrix operator+(const Matrix& other) const {
        check_same_size(other);
        Matrix result(m_rows, m_columns);
        for (size_t i = 0; i < m_rows; ++i) {
            for (size_t j = 0; j < m_columns; ++j) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
        return result;
    }

    /**
     * @brief Dodawanie macierzy z przypisaniem
     * 
     * @param other Macierz do dodania
     * @return Referencja do macierzy (this)
     * @throw std::invalid_argument jeśli wymiary się różnią
     */
    Matrix& operator+=(const Matrix& other) {
        check_same_size(other);
        for (size_t i = 0; i < m_rows; ++i) {
            for (size_t j = 0; j < m_columns; ++j) {
                (*this)(i, j) += other(i, j);
            }
        }
        return *this;
    }

    /**
     * @brief Odejmowanie dwóch macierzy
     * 
     * @param other Macierz do odjęcia 
     * @return Nowa macierz (this - other)
     * @throw std::invalid_argument jeśli wymiary się różnią
     */
    Matrix operator-(const Matrix& other) const {
        check_same_size(other);
        Matrix result(m_rows, m_columns);
        for (size_t i = 0; i < m_rows; ++i) {
            for (size_t j = 0; j < m_columns; ++j) {
                result(i, j) = (*this)(i, j) - other(i, j);
            }
        }
        return result;
    }

    /**
     * @brief Dodawanie macierzy z przypisaniem
     * 
     * @param other Macierz do odjęcia
     * @return Nowa macierz (this - other)
     * @throw std::invalid_argument jeśli wymiary się różnią
     */
    Matrix& operator-=(const Matrix& other) {
        check_same_size(other);
        for (size_t i = 0; i < m_rows; ++i) {
            for (size_t j = 0; j < m_columns; ++j) {
                (*this)(i, j) -= other(i, j);
            }
        }
        return *this;
    }

    /**
     * @brief Mnożenie macierz * skalar
     * 
     * @param scalar Skalar do pomnożenia
     * @return Nowa macierz (this * skalar)
     */
    Matrix operator*(const T& scalar) const {
        Matrix result(m_rows, m_columns);
        for (size_t i = 0; i < m_rows; ++i) {
            for (size_t j = 0; j < m_columns; ++j) {
                result(i, j) = (*this)(i, j) * scalar;
            }
        }
        return result;
    }

    /**
     * @brief Mnożenie skalar * macierz
     * 
     * @param scalar Skalar
     * @param mat Macierz
     * @return Nowa macierz 
     */
    friend Matrix operator*(const T& scalar, const Matrix& matrix) {
        return matrix * scalar;
    }

    /**
     * @brief Mnożenie dwóch macierzy
     * 
     * @param other Druga macierz musi mieć m_columns == other.rows()
     * @return Nowa macierz this * other
     * @throw std::invalid_argument jeśli wymiary się nie zgadzają
     */
    Matrix operator*(const Matrix& other) const {
        if (m_columns != other.m_rows) {
            throw std::invalid_argument("Wrong dimensions for multiplication");
        }
        Matrix result(m_rows, other.m_columns, T{});
        for (size_t i = 0; i < m_rows; ++i) {
            for (size_t j = 0; j < other.m_columns; ++j) {
                for (size_t k = 0; k < m_columns; ++k) {
                    result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
        }
        return result;
    }

    /**
     * @brief Wypisanie macierzy do strumienia.
     * 
     * @param os Strumień wyjściowy
     * @param matrix Macierz do wypisania
     * @return Referencja do strumienia
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.m_rows; ++i) {
            for (size_t j = 0; j < matrix.m_columns; ++j) {
                os << matrix(i, j);
                if (j + 1 < matrix.m_columns) {
                    os << " ";
                }
            }
            os << '\n';
        }
        return os;
    }


}; 

} 

#include "SquareMatrix.hpp"
#include "IdentityMatrix.hpp"
