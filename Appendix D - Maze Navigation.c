/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/faq/how-to-input-a-multiple-digits-number-using-the-keypad
 */
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define I2C_SLAVE_ADDR 0x04

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte pin_rows[ROW_NUM] = {18, 5, 17, 16};   //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {4, 0, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

LiquidCrystal lcd(19, 23, 15, 26, 25, 14);

String inputString;
long inputInt;
long timer;
String distinputString;
int distinputInt;



void setup() {
  Wire.begin();
  Serial.begin(9600);
  inputString.reserve(10); // maximum number of digit for a number is 10, change if needed

 lcd.begin(16, 2);

 //lcd.print("Vehicle is:");



}

//here we have the motor functions thatll be used to make the car move when certain digits are pressed
void MoveTheCar(int leftMotor_speed, int rightMotor_speed, int servoAngle)
 {
   //if (millis() - timer > 1000) {
  Wire.beginTransmission(I2C_SLAVE_ADDR);
  // Serial.println("sending");
  // Serial.println(leftMotor_speed);
  // Serial.println(rightMotor_speed);
  // Serial.println(servoAngle);
  Wire.write((byte)((leftMotor_speed & 0x0000FF00) >> 8));
  Wire.write((byte)(leftMotor_speed & 0x000000FF));
  Wire.write((byte)((rightMotor_speed & 0x0000FF00) >> 8));
  Wire.write((byte)(rightMotor_speed & 0x000000FF));
  Wire.write((byte)((servoAngle & 0x0000FF00) >> 8));
  Wire.write((byte)(servoAngle & 0x000000FF));
  Wire.endTransmission();
  //  delay(100);
  //  timer = millis();
   }

 //}


//  float encoder_count(){
//    Wire.requestFrom(I2C_SLAVE_ADDR, 2); //get position of encoder
//    int position = wire.read();  //encoder psition stored

//   int diameter = "10";
//   int distance = pi*diameter; //one rotation
//   enc1_count = dist/distance;
//   return(enc1_count);


 //}

void loop() {
  char key = keypad.getKey();

  if (key) {


    if (key >= '0' && key <= '9') {     // only act on numeric keys
      inputString += key;               // append new character to input string
      Serial.println(key);

    } else if (key == '#') {
      if (inputString.length() > 0) {
        inputInt = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        //inputString = "";               // clear input
        // DO YOUR WORK HERE
long n;
int m = 0;
int b;
int keyPressed;
char keyPressed1;
char dist;
int onez;
int twoz;
int threez;
int fourz;
int fivez;
int sixz;
int ninez;
Serial.println("you entered this many numbers: ");
Serial.println(inputString.length());






for (n = 0; n<inputString.length(); n++ ){
  int m = 0;
  distinputString = "";

  delay(1000);
key = inputString[n];
//keyPressed = int(keyPressed1);
  // Serial.println(key);
//  if (key){
  if (key == '1'){
    Serial.println("FORWARDS");
      //lcd.setCursor(0, 1);

    Serial.println("enter distance:");
    while (m != '1000') {
    char dist = keypad.waitForKey();
    Serial.println(dist);
    if (dist >= '0' && dist <= '9') {     // only act on numeric keys
      distinputString += dist;               // append new character to input strin
    } else if (dist == '#') {
      if (distinputString.length() > 0) {
        distinputInt = distinputString.toInt();
        onez = distinputInt;
        m = '1000';
        break;
      }
      }
    }

  Serial.println(distinputInt);
  //lcd.print("Moving Forward ");
    // MoveTheCar(100, 100, 90);
    //delay(distinputInt);
  }
  else if (key == '2'){
  Serial.println("BACKWARDS");
      //lcd.setCursor(0, 1);

          Serial.println("enter distance:");
    while (m != '1000') {
    char dist = keypad.waitForKey();
    Serial.println(dist);
    if (dist >= '0' && dist <= '9') {     // only act on numeric keys
      distinputString += dist;               // append new character to input strin
    } else if (dist == '#') {
      if (distinputString.length() > 0) {
        distinputInt = distinputString.toInt();
        twoz = distinputInt;
        m = '1000';
      }
      }
    }
Serial.println(distinputInt);
  //lcd.print("Moving Back");
  // MoveTheCar(-100, -100, 90);
  // delay(distinputInt);
  }
  else if (key == '3'){
  Serial.println("RIGHT");
    //lcd.setCursor(0, 1);

        Serial.println("enter distance:");
    while (m != '1000') {
    char dist = keypad.waitForKey();
    Serial.println(dist);
    if (dist >= '0' && dist <= '9') {     // only act on numeric keys
      distinputString += dist;               // append new character to input strin
    } else if (dist == '#') {
      if (distinputString.length() > 0) {
        distinputInt = distinputString.toInt();
        threez = distinputInt;
        m = '1000';
        break;
      }
      }
    }
Serial.println(distinputInt);
  //lcd.print("Turning Right ");
  // MoveTheCar(100, 100, 135);
  // delay(distinputInt);
  }
  else if (key == '4'){
  Serial.println("LEFT");
   // lcd.setCursor(0, 1);

        Serial.println("enter distance:");
    while (m != '1000') {
    char dist = keypad.waitForKey();
    Serial.println(dist);
    if (dist >= '0' && dist <= '9') {     // only act on numeric keys
      distinputString += dist;               // append new character to input strin
    } else if (dist == '#') {
      if (distinputString.length() > 0) {
        distinputInt = distinputString.toInt();
        fourz = distinputInt;
        m = '1000';
      }
      }
    }

 // lcd.print("Turning Left  ");
  // MoveTheCar(100, 100, 45);
  // delay(distinputInt);
  }
 else if (key == '5'){
  Serial.println("BACKWARD LEFT");
  //lcd.setCursor(0, 1);

      Serial.println("enter distance:");
    while (m != '1000') {
    char dist = keypad.waitForKey();
    Serial.println(dist);
    if (dist >= '0' && dist <= '9') {     // only act on numeric keys
      distinputString += dist;               // append new character to input strin
    } else if (dist == '#') {
      if (distinputString.length() > 0) {
        distinputInt = distinputString.toInt();
        fivez = distinputInt;
        m = '1000';
      }
      }
    }

 // lcd.print("Reversing Left  ");
  // MoveTheCar(-100, -100, 135);
  // delay(distinputInt);
 }
 else if (key == '6'){
  Serial.println("BACKWARD RIGHT");
   // lcd.setCursor(0, 1);

        Serial.println("enter distance:");
    while (m != '1000') {
    char dist = keypad.waitForKey();
    Serial.println(dist);
    if (dist >= '0' && dist <= '9') {     // only act on numeric keys
      distinputString += dist;               // append new character to input strin
    } else if (dist == '#') {
      if (distinputString.length() > 0) {
        distinputInt = distinputString.toInt();
        sixz = distinputInt;
        m = '1000';
      }
      }
    }

  //lcd.print("Reversing Right");
  // MoveTheCar(-100, -100, 45);
  // delay(distinputInt);
 }
 else if (key == '7'){
  Serial.println("FORWARD");
  // MoveTheCar(100, 100, 90);
  // delay(distinputInt);
 }
 else if (key == '8'){
   Serial.println("---------");
  for (int l = 0; l<inputString.length(); l++ ){
    key = inputString[l];
    Serial.println(key);
    // for (b = 0; b<distinputString.length(); b++ ){

      if (key == '1'){
        MoveTheCar(100, 100, 90);
        lcd.setCursor(0, 1);
        //Serial.println(onez);
        delay(onez);
        Serial.println(onez);
        lcd.print("Moving forward");
      }
      else if (key == '2'){
        MoveTheCar(-100, -100, 90);
        lcd.setCursor(0, 1);
        delay(twoz);
        Serial.println(twoz);
        lcd.print("Moving Backward");
      }
      else if (key == '3'){
        MoveTheCar(100, 100, 135);
        lcd.setCursor(0, 1);
        //Serial.println(threez);
        delay(threez);
        Serial.println(threez);
        lcd.print("Moving right");
      }
      else if (key == '4'){
        MoveTheCar(100, 100, 45);
        lcd.setCursor(0, 1);
        delay(fourz);
        Serial.println(fourz);
        lcd.print("Moving left");
      }
      else if (key == '5'){
        MoveTheCar(-100, -100, 135);
        lcd.setCursor(0, 1);
        delay(fivez);
        Serial.println(fivez);
        lcd.print("backwards right");
      }
      else if (key == '6'){
        MoveTheCar(-100, -100, 45);
        lcd.setCursor(0, 1);
        delay(sixz);
        lcd.print("Backwards left");
      }
      else if (key == '7'){
        MoveTheCar(100, 100, 90);
        lcd.setCursor(0, 1);
        delay(distinputString[n]);
        lcd.print("Moving forward");
      }
      else if (key == '8'){
        MoveTheCar(0, 0, 90);
        lcd.setCursor(0, 1);
        delay(distinputString[n]);
        lcd.print("stopping");
      }
      else if (key == '9'){
        MoveTheCar(0, 0, 90);
        lcd.setCursor(0, 1);
        delay(ninez);
        Serial.println(ninez);
        lcd.print("stopping");
      }
    }
 //}

 }
 else if (key == '9'){
  Serial.println("STOP");
     // lcd.setCursor(0, 1);

  //lcd.print("Stopping");
       Serial.println("enter distance:");
    while (m != '1000') {
    char dist = keypad.waitForKey();
    Serial.println(dist);
    if (dist >= '0' && dist <= '9') {     // only act on numeric keys
      distinputString += dist;               // append new character to input strin
    } else if (dist == '#') {
      if (distinputString.length() > 0) {
        distinputInt = distinputString.toInt();
        ninez = distinputInt;
        m = '1000';
      }
      }
    }
  // MoveTheCar(0, 0, 90);
  // delay(1000);
 }
 else {
  Serial.println(key);
  MoveTheCar(0, 0, 90);
  delay(500);
 }
//}
}


      }
    } else if (key == '*') {
      inputString = "empty";                 // clear input
    }
  }
}
