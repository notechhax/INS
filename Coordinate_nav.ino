//#include "NAxisMotion.h"        //Contains the bridge code between the API and the Arduino Environment
//#include <Wire.h>

//NAxisMotion mySensor;           //Object that for the sensor
float cardinal;                 //Variable to store current Cardinal direction
//float travel;                   //variable to hold current direction of travel
//cardinal= constrain(carindal, 0, 360);      //limits cardinal to between 0 and 360
//bool left=false;                //variable to indicate vessel should turn to port
//bool right=false;               //variable to indicate vessel should turn to starboard
float lat_a;               //variable for start latitude  //n&s
float lat_b;               //variable for end latitude
float long_a;              //variable for start longitude //e&e
float long_b;              //variable for end longitude
float angle;               //variable for angle to turn
float x;                   //variable for x difference
float y;                   //variable for y difference


void setup() //This code is executed once
{
  //Peripheral Initialization
  //I2C.begin();                    //Initialize I2C communication to the let the library communicate with the sensor.
  //Sensor Initialization
  //mySensor.initSensor();          //The I2C Address can be changed here inside this function in the library
  //mySensor.setOperationMode(OPERATION_MODE_COMPASS);   //Can be configured to other operation modes as desired
  //mySensor.setPowerMode (POWER_MODE_LOWPOWER);          //set powermode to lowpower
  y = lat_a-lat_b;
  x=long_a-long_b;
  //angle= double   atan2 (double x, double y) // arc tangent of x/y
  float angle = ( atan2 (x, y) * 180/3.14159265 ); // radians to degrees and rounding
}

void loop() //This code is looped forever
{
 Serial.println(cardinal);      //print desired direction of travel
 //travel=mySensor.readMagX();    //update direction of travel
// Serial.println(travel);        //print current direction of travel
 if(x>0 and y>0)
    cardinal = 180+angle;
 if(x<0 and y<0)
    cardinal = angle;
 if(x<0 and y>0)
    cardinal = 360 - angle;
 if(x>0 and y<0)
    cardinal = 180 + angle;
}
