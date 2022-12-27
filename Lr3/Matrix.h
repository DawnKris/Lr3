#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

using namespace std::literals;

template<typename T>
class Matrix {
private:
    size_t row;
    size_t column;

    T** data;

    static void swap(Matrix& lhs, Matrix& rhs) {
        std::swap(lhs.row, rhs.row);
        std::swap(lhs.column, rhs.column);
        std::swap(lhs.data, rhs.data);
    }

    void checkAccess(size_t i, size_t j) const {
        if (!(i < row && j < column)) {
            auto reason = "can't access matrix element at "s + std::to_string(i) + ", " + std::to_string(j);
            throw std::invalid_argument(reason);
        }
    }

public:
    Matrix(size_t row, size_t column, const T& defaultValue) : row(row), column(column) {
        data = new T * [row];
        for (size_t i = 0; i < row; ++i) {
            data[i] = new T[column];
            for (size_t j = 0; j < column; ++j) {
                data[i][j] = defaultValue;
            }
        }
    }

    Matrix(const Matrix& other) : row(other.row), column(other.column) {
        data = new T * [row];
        for (size_t i = 0; i < row; ++i) {
            data[i] = new T[column];
            for (size_t j = 0; j < column; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (size_t i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            Matrix tmp(other);
            swap(*this, tmp);
        }
        return *this;
    }

    [[nodiscard]] size_t rows() const {
        return row;
    }

    [[nodiscard]] size_t columns() const {
        return column;
    }

    //T & ???
    //const T & ???

    T get(size_t i, size_t j) const {
        checkAccess(i, j);
        return data[i][j];
    }

    void set(size_t i, size_t j, const T& value) {
        checkAccess(i, j);
        data[i][j] = value;
    }

    Matrix sum(const Matrix& matrix) const {
        if (!(row == matrix.row && column == matrix.column)) {
            throw std::invalid_argument("can't sum matrix with different [rows * columns]");
        }

        auto result = Matrix(row, column, T()); //create matrix with same size and default value of type T
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < column; ++j) {
                result.data[i][j] = data[i][j] + matrix.data[i][j];
            }
        }

        return result;
    }

    void print() const {
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < column; ++j) {
                std::cout << std::setw(4) << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif //MATRIX_H
