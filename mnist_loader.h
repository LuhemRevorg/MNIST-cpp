#pragma once

#include <string>
#include <vector>
#include "Matrix.h"
using namespace std;


class Image {
    
    public:
        Matrix img;
        int label;
        Image(Matrix img, int label);
        Image() = default;

};

vector<Image> load_images(const string &img_path, const string &label_path);


