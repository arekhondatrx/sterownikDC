/*
 * StepperMotor.h
 *
 *  Created on: 01.04.2018
 *      Author: Arkadiusz Hallmann
 *      e-mail: hallmann92@wp.pl
 */


#ifndef STEPPERMOTOR_STEPERMOTOR_H_
#define STEPPERMOTOR_STEPERMOTOR_H_

#include "Arduino.h"


class StepperMotor {
public:
	StepperMotor(int8_t, int8_t, unsigned int);
	virtual ~StepperMotor();

public:
	bool move();
	void resetStepCounter(){stepCounter = 1;}
	int getStepperCounter(){return stepCounter;}

private:
	void moto(unsigned int);
	void moveRight(uint8_t);
	void moveLeft(uint8_t);


private:
	unsigned long time;
	bool state;
	bool direction;
	uint8_t steps;
	uint8_t stepPin;
	uint8_t dirPin;
	uint8_t countRightSteps;
	uint8_t countLeftSteps;
	int stepCounter;
	unsigned int stepDelay;
};

#endif /* STEPPERMOTOR_STEPERMOTOR_H_ */
