/*
 * DriverPWM.cpp
 *
 *  Created on: 30.03.2018
 *      Author: Arek
 */

#include "DriverPWM.h"

DriverPWM::DriverPWM() {
	setUp();
}

DriverPWM::DriverPWM(uint8_t pin,uint8_t minPWM, unsigned long softTime) {
	this->pin = pin;
	this->minPWM = minPWM;
	this->softTime = softTime;
	setUp();
}

DriverPWM::~DriverPWM() {
	// TODO Auto-generated destructor stub
}

void DriverPWM::setUp(){
	actualPWM = 0;
	minPWM = 50;
	time = micros();
	zeroPWM = true;
}

void DriverPWM::PWM(uint8_t pwm){
	if(millis() - time > softTime && actualPWM != pwm){
		if(actualPWM - pwm < 0){
			actualPWM++;
		}
		if(actualPWM - pwm > 0){
			actualPWM--;
		}
		preparePWM(&pwm);
		analogWrite(pin, actualPWM);
		time = millis();
		Serial.print("aktulny PWM: ");
		Serial.println(actualPWM);
	}
}

void DriverPWM::preparePWM(uint8_t *pwm){
	if(zeroPWM && (*pwm) >= minPWM){
		actualPWM = minPWM;
		zeroPWM = false;
		return;
	}

	if((*pwm) < minPWM){
		actualPWM = 0;
		(*pwm) = 0;
		zeroPWM = true;
		return;
	}
}

