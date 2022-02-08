#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>

using namespace cv;
using namespace std;

// h_min, s_min, v_min, h_max, s_max, v_max 
vector<vector<int>> my_colors{{0,70,8,7,255,161}, //red
                            {27,54,40,40,255,255}}; // green

vector<Scalar> my_color_values{(255, 0 , 0),
                                (0, 255, 0)};

Mat img;

vector<vector<int>> new_points;


Point get_contours(Mat img_dilate){

    vector<vector<Point>> contours;
    vector<Vec4i> hierarcy;
    

    findContours(img_dilate, contours, hierarcy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //drawContours(img, contours, -1, Scalar(255, 0, 255),2);

    vector<vector<Point>> con_poly(contours.size());
    vector<Rect> bound_rect(contours.size());

    Point my_point(0, 0);
    
    

    for (int i = 0; i < contours.size(); i++){

        int area = contourArea(contours[i]);
        cout << area << endl;

        string object_type;

        if (area > 1000) {

            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], con_poly[i], 0.02 * peri, true);

            cout << con_poly[i].size() << endl;
            bound_rect[i] = boundingRect(con_poly[i]);
            my_point.x = bound_rect[i].x + bound_rect[i].width / 2;
            my_point.y = bound_rect[i].y;
            
            drawContours(img, con_poly, i, Scalar(255, 0, 255), 2); 

            rectangle(img, bound_rect[i].tl(), bound_rect[i].br(), Scalar(0, 255, 0),5);
        }


    }
    return my_point;

}

vector<vector<int>> find_color(Mat img){

    Mat img_hsv;
    cvtColor(img, img_hsv, COLOR_BGR2HSV);

    for (int i = 0; i < my_colors.size(); i++){
        Scalar lower(my_colors[i][0], my_colors[i][1], my_colors[i][2]);
        Scalar upper(my_colors[i][3], my_colors[i][4], my_colors[i][5]);
        Mat mask;    
        inRange(img_hsv, lower, upper, mask);
        //imshow(to_string(i), mask);
        Point my_point = get_contours(mask);
        if (my_point.x != 0){

            new_points.push_back({my_point.x, my_point.y, i});

        }
        
    }
    return new_points;
}


void draw_on_canvas(vector<vector<int>> new_points, vector<Scalar> my_color_values){

    for (int i = 0; i < new_points.size(); i++){

        circle(img, Point(new_points[i][0], new_points[i][1]), 10, my_color_values[new_points[i][2]], FILLED); 

    }

}

int main() {

    VideoCapture cap(0);


    while (true){

        cap.read(img);

        new_points = find_color(img);

        draw_on_canvas(new_points, my_color_values);

        imshow("Image", img);

        if (waitKey(10) == 27){

            cout << "Esc key is pressed by user. Stoppig the video" << endl;
        
        break;

        }

    }
    
    return 0;

}