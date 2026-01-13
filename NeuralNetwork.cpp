#include "NeuralNetwork.h"



NeuralNetwork::NeuralNetwork():l1(DenseLayer(784, 128)), l2(DenseLayer(128,10)) {}

Matrix NeuralNetwork::forward(const Matrix &input) {

    Matrix z1 = l1.forward(input);
    Matrix a1 = ReLU(z1);
    Matrix z2 = l2.forward(a1);
    Matrix output = softmax(z2);

    return output;

}

void NeuralNetwork::backward(const Matrix &dz) {

    Matrix dz1 = l2.backward(dz);
    Matrix relu_grad = elementwise(dz1, deriv_ReLU(l1.out()));
    Matrix dz0 = l1.backward(relu_grad);
    
}

void NeuralNetwork::apply(float batch_size, float lr) {
    l1.apply(batch_size, lr);
    l2.apply(batch_size, lr);
}

void NeuralNetwork::zero_gradients() {
    l1.zero_gradients();
    l2.zero_gradients();
}

void NeuralNetwork::accumulate_gradients(const NeuralNetwork& other) {
    l1.accumulate_gradients(other.l1);
    l2.accumulate_gradients(other.l2);
}
