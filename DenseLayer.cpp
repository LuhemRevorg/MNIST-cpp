#include "DenseLayer.h"


DenseLayer::DenseLayer(int input, int output):input_size{input}, output_size{output},weights{Matrix()},
input{Matrix()}, output{Matrix()}, biases(Matrix()) {
    weights.random();
    biases.zeroes();
}



Matrix DenseLayer::forward(const Matrix &input_layer) {

    input=input_layer;
    output = dot(weights, input) + biases;

}






