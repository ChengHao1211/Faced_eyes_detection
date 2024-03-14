#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;
/*
int main( int argc, char** argv )
{
    cout << "Program started." << endl;

     string img = "C:\\Users\\ychen\\CodingProgram\\C++\\opencvexample\\lenna.jpeg";
     Mat srcImage = imread(img);
     if (srcImage.empty())
         std::cout << "failed to open img.jpg" << std::endl;
     if (!srcImage.data) {
         cerr << "Error: Unable to load image " << img << endl;
         return 1;
     }

    cout << "Image loaded successfully." << endl;

     imshow("srcImage", srcImage);
     waitKey(0);

    cout << "Program ended." << endl;
    return 0;
    */


int main(int argc, char** argv) {
    double scale = 2.0;

    CascadeClassifier faceCascade, glassCascade;
    faceCascade.load("C:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");
    glassCascade.load("C:\\opencv\\sources\\data\\haarcascades\\haarcascade_eye_tree_eyeglasses.xml");

    VideoCapture cap(0);
    if (!cap.isOpened()) {
        return 0;
    }


    while (true) {
        Mat frame;
        cap >> frame;

        Mat grayScale;
        cvtColor(frame, grayScale, COLOR_BGR2GRAY);
        resize(grayScale, grayScale, Size(grayScale.size().width / scale, grayScale.size().height/scale));

        vector<Rect> faces;

        faceCascade.detectMultiScale(grayScale, faces, 1.1, 3, 0, Size(30, 30));


        for (Rect area : faces) {
            Scalar drawColor = Scalar(255, 0, 0);
            rectangle(frame, Point(cvRound(area.x * scale), cvRound(area.y * scale)), 
                Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawColor);

            Mat faceROI = grayScale(area);
            vector<Rect> glasses;
            glassCascade.detectMultiScale(faceROI, glasses, 1.1, 3, 0, Size(30, 30));
            
            for (Rect glassArea : glasses){
                Rect glassRect(cvRound(area.x * scale) + cvRound(glassArea.x * scale),
                    cvRound(area.y * scale) + cvRound(glassArea.y * scale),
                    cvRound(glassArea.width * scale),
                    cvRound(glassArea.height * scale));

                Scalar glassColor = Scalar(0, 255, 0);
                rectangle(frame, glassRect.tl(), glassRect.br(), glassColor);
            }
        }


        imshow("Image", frame);
        const int esc_key = 27;
        if (waitKey(10) == esc_key) {
            break;
        }
    }

    return 0;
}
 
