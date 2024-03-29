/*
 * buzzer.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mark
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "std_types.h"
#include "gpio.h"

/**************************************************************************************
 *                                 DEFINITIONS
 **************************************************************************************/

/*define the port and the pin where the buzzer is connected*/
#define BUZZER_PORT_NUM PORTD_ID
#define BUZZER_PIN_NUM	PIN7_ID

/**************************************************************************************
 *                                FUNCTIONS PROTOTYPES
 **************************************************************************************/


/*
 * Description : Setup the direction for the buzzer pin as output pin through the GPIO driver.
 * Turn off the buzzer through the GPIO.
 */
void Buzzer_Init(void);






/*
 * Description : Function to enable the Buzzer through the GPIO.
 */
void Buzzer_on(void);





/*
 * Description : Function to disable the Buzzer through the GPIO.
 */
void Buzzer_off(void);
#endif /* BUZZER_H_ */
