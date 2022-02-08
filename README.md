# COMPUTER VISION WITH C++ ON UBUNTU 18.04

## g++ Installation

***G++, the GNU C++ Compiler is a compiler in Linux which was developed to compile C++ programs. The file extensions that can be compiled with G++ are .c and .cpp.***

```$ sudo apt install build-essential```

check the installation with ```$ g++ -v```

## OpenCV Installation

* Update the Ubuntu System Package
```
$ sudo apt-get update && sudo apt-get upgrade
$ sudo apt install software-properties-common
$ sudo apt install apt-file
```
* Install Required tools and packages

```
$ sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
$ sudo apt-get install python3.7-dev python3-numpy libtbb2 libtbb-dev
$ sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
```
If you got an error like "unable to locate package" :

```$ sudo apt-add-repository "deb http://security.ubuntu.com/ubuntu xenial-security main"
$ sudo apt update
$ sudo apt install libjasper1 libjasper-dev
```
* Download OpenCV Sources using git

```
$ sudo apt install build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb2 libtbb-dev libdc1394-22-dev
$ mkdir ~/opencv_build && cd ~/opencv_build
$ git clone https://github.com/opencv/opencv.git
$ git clone https://github.com/opencv/opencv_contrib.git

```

* Build & Install OpenCV

```
$ cd ~/opencv_build/opencv
$ mkdir build && cd build
$ cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D INSTALL_C_EXAMPLES=ON \
    -D INSTALL_PYTHON_EXAMPLES=ON \
    -D OPENCV_GENERATE_PKGCONFIG=ON \
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules \
    -D BUILD_EXAMPLES=ON ..
```


``` 	
$ make -j8
```
you can check your proc with command ```nproc``` 

```
$ sudo make install
$ pkg-config --modversion opencv4

```
* Check OpenCV version installed

```
$ pkg-config --modversion opencv4
```

* Find & Set “opencv.pc” file path 

```
$ apt-file search opencv.pc
$ ls /usr/local/lib/pkgconfig/
$ sudo cp /usr/local/lib/pkgconfig/opencv4.pc  /usr/lib/x86_64-linux-gnu/pkgconfig/opencv.pc
$ pkg-config --modversion opencv
```


## Example Usage

* Make a directory

```
$ mkdir opencv_test
$ cd opencv_test
$ gedit test.cpp
```
* Copy the below code and paste in the file just created

In your ***opencv_test*** directory you must have an image named ***test.jpg*** for run the code succesfully.
```
#include <opencv2/highgui.hpp>
#include <iostream>
 
int main( int argc, char** argv ) {
  
  cv::Mat image;
  image = cv::imread("test.jpg" ,cv::IMREAD_COLOR);
  
  if(! image.data ) {
      std::cout <<  "Image not found or unable to open" << std::endl ;
      return -1;
    }
  
  cv::namedWindow( "OpenCV Test Program", cv::WINDOW_AUTOSIZE );
  cv::imshow( "OpenCV Test Program", image );
  
  cv::waitKey(0);
  return 0;
}
```

* Compile the Code

```
$ g++ test.cpp -o testoutput -std=c++11 `pkg-config --cflags --libs opencv4`
```

* Execute the code in opencv_test directory

```
$ ./testoutput
```
If you got some error like *libopencv_highgui.so.405: cannot open shared object file* :

``` 
$ sudo find / -name "libopencv_core.so.4.5*" 
```
output: ***/home/akdeniz/opencv_build/opencv/build/lib/libopencv_core.so.4.5.5***

```
$ sudo nano /etc/ld.so.conf.d/opencv.conf
```
copy the path into that file. For example: **/home/akdeniz/opencv_build/opencv/build/lib/**

```
$ sudo ldconfig -v
```