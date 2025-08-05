#include "Matrix.h"
#include <iostream>
#include <random>
using namespace std;

Matrix::Matrix(int m, int n): m{m}, n{n}, vals{vector<double>(m*n)}{}
void Matrix::print(int precision) const {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::fixed << std::setprecision(precision)
                      << vals[i * n + j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

Matrix::Matrix(const Matrix &M1): m{M1.m}, n{M1.n}, vals{M1.vals} {}

void Matrix::random() {
    
    std::random_device rd;   // seed source
    std::mt19937 gen(rd());  // random number generator (Mersenne Twister)
    std::uniform_real_distribution<> dis(-1.0, 1.0);  // range: [-1, 1]

    for (int i = 0; i < m * n; ++i) {
        vals[i] = dis(gen);  // fill each element with a random double
    }

}

void Matrix::zeroes() {
    for (int i = 0; i < m * n; ++i) {
        vals[i] = 0;  // fill each element with a random double
    }
}

Matrix dot(const Matrix &M1, const Matrix &M2) {

    
    if (M1.n != M2.m) {cerr << "Issue with dot, order is wrong" << endl; return {};}
    Matrix result = Matrix(M1.m, M2.n);
    for(int k =0; k < M1.m; ++k) {
        for(int j = 0; j < M2.n; ++j) {
            double val = 0.0;
            for (int i = 0; i < M1.n; ++i) {
                val += M1.vals[i + M1.n*k]*M2.vals[i*M2.n + j];
            }
            result.vals[k*M2.n + j] = val;    
        }
    }
    return result;

}


Matrix operator+(const Matrix &M1, const Matrix &M2) {

    Matrix result(M1.m, M1.n);

    for (int i = 0; i < M1.m; ++i) {
        for (int j = 0; j < M1.n; ++j) {
            result.vals[i*M1.m + j] = M1.vals[i*M1.m + j] + M2.vals[i*M1.m + j];
        }
    }

    return result;

}





