#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

Mat img_hsv, mask;
int h_min = 0, s_min = 70, v_min = 50; // red detection
int h_max = 10, s_max = 255, v_max = 255;

int main(){

    string path = "redbull.jpg";
    Mat img = imread(path);
    cvtColor(img, img_hsv, COLOR_BGR2HSV);

    namedWindow("Trackbars", (640, 200));
    createTrackbar("Hue min", "Trackbars", &h_min, 180);
    createTrackbar("Hue max", "Trackbars", &h_max, 255);
    createTrackbar("Sat min", "Trackbars", &s_min, 255);
    createTrackbar("Sat max", "Trackbars", &s_max, 255);
    createTrackbar("Val min", "Trackbars", &v_min, 255);
    createTrackbar("Val max", "Trackbars", &v_max, 255);

    while (true){

        Scalar lower(h_min, s_min, v_min);
        Scalar upper(h_max, s_max, v_max);

        inRange(img_hsv, lower, upper, mask);

        imshow("original img", img);
        imshow("hsv img", img_hsv);
        imshow("masked img", mask);
        
        if(waitKey(1) == 27){
            break;
        }

    }
    

    return 0;

}