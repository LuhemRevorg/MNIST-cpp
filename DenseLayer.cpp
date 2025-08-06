#include "DenseLayer.h"


DenseLayer::DenseLayer(int input, int output):input_size{input}, output_size{output},weights{Matrix(output_size, input_size)},
input{Matrix()}, output{Matrix()}, biases(Matrix(output_size, 1)) {
    weights.random();
    biases.zeroes();
}

Matrix DenseLayer::forward(const Matrix &input_layer) {
    input=input_layer;
    output = dot(weights, input) + biases;
    return output;
}






