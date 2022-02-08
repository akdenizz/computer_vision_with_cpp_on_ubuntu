#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main(){

    string path="schumi.jpg";
    Mat img = imread(path);

    CascadeClassifier face_cascade;

    face_cascade.load("haarcascade_frontalface_default.xml");
    if (face_cascade.empty()){ cout << "XML file not loaded" << endl; }

    vector<Rect> faces;
    face_cascade.detectMultiScale(img, faces, 1.1, 10); //scale factor, min neighbours

    for (int i; i < faces.size(); i++){

        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0),5);
    }
    imshow("Image", img);    
    waitKey(0);
}