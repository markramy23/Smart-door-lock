/*
 * buzzer.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mark
 */
#include "buzzer.h"
#include "gpio.h"




/**************************************************************************************
 *                                Functions Definition                                *
 **************************************************************************************/

/*
 * Description : Setup the direction for the buzzer pin as output pin through the GPIO driver.
 * Turn off the buzzer through the GPIO.
 */

void Buzzer_Init(void){
	/*initializing the pin of the buzzer as output pin*/
	GPIO_setupPinDirection(BUZZER_PORT_NUM,BUZZER_PIN_NUM,PIN_OUTPUT);
	/*turning off the buzzer at first*/
	GPIO_writePin(BUZZER_PORT_NUM,BUZZER_PIN_NUM,LOGIC_LOW);
}




/*
 * Description : Function to enable the Buzzer through the GPIO.
 */

void Buzzer_on(void){
	/*write logic high to the buzzer pin to enable it*/
	GPIO_writePin(BUZZER_PORT_NUM,BUZZER_PIN_NUM,LOGIC_HIGH);
}




/*
 * Description : Function to disable the Buzzer through the GPIO.
 */

void Buzzer_off(void){
	/*write logic low to the buzzer pin to turn it off*/
	GPIO_writePin(BUZZER_PORT_NUM,BUZZER_PIN_NUM,LOGIC_LOW);
}
