#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Matrix {
private:
    size_t rows; // Количество строк
    size_t columns; // Количество столбцов
    std::vector<std::vector<T>> matrix; // Двумерная матрица

public:
    using type = typename T;

    Matrix(); // Конструктор по умолчанию
    Matrix(size_t rows, size_t columns); // Конструктор с параметрами - количество строк и столбцов
    Matrix(size_t rows, size_t columns, T value); // Конструктор с параметрами - количество строк, столбцов и значение
    Matrix(const Matrix<T>& other); // Конструктор копирования


    size_t getRowCount() const; // Возвращает количества строк
    size_t getColumnCount() const; // Возвращает количества столбцов
    std::vector<std::vector<T>> getMatrix(); // Возвращает матрицу

    void setElement(size_t row, size_t col, T value); // Получение элемента
    T getElement(size_t row, size_t col) const; // Возвращает элемент

    std::vector<T> getRow(size_t row) const; // Возвращает строку
    std::vector<T> getColumn(size_t col) const; // Возвращает столбец

    void fillMatrix(T value); // Заполение матрицы значениями

    void addRow(T value = T()); // Добавление строки
    void addColumn(T value = T()); // Добавление столбца

    void removeRow(size_t number); // Удаление строки
    void removeColumn(size_t number); // Удаление столбца


    Matrix<T>& operator=(const Matrix<T>& other); // Оператор присваивания
    Matrix<T> operator+(const Matrix<T>& other); // Оператор сложения
    Matrix<T> operator-(const Matrix<T>& other); // Оператор вычитания

    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix); // Вывод матрицы

    template <typename T>
    friend std::istream& operator>>(std::istream& is, Matrix<T>& matrix); // Ввод матрицы
};

// КОНСТРУКТОРЫ

template <typename T>
Matrix<T>::Matrix() : 
    rows(0), columns(0) {}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns) :
    rows(rows), columns(columns), matrix(rows, std::vector<T>(columns)) {}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns, T value) :
    rows(rows), columns(columns), matrix(rows, std::vector<T>(columns, value)) {}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) :
    rows(other.rows), columns(other.columns), matrix(other.matrix) {}

// МЕТОДЫ

template <typename T>
size_t Matrix<T>::getRowCount() const {
    return rows;
}

template <typename T>
size_t Matrix<T>::getColumnCount() const {
    return columns;
}

template <typename T>
std::vector<std::vector<T>> Matrix<T>::getMatrix() {
    return matrix;
}

template <typename T>
void Matrix<T>::setElement(size_t row, size_t col, T value) {
    if ((row >= rows) || (col >= columns)) {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    matrix[row][col] = value;
}

template <typename T>
T Matrix<T>::getElement(size_t row, size_t col) const {
    if ((row >= rows) || (col >= columns)) {
        std::cout << "Index out of range" << std::endl;
        return T();
    }
    return matrix[row][col];
}

template <typename T>
std::vector<T> Matrix<T>::getRow(size_t row) const {
    return matrix[row];
}

template <typename T>
std::vector<T> Matrix<T>::getColumn(size_t col) const {
    std::vector<T> result;
    for (auto& row : matrix) {
        result.push_back(row.at(col - 1));
    }
    return result;
}

template <typename T>
void Matrix<T>::fillMatrix(T value) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            matrix[i][j] = value;
        }
    }
}

template <typename T>
void Matrix<T>::addRow(T value) {
    matrix.push_back(std::vector<T> (columns, value));
    rows += 1;
}

template <typename T>
void Matrix<T>::addColumn(T value) {
    for (size_t i = 0; i < rows; ++i) {
        matrix[i].push_back(value);
    }
    columns += 1;
}

template <typename T>
void Matrix<T>::removeRow(size_t number) {
    if (number >= rows) {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    matrix.erase(matrix.begin() + number);
    rows -= 1;
}

template <typename T>
void Matrix<T>::removeColumn(size_t number) {
    if (number >= columns) {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    for (size_t i = 0; i < rows; ++i) {
        matrix[i].erase(matrix[i].begin() + number);
    }
    columns -= 1;
}

// ПЕРЕГРУЗКА ОПЕРАТОРОВ

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
    if (this != &other) {
        rows = other.rows;
        columns = other.columns;
        matrix = other.matrix;
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) {
    Matrix<T> result(rows, columns);
    if ((rows == other.rows) && (columns == other.columns)) {
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.columns; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) {
    Matrix<T> result(rows, columns);
    if ((rows == other.rows) && (columns == other.columns)) {
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.columns; ++j) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
    }
    return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.columns; ++j) {
            os << matrix.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Matrix<T>& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.columns; ++j) {
            T value;
            is >> value;
            matrix.setElement(i, j, value);
        }
    }
    return is;
}
