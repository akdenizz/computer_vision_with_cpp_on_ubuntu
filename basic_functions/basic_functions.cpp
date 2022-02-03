#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main(){

    string path="schumi.jpg";
    Mat img = imread(path);

    Mat img_gray, img_blur, img_canny, img_dilate, img_erode;

    cvtColor(img, img_gray, COLOR_BGR2GRAY);

    GaussianBlur(img, img_blur, Size(3, 3), 3, 0);

    Canny(img_blur, img_canny, 25, 75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

    dilate(img_canny, img_dilate, kernel);

    erode(img_dilate, img_erode, kernel);

    imshow("Original Image", img);
    imshow("Gray Image", img_gray);
    imshow("Gaussian Blur Image", img_blur);
    imshow("Canny Image", img_canny);
    imshow("Dilation Image", img_dilate);
    imshow("Erode Image", img_erode);
    
    waitKey(0);
}