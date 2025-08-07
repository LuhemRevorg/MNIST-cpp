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

    dw = dw + dot(dz, in_T);   // accumulate gradients
    db = db + dz;

    return dot(weights.transpose(), dz); // return gradient to pass backward
}

void DenseLayer::apply(float batch_size, float lr) {

    dw = dw / batch_size;
    db = db / batch_size;
    weights = weights - lr * dw;
    biases = biases - lr * db;
    dw.zeroes();
    db.zeroes();
    

}
