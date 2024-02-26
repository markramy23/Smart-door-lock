/*
 * timer1.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mark
 */

#ifndef TIMER1_H_
#define TIMER1_H_
#include "std_types.h"


/****************************************************************************************
 *                              Type Declaration                                        *
 ****************************************************************************************/


/*enum for all the modes supported by timer1*/
typedef enum{
	NORMAL,PWM_8BIT,PWM_9BIT,PWM_10BIT,CTC_OCR1A,FAST_PWM_8BIT,
	FAST_PWM_9BIT,FAST_PWM_10BIT,PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1,
	PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A,CTC_ICR1,RESERVED,FAST_PWM_ICR1,
	FAST_PWM_OCR1A
}Timer1_Mode;


/*enum to select the prescaler for timer 1*/
typedef enum{
	NO_CLOCK,CLK_1,CLK_8,CLK_64,CLK_256,CLK_1024,EXTERNAL_FALLING,
	EXTERNAL_RISING
}Timer1_Prescaler;



/*structure to hold the configuration of timer 1 to use it during initialization*/
typedef struct{
	uint16 initial_vlaue;
	uint16 compare_value;
	Timer1_Prescaler prescaler;
	Timer1_Mode mode;

}Timer1_ConfigType;



/**************************************************************************************
 *                                FUNCTIONS PROTOTYPES
 **************************************************************************************/

/*
 * Description : Function to initialize the Timer driver.
 * Inputs: pointer to the configuration structure with type Timer1_ConfigType.
 * Return: None
 */
void Timer1_init(const Timer1_ConfigType *Config_Ptr);






/*
 * Description : Function to disable the Timer1.
 *  Inputs: None
 *  Return: None
 */
void Timer1_deInit(void);





/*
 * Description: Function to set the Call Back function address.
 *  Inputs: pointer to Call Back function.
 *   Return: None
 */
void Timer1_setCallBack(void(*a_ptr)(void));


#endif /* TIMER1_H_ */
