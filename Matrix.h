#pragma once
#include <vector>
#include <iomanip>

using namespace std;

class Matrix {
 
    int m;
    int n;
    vector<double> vals;

    
    public:
        Matrix(int m , int n);
        Matrix()=default;
        friend Matrix dot(const Matrix &M1, const Matrix &M2);
        friend Matrix operator+(const Matrix &M1, const Matrix &M2);
        Matrix(const Matrix& M1);
        void print(int precision = 4) const;
        void random();
        void zeroes();
};

Matrix dot(const Matrix &M1, const Matrix &M2);
Matrix operator+(const Matrix &M1, const Matrix &M2);