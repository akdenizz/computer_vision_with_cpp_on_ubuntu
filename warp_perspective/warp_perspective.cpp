#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

float w = 250, h = 350;
Mat matrix, img_warp, img_resize;


int main(){

    string path = "card.jpg";

    Mat img = imread(path);

    Point2f src[4] = {{1210, 1506}, {327, 1960}, {2413, 2539}, {1386, 3365}};

    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    matrix = getPerspectiveTransform(src, dst);

    warpPerspective(img, img_warp, matrix, Point(w, h));
    
    resize(img, img_resize, Size(), 0.2, 0.2);

    imshow("image", img_resize);
    imshow("warp perspective image", img_warp);

    waitKey(0);

    return 0;
}