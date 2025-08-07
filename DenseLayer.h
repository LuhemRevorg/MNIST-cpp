#pragma once
#include <vector>
#include "Matrix.h"

class DenseLayer {

    int input_size;
    int output_size;
    Matrix weights;
    Matrix dw;
    Matrix input;
    Matrix output;
    Matrix biases;
    Matrix db;

    public:
        DenseLayer() = default;
        DenseLayer(int input, int output);
        Matrix forward(const Matrix &input_layer);
        Matrix backward(const Matrix &dz);
        void apply(float batch_size, float lr);
        Matrix out() {return output;}
};


