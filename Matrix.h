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
        Matrix(int m , int n, vector<double> vals);
        Matrix()=default;
        friend Matrix dot(const Matrix &M1, const Matrix &M2);
        friend Matrix operator+(const Matrix &M1, const Matrix &M2);
        friend Matrix operator/(const Matrix &M, float num);
        friend Matrix ReLU(const Matrix &M);
        friend Matrix softmax(const Matrix &M);
        friend Matrix elementwise(const Matrix &M1, const Matrix &M2);
        friend Matrix deriv_ReLU(const Matrix &M);
        friend Matrix one_hot(int label);
        friend Matrix operator-(const Matrix& M1, const Matrix& M2);
        friend Matrix operator*(float num, const Matrix &M);
        Matrix(const Matrix& M1);
        Matrix transpose() const;
        void print(int precision = 8) const;
        void random();
        void zeroes();
        int argmax();
};

Matrix dot(const Matrix &M1, const Matrix &M2);
Matrix operator+(const Matrix &M1, const Matrix &M2);
Matrix ReLU(const Matrix &M);
Matrix softmax(const Matrix &M);
Matrix operator/(const Matrix &M, float num);
Matrix elementwise(const Matrix &M1, const Matrix &M2);
Matrix deriv_ReLU(const Matrix &M);
Matrix one_hot(int label);
Matrix operator-(const Matrix& M1, const Matrix& M2);
Matrix operator*(float num, const Matrix &M);
