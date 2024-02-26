/*
 * keypad.h
 *
 *  Created on: Oct 4, 2023
 *      Author: Mark
 */

#ifndef MY_KEYPAD_H_
#define MY_KEYPAD_H_
#include "gpio.h"
#include "std_types.h"


/****************************************************************************************
 *                                  definitions                                         *
 ****************************************************************************************/
#define KEYPAD_ROW_PORT PORTC_ID
#define KEYPAD_ROW_FIRST_PIN PIN0_ID
#define KEYPAD_COL_PORT PORTC_ID
#define KEYPAD_COL_FIRST_PIN PIN4_ID
#define KEYPAD_NUM_OF_COLUMNS 4
#define KEYPAD_NUM_OF_ROWS    4
#define KEYPRESSED LOGIC_LOW
#define KEYRELEASED LOGIC_HIGH

/*define if using standarD keypad from 1 to 16
 * IF YOU WANT TO USE STANDARD KEYPAD UNCOMMENT THE NEXT LINE*/

//#define STANDARD_KEYPAD



/*************************************************************************
 *       this part is for the user to customize his own keypad           *
 * ***********************************************************************/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*UNCOMMENT THE NEXT LINE FOR USING YOUR CUSTOM KEYPAD*/
//#define CUSTOM_KEYPAD

#ifdef CUSTOM_KEYPAD
	#define SIZE (KEYPAD_NUM_OF_ROWS*KEYPAD_NUM_OF_COLUMNS)
	typedef enum{

		/*IF YOU ARE USING 4X3 KEYPAD CHANGE KEYS FROM 1 TO 12
		 * USE INTEGER VALUES FOR NUMBERS
		 * FOR CHARACTERS USE ASCII (FOR EXAMPLE: USE '+' FOR SPECEFYING A KEY FOR THE + SIGN */
			KEY1=1,KEY2=2,KEY3=3,KEY4=4,KEY5=5,KEY6=6,KEY7=7,KEY8=8,KEY9=9,KEY10=0,KEY11='-',KEY12='*',KEY13='%',KEY14='+',KEY15='=',KEY16='c'

		#if(KEYPAD_NUM_OF_COLUMNS==4)
			/* IF YOU ARE USING 4X4 KAYPAD CHANGE THESE KEYS ALSO*/
		#endif
}KEY_PAD_KEYS;
#endif

/****************************************************************************************
 *                                   PROTOTYPES                                         *
 ****************************************************************************************/


/*
 * to return the pressed key on the keypad
 */
uint8 KEYPAD_getPressedKey();

#ifndef STANDARD_KEYPAD
	#if(KEYPAD_NUM_OF_COLUMNS==3)
/*
 * mapping the pressed key number to the actual number on the proteus keypad for 4x3 keypad
 */
		static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 key_number);
	#elif(KEYPAD_NUM_OF_COLUMNS==4)
		/*
		 * mapping the pressed key number to the actual number on the proteus keypad for 4x4 keypad
		 */
		static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 key_number);
	#endif
#endif
#endif /* MY_KEYPAD_H_ */
