#include "mnist_loader.h"
#include <iostream>
#include "Matrix.h"
#include "NeuralNetwork.h"
#include <algorithm>
#include <random>

Matrix one_hot(int lbl) {
    Matrix result(10, 1);
    result.zeroes();
    result.vals[lbl] = 1.0;
    return result;
}




int main() {

    // loading test and train data
    int seed = 32;
    auto train_data = load_images("data/train-images.idx3-ubyte", "data/train-labels.idx1-ubyte");
    auto test_data = load_images("data/t10k-images.idx3-ubyte", "data/t10k-labels.idx1-ubyte");


    NeuralNetwork model = NeuralNetwork();
    int batch_size = 100;
    float lr = 0.01;
 

    for (int epoch = 0; epoch < 10; ++epoch) {
        int round = 0;
        std::shuffle(train_data.begin(), train_data.end(), std::default_random_engine(seed));
        for (long unsigned int i = 0; i < train_data.size(); ++i) {
            Matrix pred = model.forward(train_data[i].img);
            Matrix dz = pred - one_hot(train_data[i].label);
            model.backward(dz);
            ++round;
            if (round == batch_size) {
                model.apply(batch_size, lr);
                round = 0;
            }
        }

        int correct = 0;
        for (long unsigned int j = 0; j < test_data.size(); ++j) {
            Matrix pred = model.forward(test_data[j].img);
            if (pred.argmax() == test_data[j].label) correct++;
        }

        float acc = 100.0f * correct / test_data.size();
        cout << "Epoch " << epoch+1 << " Accuracy: " << acc << "%" << endl;
    }

    cout << "Training Complete & Testing Complete!" << endl;

   


}




