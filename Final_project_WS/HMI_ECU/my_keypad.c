/*
 * keypad.c
 *
 *  Created on: Oct 4, 2023
 *      Author: Mark
 */

#include "my_keypad.h"

#include <util/delay.h>

/*
 * FOR USER SPECEFIED CUSTOM KEYPAD WE USE THE NEXT ARRAY TO STORE THE VALUE OF EACH CORRESPONDING KEY
 */
#ifdef CUSTOM_KEYPAD
#if (KEYPAD_NUM_OF_COLUMNS==3)
char g_keys[SIZE]={KEY1,KEY2,KEY3,KEY4,KEY5,KEY6,KEY7,KEY8,KEY9,KEY10,KEY11,KEY12};
#elif(KEYPAD_NUM_OF_COLUMNS==4)
char g_keys[SIZE]={KEY1,KEY2,KEY3,KEY4,KEY5,KEY6,KEY7,KEY8,KEY9,KEY10,KEY11,KEY12,KEY13,KEY14,KEY15,KEY16};
#endif
#endif



/*
 *to get the key pressed on the keypad
 */
uint8 KEYPAD_getPressedKey(){
	/* to initialize the rows pins as input*/
	for(char i=0;i<KEYPAD_NUM_OF_ROWS;i++){
		GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_FIRST_PIN+i,PIN_INPUT);
	}
	/*to initialize the columns as input pins*/
	for(char i=0;i<KEYPAD_NUM_OF_COLUMNS;i++){
		GPIO_setupPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_FIRST_PIN+i,PIN_INPUT);
	}
	while(1){
		/* loop through the rows pins one by one each time setting the current one only
		 * as output and setting it with logic_high and other as input
		 */
		for(char row=0;row<KEYPAD_NUM_OF_ROWS;row++){
			GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_FIRST_PIN+row,PIN_OUTPUT);
			GPIO_writePin(KEYPAD_ROW_PORT,KEYPAD_ROW_FIRST_PIN+row,KEYPRESSED);
			/*loop through the columns pins and check if any pin is logic_low then the corresponding
			 * key is pressed return the number for that key
			 */
			for(char col=0;col<KEYPAD_NUM_OF_COLUMNS;col++){
				if(GPIO_readPin(KEYPAD_COL_PORT,KEYPAD_COL_FIRST_PIN+col)==KEYPRESSED)
					#if(KEYPAD_NUM_OF_COLUMNS==3)
#ifndef CUSTOM_KEYPAD
								#ifndef STANDARD_KEYPAD
										return KEYPAD_4x3_adjustKeyNumber((row*KEYPAD_NUM_OF_COLUMNS)+col+1);
								#else
									return ((row*KEYPAD_NUM_OF_COLUMNS)+col+1 );
								#endif
#else
									return g_keys[(row*KEYPAD_NUM_OF_COLUMNS)+col+1];
#endif
					#elif(KEYPAD_NUM_OF_COLUMNS==4)
							#ifndef CUSTOM_KEYPAD
								#ifndef STANDARD_KEYPAD
										return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_OF_COLUMNS)+col+1);
								#else
										return ((row*KEYPAD_NUM_OF_COLUMNS)+col+1 );
								#endif
							#else
									return g_keys[(row*KEYPAD_NUM_OF_COLUMNS)+col];
							#endif
					#endif
			}
			GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_FIRST_PIN+row,PIN_INPUT);
			_delay_ms(5);
		}
	}
}
#ifndef STANDARD_KEYPAD
#ifndef CUSTOM_KEYPAD
#if(KEYPAD_NUM_OF_COLUMNS==3)
static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 key_number){
	uint8 key_pressed=key_number;
	switch (key_number){
	case 10:
		key_pressed= '*';
		break;
	case 11:
		key_pressed= 0;
		break;
	case 12:
		key_pressed= '#';
		break;
	}
	return key_pressed;
}
#elif(KEYPAD_NUM_OF_COLUMNS==4)
static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 key_number){
	uint8 key_pressed=key_number;
	switch(key_number){
	case 1:
		key_pressed=7;
		break;
	case 2:
		key_pressed=8;
		break;
	case 3:
		key_pressed=9;
		break;
	case 4:
		key_pressed='%';
		break;
	case 5:
		key_pressed=4;
		break;
	case 6:
		key_pressed=5;
		break;
	case 7:
		key_pressed=6;
		break;
	case 8:
		key_pressed='*';
		break;
	case 9:
		key_pressed=1;
		break;
	case 10:
		key_pressed=2;
		break;
	case 11:
		key_pressed=3;
		break;
	case 12:
		key_pressed='-';
		break;
	case 13:
		key_pressed=13;
		break;
	case 14:
		key_pressed=0;
		break;
	case 15:
		key_pressed='=';
		break;
	case 16:
		key_pressed='+';
		break;
	}
	return key_pressed;
}
#endif
#endif
#endif
