#include "mnist_loader.h"
#include <iostream>
#include <fstream>

using namespace std;


Image::Image(vector<double> img, int label):img{img}, label{label} {}


int read(ifstream &file) {
    unsigned char bytes[4];
    file.read((char*)bytes, 4);
    return int(bytes[0] << 24 | bytes[1] << 16 | bytes[2] << 8 | bytes[3]);
}

vector<Image> load_images(const string &img_path, const string &label_path) {

    ifstream img(img_path, ios::binary);
    ifstream lbl(label_path, ios::binary);

    if (!img.is_open() || !lbl.is_open()) {
        cerr << "Error opening in file" << endl;
        return {};
    }

    int magic_img = read(img);
    int nos_img=read(img);
    int rows=read(img);
    int cols=read(img);

    int magic_lbl = read(lbl);
    int nos_lbl=read(lbl);


    if (nos_lbl!=nos_img) {cerr<<"file read incorrectly" << endl; return {};}

    vector<Image> ds(nos_img);

    for (int i = 0; i < nos_img; ++i) {
        vector<double> pxls(rows*cols);

        for (int j = 0; j < rows*cols; j++) {
            unsigned char byte;
            img.read((char*)&byte, 1);
            pxls[j]=byte/255.0; // Pixel value is > 0(Black) && < 255(White)
        }

        unsigned char lbl_byte;
        lbl.read((char*) &lbl_byte, 1);
        ds[i] = Image(pxls, lbl_byte);


    }

    return ds;





}

