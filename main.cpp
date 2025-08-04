#include "mnist_loader.h"
#include <iostream>


int main() {

    auto train_data = load_images("data/train-images.idx3-ubyte", "data/train-labels.idx1-ubyte");
    cout << "Training Data Loaded :)" << endl;
    for (int row = 0; row < 28; ++row) {
        for (int col = 0; col < 28; ++col) {
            std::cout << (train_data[0].img[row * 28 + col] > 0.0 ? '#' : ' ');
        }   
    std::cout << '\n';
}


}



