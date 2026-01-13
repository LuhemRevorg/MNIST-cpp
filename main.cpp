#include "mnist_loader.h"
#include <iostream>
#include "Matrix.h"
#include "NeuralNetwork.h"
#include <algorithm>
#include <random>
#include <thread>

Matrix one_hot(int lbl) {
    Matrix result(10, 1);
    result.zeroes();
    result.vals[lbl] = 1.0;
    return result;
}

int main() {
    // Load training and test data
    auto train_data = load_images("data/train-images.idx3-ubyte", "data/train-labels.idx1-ubyte");
    auto test_data = load_images("data/t10k-images.idx3-ubyte", "data/t10k-labels.idx1-ubyte");

    NeuralNetwork model;
    int batch_size = 100;
    float lr = 0.01;
    int num_threads = 4;
    int chunk_size = batch_size / num_threads;
    int seed = 32;

    for (int epoch = 0; epoch < 10; ++epoch) {
        std::shuffle(train_data.begin(), train_data.end(), std::default_random_engine(seed + epoch));

        for (int i = 0; i + batch_size <= train_data.size(); i += batch_size) {
            std::vector<NeuralNetwork> thread_models(num_threads, model);
            std::vector<std::thread> threads;

            for (int t = 0; t < num_threads; ++t) {
                threads.emplace_back([&, t]() {
                    int start = i + t * chunk_size;
                    int end = start + chunk_size;
                    for (int j = start; j < end; ++j) {
                        Matrix pred = thread_models[t].forward(train_data[j].img);
                        Matrix dz = pred - one_hot(train_data[j].label);
                        thread_models[t].backward(dz);
                    }
                });
            }

            for (auto& thread : threads) thread.join();

            model.zero_gradients();
            for (int t = 0; t < num_threads; ++t) {
                model.accumulate_gradients(thread_models[t]);
            }

            model.apply(batch_size, lr);
        }

        // Evaluate accuracy after each epoch
        int correct = 0;
        for (int j = 0; j < test_data.size(); ++j) {
            Matrix pred = model.forward(test_data[j].img);
            if (pred.argmax() == test_data[j].label) correct++;
        }

        float acc = 100.0f * correct / test_data.size();
        std::cout << "Epoch " << epoch + 1 << " Accuracy: " << acc << "%" << std::endl;
    }

    std::cout << "Training Complete & Testing Complete!" << std::endl;
    return 0;
}