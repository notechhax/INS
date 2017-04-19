#include "NAxisMotion.h"        //Contains the bridge code between the API and the Arduino Environment
#include <Wire.h>

NAxisMotion mySensor;           //Object that for the sensor
int cardinal;                 //Variable to store current Cardinal direction
//float travel;                   //variable to hold current direction of travel
cardinal = constrain(carindal, 0, 360);      //limits cardinal to between 0 and 360
bool left=false;                //variable to indicate vessel should turn to port
bool right=false;               //variable to indicate vessel should turn to starboard


void setup() //This code is executed once
{
  //Peripheral Initialization
  I2C.begin();                    //Initialize I2C communication to the let the library communicate with the sensor.
  //Sensor Initialization
  mySensor.initSensor();          //The I2C Address can be changed here inside this function in the library
  mySensor.setOperationMode(OPERATION_MODE_COMPASS);   //Can be configured to other operation modes as desired
  mySensor.setPowerMode (POWER_MODE_LOWPOWER);          //set powermode to lowpower
  cardinal=mySensor.readMagX();
}

void loop() //This code is looped forever
{
 Serial.println(cardinal);      //print desired direction of travel
 //travel=mySensor.readMagX();    //update direction of travel
// Serial.println(travel);        //print current direction of travel
 if(mySensor.readMagX()-cardinal==0)       //case one
    left=false;
    right=false;
 if(mySensor.readMagX()<cardinal and abs(mySensor.readMagX()-cardinal)>180)       //case two
    left=true;
    right=false;
 if(abs(mySensor.readMagX()-cardinal)==180)      //case three
    left=false;
    right=true;
 if(mySensor.readMagX()<cardinal and abs(mySensor.readMagX()-cardinal)<180)     //case four
    left=false;
    right=true;
 if(mySensor.readMagX()>cardinal and abs(mySensor.readMagX()-cardinal)>180)     //case five
    left=false;
    right=true;
 if(mySensor.readMagX()>cardinal and abs(mySensor.readMagX()-cardinal)<180)     //case six
    left=true;
    right=false;
}
