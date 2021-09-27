/*
 * led.h
 *
 *  Created on: Sep 27, 2021
 *      Author: TOSHIBA PC
 */

#ifndef LED_H_
#define LED_H_

#include "dio.h"

typedef struct
{
	EN_port port;
	uint8_t pin;

}ST_LED_config_t;


void LED_init(ST_LED_config_t* config);
void LED_on(ST_LED_config_t* led);
void LED_off(ST_LED_config_t* led);



#endif /* LED_H_ */
