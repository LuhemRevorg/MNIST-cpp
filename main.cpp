#include "mnist_loader.h"
#include <iostream>
#include "Matrix.h"
#include "NeuralNetwork.h"

Matrix one_hot(int lbl) {
    Matrix result(10, 1);
    result.zeroes();
    result.vals[lbl] = 1.0;
    return result;
}


int main() {

    // loading test and train data

    auto train_data = load_images("data/train-images.idx3-ubyte", "data/train-labels.idx1-ubyte");
    auto test_data = load_images("data/t10k-images.idx3-ubyte", "data/t10k-labels.idx1-ubyte");


    NeuralNetwork model = NeuralNetwork();

    Matrix pred = model.forward(train_data[0].img);
    Matrix dz = pred - one_hot(train_data[0].label);
    model.backward(dz);


    


}




