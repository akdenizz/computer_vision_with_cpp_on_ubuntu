#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main(){

    string path="schumi.jpg";
    Mat img = imread(path);

    Mat img_resize, img_crop;

    // cout << img.size() << endl; // [1000 x 1000]

    // resize(img, img_resize, Size(640, 640));

    resize(img, img_resize, Size(), 0.5, 0.5); // makes its size half of original size

    Rect roi(100, 100, 300, 250);
    img_crop = img(roi);

    imshow("original image", img);
    imshow("resized image", img_resize);
    imshow("cropped image", img_crop);


    waitKey(0);
}