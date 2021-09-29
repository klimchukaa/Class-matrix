//
// Created by klimchuk.aa on 29.09.2021.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Matrix{
    int n, m;
    vector <vector <T>> data;
public:
    // Constructors
    Matrix(vector <vector <T>>);
    Matrix(int, int);
    // Methods
    int size_rows() const { return n; }
    int size_columns() const { return m; }
    // Operators
    const Matrix operator+(const Matrix&) const;
    const Matrix operator*(const Matrix&) const;
    const Matrix operator*(const T&) const;
    vector <T>& operator[](int i) { return data[i]; };
    const vector<T>& operator[](int i) const { return data[i]; };
    // Functions
    Matrix transposition();
    const Matrix get_power(int) const;
};

template<typename T>
Matrix<T>::Matrix(vector <vector <T>> v) {
    data = v;
    n = v.size(); m = v[0].size();
}

template<typename T>
Matrix<T>::Matrix(int n_, int m_) {
    data.assign(n_, vector <int> (m_, 0));
    n = n_; m = m_;
}

template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix& a) const {
    Matrix<T> res(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i][j] = data[i][j] + a[i][j];
        }
    }
    return res;
}

template<typename T>
const Matrix<T> Matrix<T>::operator*(const Matrix& a) const {
    Matrix<T> res(n, a.m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a.m; ++j) {
            for (int w = 0; w < m; ++w) {
                res[i][j] += data[i][w] * a[w][j];
            }
        }
    }
    return res;
}

template<typename T>
const Matrix<T> Matrix<T>::operator*(const T& k) const {
    Matrix<T> res(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i][j] = data[i][j] * k;
        }
    }
    return res;
}

template<typename T>
Matrix<T> Matrix<T>::transposition() {
    Matrix res(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = data[j][i];
        }
    }
    return res;
}

template<typename T>
const Matrix<T> Matrix<T>::get_power(int p) const {
    if (p == 1) return (*this);
    if (p & 1) {
        return ((*this) * (*this)).get_power(p / 2) * (*this);
    } else {
        return ((*this) * (*this)).get_power(p / 2);
    }
}


#endif //MATRIX_MATRIX_H
