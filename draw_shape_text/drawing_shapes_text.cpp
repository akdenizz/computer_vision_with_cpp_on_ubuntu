#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main(){

    Mat img(512, 512, CV_8UC3, Scalar(0, 255, 0));

    circle(img, Point(256, 256), 155, Scalar(255, 0, 169), FILLED); //(img, Point center, radius, Scalar &color, int thickness = 1, int lineType = 8, int shift = 0)

    rectangle(img, Point(130, 230), Point(320,210), Scalar(255, 255, 0), FILLED); // (img, Rect rec, Scalar &color, int thickness = 1, int lineType = 8, int shift = 0)

    line(img, Point(130, 300), Point(320,300), Scalar(255, 255, 255), 3); // (img, Point pt1, Point pt2, Scalar &color, int thickness = 1, int lineType = 8, int shift = 0)

    putText(img, "aysenur", Point(130, 230), FONT_HERSHEY_DUPLEX, 0.75, Scalar(120, 36, 12), 2); //(img, String &text, Point org, int fontFace, double fontScale, Scalar color, int thickness = 1, int lineType = 8, bool bottomLeftOrigin = false)

    imshow("image", img);

    waitKey(0);

    return 0;
}