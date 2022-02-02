# COMPUTER VISION APPLICATIONS WITH C++ ON UBUNTU 18.04

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
$ sudo -s
$ cd /opt
$ git clone https://github.com/Itseez/opencv.git
$ git clone https://github.com/Itseez/opencv_contrib.git
```

*Build & Install OpenCV

```
$ cd opencv
$ mkdir release
$ cd release
$ cmake -D BUILD_TIFF=ON -D WITH_CUDA=ON -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D OPENCV_GENERATE_PKGCONFIG=ON -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/
```


``` 	
$ make -j8
```
you can check your proc with command ```nproc``` 

```
$ make install
$ ldconfig
$ exit
$ cd ~
```
* Check OpenCV version installed

```
$ pkg-config --modversion opencv
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
  
  cv::namedWindow( "Techawarey:OpenCV Test Program", cv::WINDOW_AUTOSIZE );
  cv::imshow( "Techawarey:OpenCV Test Program", image );
  
  cv::waitKey(0);
  return 0;
}
```

* Compile the Code

```
$ g++ test.cpp -o testoutput -std=c++11 `pkg-config --cflags --libs opencv`
```

* Execute the code in opencv_test directory

```
$ ./testoutput
```
