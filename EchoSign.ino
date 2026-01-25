//EchoSign 
//TECH TALK 2023-24 ADIS



// IMPORTS THE LIBRARIES USED FOR THIS DEVICE
#include <math.h>
#include <SoftwareSerial.h>


// CONNECT THE HC-05 MODULE TO THE "HC-05-BT" SOCKET ON THE ECHOSIGN BOARD
SoftwareSerial mySerial(2,3);


// CONNECT THE FLEX SENSORS TO FLEX SENS0RS SOCKET ON THE ECHOSIGN BOARD
const int flexPin0 = A0; 
const int flexPin1 = A1; 
const int flexPin2 = A2; 
const int flexPin3 = A3; 
const int flexPin4 = A4; 


// CONNECT THE ADXL335 SENSOR TO ADXL335 SOCKET ON THE ECHOSIGN BOARD
const int x_out = A5; 
const int y_out = A6; 
const int z_out = A7; 


// INITIALISES THE SERIAL COM PORTS
void setup() {
  Serial.begin(9600); 
  mySerial.begin(9600);
}


//ASSIGNS AND PRINTS THE THE SENSOR VALUE TO THE SERIAL AND BLUETOOTH COM PORTS TO CONVERT RAW DATA TO USEFUL DATA USING PYTHON.
void loop() {
  int flexValue0;
  int flexValue1;
  int flexValue2;
  int flexValue3;
  int flexValue4;
  int x_adc_value, y_adc_value, z_adc_value; 
  double x_g_value, y_g_value, z_g_value;
  double roll, pitch, yaw;
  flexValue0 = analogRead(flexPin0);
  flexValue1 = analogRead(flexPin1);
  flexValue2 = analogRead(flexPin2);
  flexValue3 = analogRead(flexPin3);
  flexValue4 = analogRead(flexPin4);
  x_adc_value = analogRead(x_out); /* Digital value of voltage on x_out pin */ 
  y_adc_value = analogRead(y_out); /* Digital value of voltage on y_out pin */ 
  z_adc_value = analogRead(z_out); /* Digital value of voltage on z_out pin */ 
  Serial.print("x = ");
  Serial.print(x_adc_value);
  Serial.print("      ");
  Serial.print("y = ");
  Serial.print(y_adc_value);
  Serial.print("      ");
  Serial.print("z = ");
  Serial.print(z_adc_value);
  Serial.print("      ");
  Serial.print("F0 = ");
  Serial.print(flexValue0);
  Serial.print("   ");
  Serial.print("F1 = ");
  Serial.print(flexValue1);
  Serial.print("   ");
  Serial.print("F2 = ");
  Serial.print(flexValue2);
  Serial.print("   ");
  Serial.print("F3 = ");
  Serial.print(flexValue3);
  Serial.print("   ");
  Serial.print("F4 = ");
  Serial.print(flexValue4);
  Serial.print("   ");  
  Serial.print("\n\n");




  mySerial.print("x = ");
  mySerial.print(x_adc_value);
  mySerial.print(",");
  mySerial.print("y = ");
  mySerial.print(y_adc_value);
  mySerial.print(",");
  mySerial.print("z = ");
  mySerial.print(z_adc_value);
  mySerial.print(",");
  mySerial.print("F0 = ");
  mySerial.print(flexValue0);
  mySerial.print(",");
  mySerial.print("F1 = ");
  mySerial.print(flexValue1);
  mySerial.print(",");
  mySerial.print("F2 = ");
  mySerial.print(flexValue2);
  mySerial.print(",");
  mySerial.print("F3 = ");
  mySerial.print(flexValue3);
  mySerial.print(",");
  mySerial.print("F4 = ");
  mySerial.print(flexValue4);
  mySerial.print("\n"); 

  delay(1000);
  

}
