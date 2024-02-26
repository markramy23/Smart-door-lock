/*
 * pwm.c
 *	Description: Driver to use PWM for Timer0 in atmega32
 *  Created on: Oct 13, 2023
 *      Author: Mark
 */

#include "pwm.h"
#include <avr/io.h>
#include "gpio.h"
void PWM_Timer0_start(uint8 duty_cycle){
	/*
	 * initialize timer0 to generate fast pwm signal of
	 * frequency 500hz with non-inverting mode.
	 */
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01);
	TCNT0=0; /*add 0 in the timer register */
	OCR0=255*((float)duty_cycle/100); /*set the compare value according to the required duty cycle*/
	TCCR0|=(1<<CS01); /*initialize clock with precaler value = FCPU/8*/
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);/*setup oc0 as output pin*/
}
