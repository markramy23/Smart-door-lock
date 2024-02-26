/*
 * lcd.h
 *
 *  Created on: Oct 3, 2023
 *      Author: Mark
 */

#ifndef MY_LCD_H_
#define MY_LCD_H_
#include"std_types.h"
#include "gpio.h"
#include "common_macros.h"
/**************************************************************************************
 *                                 DEFINITIONS
 **************************************************************************************/
#define LCD_DATA_PORT PORTA_ID
#define LCD_RS_PORT   PORTB_ID
#define LCD_RS		  PIN0_ID
#define LCD_EN_PORT   PORTB_ID
#define LCD_ENABLE    PIN1_ID
#define LCD_BIT_MODE		8
#if(LCD_BIT_MODE==4)
#define LCD_DB4 PIN3_ID
#define LCD_DB5 PIN4_ID
#define LCD_DB6 PIN5_ID
#define LCD_DB7 PIN6_ID
#define LCD_4BIT_MODE_FIRST_COMMAND 0x33
#define LCD_4BIT_MODE_SECOND_COMMAND 0x32
#endif
/**************************************************************************************
 *                                COMMANDS
 **************************************************************************************/
#define LCD_CLEAR_DISPLAY 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_SHIFT_DISPLAY_LEFT 0x18
#define LCD_SHIFT_DISPLAY_RIGHT 0x1C
#define LCD_CURSOR_OFF 0x0C
#define LCD_CURSOR_ON 0x0E
#define LCD_CURSOR_BLINKINK 0x0F
#define LCD_CURSOR_LEFT 0x10
#define LCD_CURSOR_RIGHT 0x14
#define LCD_CURSOR_TO_FIRST_LINE 0x80
#define LCD_8BIT_MODE 0x38
#define LCD_4BIT_MODE 0x28
/**************************************************************************************
 *                                FUNCTIONS PROTOTYPES
 **************************************************************************************/


/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command);





/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayChar(uint8 character);




/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col);




/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char* str);



/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen();



/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */

void LCD_init(void);

/*
 * Description :
 * Display the required decimal value on the screen
 */

void LCD_integerToString(int num);


/*
 * Description :
 * Display the required string on the screen
 */

void LCD_displayString(const char *str);



/*
 * Describtion :
 * Display the required float value on the screen
 */
void LCD_floatToString(double num);

#endif /* MY_LCD_H_ */
