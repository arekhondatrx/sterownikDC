/*
 * StepperMotor.cpp
 *
 *  Created on: 01.04.2018
 *      Author: Arkadiusz Hallmann
 *      e-mail: hallmann92@wp.pl
 */

#include "StepperMotor.h"

StepperMotor::StepperMotor(int8_t stepPin, int8_t dirPin, unsigned int stepDelay) {

	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);

	time = micros();
	state = true;
	countRightSteps = 0;
	countLeftSteps = 0;
	stepCounter = 0;
	steps = 0;
	direction = false;
	this->stepPin = stepPin;
	this->dirPin = dirPin;
	this->stepDelay = stepDelay;
}

StepperMotor::~StepperMotor() {

}

void StepperMotor::moto(unsigned int delay){

	if(micros() - time > delay){
		digitalWrite(stepPin, state);
		state = !state;
		time = micros();
		stepCounter++;
	}
}

bool StepperMotor::move(){

	digitalWrite(dirPin, direction);

	if(stepCounter < 2 * steps){
		moto(stepDelay);
		return false;
	}
	else{
		return true;
	}
}

void StepperMotor::moveRight(uint8_t steps){

	countRightSteps = steps;
	this->steps =  steps + countLeftSteps;
	direction = true;
	countLeftSteps = 0;
	stepCounter = 0;

}

void StepperMotor::moveLeft(uint8_t steps){

	countLeftSteps = steps;
	this->steps =  steps + countRightSteps;
	direction = false;
	countRightSteps = 0;
	stepCounter = 0;

}
