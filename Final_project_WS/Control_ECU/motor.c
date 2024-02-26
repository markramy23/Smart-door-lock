/*
 * motor.c
 *	Description: Dc motor driver to operate dc motor with PWM signal
 *  Created on: Oct 13, 2023
 *      Author: Mark
 */

#include "motor.h"
#include "pwm.h"
#include "gpio.h"
#include "common_macros.h"

/*************************************************************************
 *                         FUNCTIONS DEFINITIONS                         *
 *************************************************************************/

void DcMotor_init(){

	/*Setup the two pins of the motor as output pins
	 * and write logic low to both of them to stop the motor
	 * at the beginning*/
	GPIO_setupPinDirection(DC_MOTOR_IN1_PORT,DC_MOTOR_IN1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN2_PORT,DC_MOTOR_IN2_PIN,PIN_OUTPUT);
	GPIO_writePin(DC_MOTOR_IN1_PORT,DC_MOTOR_IN1_PIN,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_IN2_PORT,DC_MOTOR_IN2_PIN,LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	/*Setup the state of the motor by writing on it's pins*/
	GPIO_writePin(DC_MOTOR_IN1_PORT,DC_MOTOR_IN1_PIN,GET_BIT(state,0));
	GPIO_writePin(DC_MOTOR_IN2_PORT,DC_MOTOR_IN2_PIN,GET_BIT(state,1));
	/*setup the speed of the motor by generating a PWM signal with the suitable
	 * duty cycle to generate this speed*/
	PWM_Timer0_start(speed);

}
