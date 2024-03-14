# Faced_eyes_detection
This project is C++ language that can detect human face and eyes.

## Prerequisites
- C++ compiler
- OpenCV library

# OpenCV model
I use the OpeCV model to do the detection. In the Opencv it has Haar features.
Haar features are a sequence of rescaled square shape functions proposed by Alfred Haar in 1909. They are similar to convolution kernels taught in the Convolution Neural Networks course. We will apply these haar features to all relevant parts of the face so as to detect human faces.

https://github.com/ChengHao1211/Faced_eyes_detection/assets/113260755/5846694a-c250-46bb-86b0-2e2b1c76f666

To detect eyebrow, we will use Haar feature (image (1)) because forehead and eyebrow form lighter pixels- darker pixel like image. Similarly, to detect lips we use similar to Haar like feature (image(3)) with lighter-darker-lighter pixels. To detect nose, we might use darker-lighter Harr like feature from (image(1)). And so on.

They are a series of classifiers or features used to identify object in an image. Using sliding windows and the number of haar features (increases as the number of stages increases), finally leading to detecting a face or not. There are a total of 38 stages defined for the Viola Jonas Method. Depending upon the sliding window's size and face location, number of features, the face can be detected at a certain stage.

# CascadeClassifier
CascadeClassifier faceCascade, glassCascade;
    faceCascade.load("C:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");
    glassCascade.load("C:\\opencv\\sources\\data\\haarcascades\\haarcascade_eye_tree_eyeglasses.xml");
Here, a scale factor and two CascadeClassifier objects (faceCascade and glassCascade) are defined.
CascadeClassifier is a class for object detection based on the Haar-like features.
The load method is used to load pre-trained cascade classifiers for face and eye detection. These XML files contain the trained models necessary for detection.

#Web camera load
VideoCapture cap(0);
    if (!cap.isOpened()) {
        return 0;
    }
VideoCapture is a class used to capture video from cameras or video files.
Here, a VideoCapture object named cap is created to capture video from the default camera (index 0).

# Mat
 Mat frame;
        cap >> frame;
A Mat object named frame is declared to hold each captured frame from the camera.
The >> operator is used to read a new frame from the camera and store it in the frame matrix.

        Mat grayScale;
        cvtColor(frame, grayScale, COLOR_BGR2GRAY);
cvtColor is a function to convert an image from one color space to another.
Here, it converts the BGR color image (frame) to grayscale and stores the result in grayScale.

# Resize
        resize(grayScale, grayScale, Size(grayScale.size().width / scale, grayScale.size().height/scale));
resize function is used to resize the image to a specified size.
Here, it resizes the grayscale image grayScale to half its original size (scale = 2.0), reducing computational load for detection.

# Face Deteect
        vector<Rect> faces;
        faceCascade.detectMultiScale(grayScale, faces, 1.1, 3, 0, Size(30, 30));
detectMultiScale is a function used for object detection in images. It detects objects (faces in this case) of different sizes in the input image.
Here, it detects faces in the grayscale image grayScale and stores the results (bounding boxes of detected faces) in the faces vector.
