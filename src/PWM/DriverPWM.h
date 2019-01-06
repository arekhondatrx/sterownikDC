/*
 * DriverPWM.h
 *
 *  Created on: 30.03.2018
 *      Author: Arkadiusz Hallmann
 *      e-mail: hallmann92@wp.pl
 */

#ifndef PWM_DRIVERPWM_H_
#define PWM_DRIVERPWM_H_

#include "Arduino.h"

class DriverPWM {
public:
	DriverPWM();
	DriverPWM(uint8_t pin,uint8_t minPWM = 50, unsigned long softTime = 5);
	virtual ~DriverPWM();

	void PWM(uint8_t pwm = 0);

	// SETERS & GETERS //
	void setPin(uint8_t pin){
		this->pin = pin;
	}

	void setSoftTime(unsigned long softTime){
		this->softTime = softTime;
	}

	void setMinPWM(uint8_t minPWM){
		this->minPWM = minPWM;
	}

private:
	void setUp();
	void preparePWM(uint8_t *pwm);

private:
	uint8_t pin;
	uint8_t actualPWM;
	uint8_t minPWM;
	unsigned long time;
	unsigned long softTime;
	bool zeroPWM;
};

#endif /* PWM_DRIVERPWM_H_ */
