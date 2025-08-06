#include "mnist_loader.h"
#include <iostream>
#include "Matrix.h"
#include "NeuralNetwork.h"


int main() {

    // loading test and train data

    auto train_data = load_images("data/train-images.idx3-ubyte", "data/train-labels.idx1-ubyte");
    auto test_data = load_images("data/t10k-images.idx3-ubyte", "data/t10k-labels.idx1-ubyte");


    NeuralNetwork model = NeuralNetwork();

    model.forward(train_data[0].img).print();


    


}




