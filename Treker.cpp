#include "Treker.h"

#include "PWM/DriverPWM.h"

String serialInput = "";
int serialInputAsInt = 0;

DriverPWM driverPWM;

void setup(){
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  analogWrite(3, 0);

  driverPWM.setPin(3);
  driverPWM.setSoftTime(5);
  Serial.print("PWM: ");
  Serial.println(serialInputAsInt);
}

void loop(){

  if(Serial.available()){
    serialInput = Serial.readStringUntil(';');
    serialInputAsInt = serialInput.toInt();
  }
  driverPWM.PWM(serialInputAsInt);
}
