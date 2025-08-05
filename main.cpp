#include "mnist_loader.h"
#include <iostream>
#include "Matrix.h"


int main() {

    // loading test and train data

    auto train_data = load_images("data/train-images.idx3-ubyte", "data/train-labels.idx1-ubyte");
    auto test_data = load_images("data/t10k-images.idx3-ubyte", "data/t10k-labels.idx1-ubyte");

    Matrix M1(3,4);
    Matrix M2(3,4);

    M1.random();
    M2.random();

    Matrix result = M1 + M2;

    cout << "Matrix M1" << endl;
    M1.print();
    cout << endl;
    
    cout << "Matrix M2" << endl;
    M2.print();
    cout << endl;

    cout << "Result" << endl;
    result.print();
    cout << endl;


    


}




