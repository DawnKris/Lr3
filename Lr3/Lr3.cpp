#include "Matrix.h"
#include "Point.h"

#include <iostream>

void basic() {
    Matrix<int> matrix = Matrix<int>(3, 4, 0);
    std::cout << matrix.rows() << " " << matrix.columns() << std::endl;

    matrix.print();

    try {
        std::cout << matrix.get(0, 4);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    matrix.set(1, 1, 0xff);
    matrix.print();

    std::cout << matrix.get(1, 1) << std::endl;

    try {
        matrix.set(3, 0, 0xff);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Matrix<int> matrix1 = Matrix<int>(3, 4, 1);
    matrix1.print();

    Matrix<int> result = matrix.sum(matrix1);
    result.print();
}

void complex() {
    Matrix<Point> matrix = Matrix<Point>(2, 3, Point(1, 2, 3));
    matrix.print();

    std::cout << matrix.get(0, 0) << std::endl;
    matrix.set(0, 0, Point(3, 3, 3));

    Matrix<Point> matrix1 = Matrix<Point>(2, 3, Point(1, 0, 0));
    matrix1.print();

    Matrix<Point> result = matrix.sum(matrix1);
    result.print();

    Matrix<Point> a = Matrix<Point>(result);
    Matrix<Point> b = a; 

    b.set(0, 0, Point(9, 9, 9));
    b.print();

    a.print();

    a = b;
    a.print();
}

int main() {
    basic();
    std::cout << std::string(70, '-') << std::endl;
    complex();
    return 0;
}
