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
    Matrix(vector <vector <T>>);
    Matrix(int, int);
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

#endif //MATRIX_MATRIX_H
