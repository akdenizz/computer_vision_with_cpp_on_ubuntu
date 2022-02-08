#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;


Mat img_gray, img_blur, img_canny, img_dilate;


void get_contours(Mat img_dilate, Mat img){

    vector<vector<Point>> contours;
    vector<Vec4i> hierarcy;
    

    findContours(img_dilate, contours, hierarcy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //drawContours(img, contours, -1, Scalar(255, 0, 255),2);

    vector<vector<Point>> con_poly(contours.size());
    vector<Rect> bound_rect(contours.size());

    string object_type;

    for (int i = 0; i < contours.size(); i++){

        int area = contourArea(contours[i]);
        cout << area << endl;


        if (area > 1000) {

            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], con_poly[i], 0.02 * peri, true);
            drawContours(img, con_poly, i, Scalar(255, 0, 255), 2); 
            cout << con_poly[i].size() << endl;
            bound_rect[i] = boundingRect(con_poly[i]);
               

            int obj_cor = (int)con_poly[i].size();

            if (obj_cor == 3) {object_type = "Triangle"; }
            if (obj_cor == 4) {object_type = "Rectangle" ;}
            if (obj_cor == 6) {object_type = "Hexagon" ;}
            if (obj_cor > 6) {object_type = "circle"; }
            rectangle(img, bound_rect[i].tl(), bound_rect[i].br(), Scalar(0, 255, 0),5);
            putText(img, object_type, {bound_rect[i].x, bound_rect[i].y -5 }, FONT_HERSHEY_PLAIN, 0.75, Scalar(0, 69, 255), 1);

        }


    }

}

int main(){

    string path = "shape2.png";
    Mat img = imread(path);

    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    GaussianBlur(img, img_blur, Size(3, 3), 3, 0);
    Canny(img_blur, img_canny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(img_canny, img_dilate, kernel);

    get_contours(img_dilate, img);

    imshow("Original Image", img);

    
    waitKey(0);
}