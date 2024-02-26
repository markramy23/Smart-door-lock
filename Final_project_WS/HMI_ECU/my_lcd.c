/*
 * lcd.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Mark
 */
#include "my_lcd.h"
#include<stdlib.h>
#include "gpio.h"
#include <util/delay.h>



/*
 * send command to lcd
 */
void LCD_sendCommand(uint8 command){
	GPIO_writePin(LCD_RS_PORT,LCD_RS,0);
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT,LCD_ENABLE,1);
	_delay_ms(1);
#if(LCD_BIT_MODE==8)

	GPIO_writePort(LCD_DATA_PORT,command);
	_delay_us(1);
	GPIO_writePin(LCD_RS_PORT,LCD_ENABLE,0);
	_delay_us(1);
#elif(LCD_BIT_MODE==4)

	GPIO_writePin(LCD_DATA_PORT,LCD_DB4,GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5,GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6,GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7,GET_BIT(command,7));
	_delay_ms(1);
	GPIO_writePin(LCD_RS_PORT,LCD_ENABLE,0);
	_delay_ms(1);
	GPIO_writePin(LCD_RS_PORT,LCD_ENABLE,1);
	_delay_ms(1);
	GPIO_writePin(LCD_DATA_PORT,LCD_DB4,GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5,GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6,GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7,GET_BIT(command,3));
	_delay_ms(1);
	GPIO_writePin(LCD_RS_PORT,LCD_ENABLE,0);
	_delay_ms(1);
#endif
}
/*
 * To Write Character on lcd
 */
void LCD_displayChar(uint8 character){
	GPIO_writePin(LCD_EN_PORT,LCD_RS,1);
	_delay_ms(1);
	GPIO_writePin(LCD_EN_PORT,LCD_ENABLE,1);
	_delay_ms(1);
#if(LCD_BIT_MODE==8)
	GPIO_writePort(LCD_DATA_PORT,character);
	_delay_us(1);
	GPIO_writePin(LCD_EN_PORT,LCD_ENABLE,0);
	_delay_us(1);
#elif(LCD_BIT_MODE==4)
	GPIO_writePin(LCD_DATA_PORT,LCD_DB4,GET_BIT(character,4));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5,GET_BIT(character,5));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6,GET_BIT(character,6));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7,GET_BIT(character,7));
	_delay_ms(1);
	GPIO_writePin(LCD_RS_PORT,LCD_ENABLE,0);
	_delay_ms(1);
	GPIO_writePin(LCD_RS_PORT,LCD_ENABLE,1);
	_delay_ms(1);
	GPIO_writePin(LCD_DATA_PORT,LCD_DB4,GET_BIT(character,0));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5,GET_BIT(character,1));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6,GET_BIT(character,2));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7,GET_BIT(character,3));
	_delay_ms(1);
	GPIO_writePin(LCD_RS_PORT,LCD_ENABLE,0);
	_delay_ms(1);
#endif
}
/*
 * TO initialize lcd
 */
void LCD_init(void){
	GPIO_setupPinDirection(LCD_RS_PORT,LCD_RS,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_EN_PORT,LCD_ENABLE,PIN_OUTPUT);
#if(LCD_BIT_MODE==8)
	GPIO_setupPortDirection(LCD_DATA_PORT,PORT_OUTPUT);
	_delay_ms(20);
	LCD_sendCommand(LCD_8BIT_MODE);
#elif(LCD_BIT_MODE==4)
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB4,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB5,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB6,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB7,PIN_OUTPUT);
	_delay_ms(20);
	LCD_sendCommand(LCD_4BIT_MODE_FIRST_COMMAND);
	LCD_sendCommand(LCD_4BIT_MODE_SECOND_COMMAND);
	LCD_sendCommand(LCD_4BIT_MODE);
#endif
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_DISPLAY);

}
/*
 * to display string on lcd
 */
void LCD_displayString(const char *str){
	for(int i=0;str[i]!='\0';i++){
		LCD_displayChar(str[i]);
	}
}
/*
 * to change the position of the cursor on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col){
	uint8 LCD_address;
	switch(row){
	case 0:
		LCD_address=col;
		break;
	case 1:
		LCD_address=col+0x40;
		break;
	case 2:
		LCD_address=col+0x10;
		break;
	case 3:
		LCD_address=col+0x50;
		break;
	}
	LCD_sendCommand(LCD_CURSOR_TO_FIRST_LINE|LCD_address);

}
/*
 * to display string in the desired position
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char* str){
	LCD_moveCursor(row,col);
	LCD_displayString(str);
}
/*
 * to clear display
 */
void LCD_clearScreen(){
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
}
/*
 * to display integers
 */
void LCD_integerToString(int num){
	char buffer[10];
	itoa(num,buffer,10);
	LCD_displayString(buffer);
}
/*
 * to display float numbers
 */
void LCD_floatToString(double num){
	char buffer[20];
	dtostrf(num,5,3,buffer);
	LCD_displayString(buffer);

}
