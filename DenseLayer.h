#pragma once
#include <vector>
#include "Matrix.h"

class DenseLayer {

    int input_size;
    int output_size;
    Matrix weights;
    Matrix input;
    Matrix output;
    Matrix biases;

    public:
        DenseLayer() = default;
        DenseLayer(int input, int output);
        Matrix forward(const Matrix &input_layer);
};


