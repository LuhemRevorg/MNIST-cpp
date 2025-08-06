#include "NeuralNetwork.h"



NeuralNetwork::NeuralNetwork():l1(DenseLayer(784, 128)), l2(DenseLayer(128,10)) {}

Matrix NeuralNetwork::forward(const Matrix &input) {

    Matrix z1 = l1.forward(input);
    Matrix a1 = ReLU(z1);
    Matrix z2 = l2.forward(z1);
    Matrix output = softmax(z2);

    return output;

}

void NeuralNetwork::backward(const Matrix &dz) {

    Matrix grad = l2.backward(dz);
    l1.backward(grad);
    
}

