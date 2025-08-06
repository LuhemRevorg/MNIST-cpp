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

Matrix::Matrix(int m , int n, vector<double> vals): m{m}, n{n}, vals{vals} {}

Matrix::Matrix(const Matrix &M1): m{M1.m}, n{M1.n}, vals{M1.vals} {}

void Matrix::random() {
    
    std::random_device rd;   // seed source
    std::mt19937 gen(rd());  // random number generator (Mersenne Twister)
    std::uniform_real_distribution<> dis(-1,1);  // range: [-1, 1]

    for (int i = 0; i < m * n; ++i) {
        vals[i] = dis(gen);  // fill each element with a random double
    }

}

Matrix Matrix::transpose() const {

    Matrix result(n, m);  // flipped dimensions
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            result.vals[j * m + i] = vals[i * n + j];
        }
    }
    return result;

}

Matrix ReLU(const Matrix &M) {
    Matrix output(M.m, M.n);
    for (int i = 0; i < M.m; ++i) {
        for (int j = 0; j < M.n; ++j) {
            output.vals[i * M.n + j] = std::max(0.0, M.vals[i * M.n + j]);
        }
    }
    return output;
}

Matrix softmax(const Matrix &M) {
    Matrix result(M.m, M.n);

    // Find max value for numerical stability
    double max_val = *std::max_element(M.vals.begin(), M.vals.end());

    // Compute exponentials
    double sum = 0.0;
    for (int i = 0; i < M.m * M.n; ++i) {
        result.vals[i] = std::exp(M.vals[i] - max_val);
        sum += result.vals[i];
    }

    // Normalize
    for (int i = 0; i < M.m * M.n; ++i) {
        result.vals[i] /= sum;
    }

    return result;
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


Matrix operator+(const Matrix& M1, const Matrix& M2) {
    if (M1.m != M2.m || M1.n != M2.n) {
        std::cerr << "Matrix + error: dimension mismatch\n";
        std::exit(EXIT_FAILURE);  // or throw
    }

    Matrix result(M1.m, M1.n);
    for (int i = 0; i < M1.m * M1.n; ++i) {
        result.vals[i] = M1.vals[i] + M2.vals[i];
    }
    return result;
}

Matrix operator/(const Matrix &M, float num) {
    Matrix result = Matrix(M.m, M.n);
    for(int i = 0; i < M.m; i++) {
        for (int j =0; j < M.n; ++j) {
            result.vals[i*M.n + j] = M.vals[i*M.n + j] / num;
        }
    }
    return result;
}

Matrix deriv_ReLU(const Matrix &M) {
    Matrix result = Matrix(M.m, M.n);
    for(int i = 0; i < M.m; i++) {
        for (int j =0; j < M.n; ++j) {
            if (M.vals[i*M.n + j] > 0.0) {result.vals[i*M.n + j] = 1;}
            else result.vals[i*M.n + j] = 0;
        }
    }
    return result;
}


Matrix elementwise(const Matrix& M1, const Matrix& M2) {
    if (M1.m != M2.m || M1.n != M2.n) {
        std::cerr << "Elementwise error: dimension mismatch.\n";
        return {};
    }

    Matrix result(M1.m, M1.n);
    for (int i = 0; i < M1.m; ++i) {
        for (int j = 0; j < M1.n; ++j) {
            int idx = i * M1.n + j;
            result.vals[idx] = M1.vals[idx] * M2.vals[idx];
        }
    }

    return result;
}

Matrix operator-(const Matrix& M1, const Matrix& M2) {
    if (M1.m != M2.m || M1.n != M2.n) {
        std::cerr << "Matrix - error: dimension mismatch\n";
        return {};
    }

    Matrix result(M1.m, M1.n);
    for (int i = 0; i < M1.m; ++i) {
        for (int j = 0; j < M1.n; ++j) {
            int idx = i * M1.n + j;
            result.vals[idx] = M1.vals[idx] - M2.vals[idx];
        }
    }

    return result;
}



