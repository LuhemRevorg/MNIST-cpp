#pragma once

#include <string>
#include <vector>
using namespace std;


class Image {
    
    public:
        vector<double> img;
        int label;
        Image(vector<double> img, int label);
        Image() = default;

};

vector<Image> load_images(const string &img_path, const string &label_path);


