Mat hsvImage, grayImage, equalizedImage;

cvtColor(frame, hsvImage, COLOR_BGR2HSV);

cvtColor(frame, grayImage, COLOR_BGR2GRAY);

equalizeHist(grayImage, equalizedImage);



Mat blackGrayscale;

inRange(hsvImage, Scalar(0,0,0), Scalar(180,255,50), blackGrayscale); // Modify this line to detect black pixels



int framecon[41];

int l;

const int len = 8;

const int framelength = 40;





for(l=0; l<41; l++)

{

    Mat subframe = blackGrayscale(Rect(l*framelength, 0, framelength, blackGrayscale.rows));

    framecon[l] = 100.0 * countNonZero(subframe) / (framelength * blackGrayscale.rows);

    printf("%d ", framecon[l]);

}

printf("\n");



int maxIndex = 0;

int maxPercentage = 0;

for(int i = 0; i < sizeof(framecon) / sizeof(int); i++)

{

    if(framecon[i] > maxPercentage)

    {

        maxIndex = i;

        maxPercentage = framecon[i];

    }

}

int linePosition = (maxIndex + 0.5) * framelength;



// Use the line position to adjust the motor speeds and servo angle

int leftMotor_speed = 0;

int rightMotor_speed = 0;

int servoAngle = 0;

const int center = 160;



if (linePosition < center) {

    // Move left

    leftMotor_speed = 50;

    rightMotor_speed = 100;

    servoAngle = 30;

} else if (linePosition > center) {

    // Move right

    leftMotor_speed = 100;

    rightMotor_speed = 50;

    servoAngle = 150;

} else {

    leftMotor_speed = 100;

               rightMotor_speed = 100;

               servoAngle = 90;

}







               int getFramecon(Mat frame, int x)

{

        int framecon=0;

        int a = 0;

        int b = 0;



        for(a = x-32; a < x ; a++)

        {



        for(b = 0 ; b < 28; b++)

        {



        if(frame.at<unsigned char>(b,a)==255)

        {

        framecon = framecon + 1;



        }



        }

        }



        framecon = ((float)framecon/960)*100;

        return(framecon);

}
