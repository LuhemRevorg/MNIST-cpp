#pragma once
#include "Matrix.h"
#include "DenseLayer.h"

class NeuralNetwork {

    DenseLayer l1;
    DenseLayer l2;

    public:
        NeuralNetwork();
        Matrix forward(const Matrix &input);
        void backward(const Matrix &dz);

};

