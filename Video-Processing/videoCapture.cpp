#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <string>

using namespace std;
using namespace cv;


//initial min and max HSV filter values.
//these will be changed using trackbars
int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;
//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;
//max number of objects to be detected in frame
const int MAX_NUM_OBJECTS=50;
//minimum and maximum object area
const int MIN_OBJECT_AREA = 20*20;
const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH/1.5;
//names that will appear at the top of each window
const string windowName = "Original Image";
const string windowName1 = "HSV Image";
const string windowName2 = "Thresholded Image";
const string windowName3 = "After Morphological Operations";
const string trackbarWindowName = "Trackbars";
void on_trackbar( int, void* )
{//This function gets called whenever a
	// trackbar position is changed
}



void createTrackbars() {
	//create window for trackbars
	namedWindow(trackbarWindowName,0);
		//create memory to store trackbar name on window
		char TrackbarName[50];
		sprintf( TrackbarName, "H_MIN", H_MIN);
		sprintf( TrackbarName, "H_MAX", H_MAX);
		sprintf( TrackbarName, "S_MIN", S_MIN);
		sprintf( TrackbarName, "S_MAX", S_MAX);
		sprintf( TrackbarName, "V_MIN", V_MIN);
		sprintf( TrackbarName, "V_MAX", V_MAX);
		//create trackbars and insert them into window
		//3 parameters are: the address of the variable that is changing when the trackbar is moved(eg.H_LOW),
		//the max value the trackbar can move (eg. H_HIGH),
		//and the function that is called whenever the trackbar is moved(eg. on_trackbar)
		//                                  ---->    ---->     ---->
		createTrackbar( "H_MIN", trackbarWindowName, &H_MIN, H_MAX, on_trackbar );
		createTrackbar( "H_MAX", trackbarWindowName, &H_MAX, H_MAX, on_trackbar );
		createTrackbar( "S_MIN", trackbarWindowName, &S_MIN, S_MAX, on_trackbar );
		createTrackbar( "S_MAX", trackbarWindowName, &S_MAX, S_MAX, on_trackbar );
		createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar );
		createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar );
}


int main( int, char**) {

	//create slider bars for HSV filtering
	createTrackbars();

	Mat frame;

	namedWindow( "Video Footage", WINDOW_AUTOSIZE);
	VideoCapture cap(0);
	cap >> frame;
	if(!cap.isOpened())
		return -1;

	while(true){


	imshow( "Video Footage", frame);
	if (waitKey(1) == 27)
		break;
	}

return 0;
}


