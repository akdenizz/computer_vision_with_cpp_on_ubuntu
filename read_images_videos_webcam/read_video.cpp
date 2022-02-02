#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

/// Video

int main(){

    string path = "perez.mp4";
    VideoCapture cap(path);

    Mat img;
    while(true){

        cap.read(img);
        imshow("video", img);
        waitKey(20);

    }

    return 0;
}


