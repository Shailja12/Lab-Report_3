
#include <iostream>

#include <stdio.h>

#include "opencv2/core.hpp"



using namespace std;

using namespace cv;



int main()

{

    Mat image = imread("RedCar.png");



    if (image.data == NULL)

    {

        cout << "No image found! Check path." << endl;

        return 1; //ERROR



    }

    else

    {

        // converts bgr to hsv

        Mat hsv_img;

        cvtColor(image, hsv_img, COLOR_BGR2HSV);



        // creating the variables for grayscale

        Mat grayscale_blue, grayscale_red, grayscale_green;

        Mat RedMask1, RedMask2;



        //blue range

        inRange(hsv_img, Scalar(110,50,50), Scalar(130,255,255), grayscale_blue);

        //green range

        inRange(hsv_img, Scalar(35,100,100), Scalar(75,255,255), grayscale_green);

        //red range

        Scalar redLower1 = Scalar(0,100,100);

        Scalar redUpper1 = Scalar(10,255,255);

        Scalar redLower2 = Scalar(150,100,100);

        Scalar redUpper2 = Scalar(180,255,255);

        inRange(hsv_img, redLower1, redUpper1, RedMask1);

        inRange(hsv_img, redLower2, redUpper2, RedMask2);

        bitwise_or(RedMask1, RedMask2, grayscale_red);



        //counts blue pixels

        int bluePixels = 0;

        bluePixels = countNonZero(grayscale_blue);

        std::cout << "Blue Pixels = " << bluePixels << std::endl;



        //counts green pixels

        int greenPixels = 0;

        greenPixels = countNonZero(grayscale_green);

        std::cout << "Green Pixels = " << greenPixels << std::endl;



        //counts red pixels

        int redPixels = 0;

        redPixels = countNonZero(grayscale_red);

        std::cout << "Red Pixels = " << redPixels << std::endl;





        if (bluePixels > greenPixels && bluePixels > redPixels)

        {

            printf("This image is blue");

            imshow("BGR image", image);

            imshow("HSV image", grayscale_blue);

            waitKey(0);



        }

        else if (greenPixels > bluePixels && greenPixels > redPixels)

        {

            printf("This image is green");

            imshow("BGR image", image);

            imshow("HSV image", grayscale_green);

            waitKey(0);



        }

        else if (redPixels > bluePixels && redPixels > greenPixels)

        {

            printf("This image is red");

            imshow("BGR image", image);

            imshow("HSV image", grayscale_red);

            waitKey(0);

        }

    }

}
