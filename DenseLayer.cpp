#include "DenseLayer.h"


DenseLayer::DenseLayer(int input, int output):input_size{input}, output_size{output},weights{Matrix(output_size, input_size)}, dw{Matrix(output_size, input_size)},
input{Matrix()}, output{Matrix()}, biases(Matrix(output_size, 1)), db(Matrix(output_size, 1)) {
    weights.random();
    dw.zeroes();
    biases.zeroes();
    db.zeroes();
}

Matrix DenseLayer::forward(const Matrix &input_layer) {
    input=input_layer;
    output = dot(weights, input) + biases;
    return output;
}



Matrix DenseLayer::backward(const Matrix &dz) {

    Matrix in_T = input.transpose();

    dw = dw + dot(dz, in_T);
    db = db + dz;
    return dot(weights.transpose(), elementwise(dz, deriv_ReLU(output)));


}


