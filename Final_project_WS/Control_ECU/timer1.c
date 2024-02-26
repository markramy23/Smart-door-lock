/*
 * Timer1.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mark
 */
#include "timer1.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/**************************************************************************************
 *                                Global Variables                                    *
 **************************************************************************************/

static volatile void (*g_callBack_ptr)(void)=NULL_PTR; /*pointer to hold the call back function*/






/**************************************************************************************
 *                                Functions Definition                                *
 **************************************************************************************/

void Timer1_init(const Timer1_ConfigType *Config_Ptr){
	/*configuring WGM10 and WGM11  bits in TCCR1A Register */
	TCCR1A=(TCCR1A&0xFC)|((Config_Ptr->mode)&(0x3));
	/*configuring WGM12 and WGM13 bits in TCCR1B Register*/
	TCCR1B=(TCCR1B&0xE7)|((((Config_Ptr->mode)&(0xC))>>2)<<WGM12);


	TCNT1=Config_Ptr->initial_vlaue; /*Adding the timer initial value*/


	/*configuring the compare register value according to the mode selected*/
	if(Config_Ptr->mode==CTC_OCR1A){
		OCR1A=Config_Ptr->compare_value;
	}
	else if(Config_Ptr->mode==CTC_ICR1){
		OCR1B=Config_Ptr->compare_value;
	}


	/*setting FOC1A and FOC1B as we are using non pwm mode*/
	TCCR1A|=(1<<FOC1A)|(1<<FOC1B);

	/*setting the prescaler configured by the user */
	TCCR1B=(TCCR1B&0xF8)|((Config_Ptr->prescaler)&0x7);

	/*enabling the interrupt of the mode selected*/
	if(Config_Ptr->mode==NORMAL){
		TIMSK=(1<<TOIE1);
	}
	else if(Config_Ptr->mode==CTC_OCR1A){
		TIMSK=(1<<OCIE1A);
	}
	else if(Config_Ptr->mode==CTC_ICR1){
		TIMSK=(1<<OCIE1B);
	}
}

void Timer1_deInit(void){
	/*resetting all the registers of the timer*/
	TCCR1A=0;
	TCCR1B=0;
	TCNT1=0;
	OCR1A=0;
	OCR1B=0;
	TIMSK=0;
}


void Timer1_setCallBack(void(*a_ptr)(void)){
	/*setting the call back function to be executed by the timer */
	g_callBack_ptr=a_ptr;
}




/**************************************************************************************
 *                            Interrupt Handling Routines                             *
 **************************************************************************************/

/*Interrupt handling routines call the call back function */
ISR(TIMER1_OVF_vect){
	if(g_callBack_ptr!=NULL_PTR){
		(*g_callBack_ptr)();
	}
}
ISR(TIMER1_COMPA_vect){
	if(g_callBack_ptr!=NULL_PTR){
		(*g_callBack_ptr)();
	}
}
ISR(TIMER1_COMPB_vect){
	if(g_callBack_ptr!=NULL_PTR){
		(*g_callBack_ptr)();
	}
}
