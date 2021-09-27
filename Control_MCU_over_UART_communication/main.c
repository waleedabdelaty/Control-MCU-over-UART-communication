/*
 * main.c
 *
 *  Created on: Sep 27, 2021
 *      Author: TOSHIBA PC
 */


#include "usart.h"
#include "led.h"


#define MAX_LENGTH 10
#define ASCII_ENTER 13

uint8_t IS_EQUAL(uint8_t* ptr1,uint8_t* ptr2)
{
	uint8_t i=0;
	while(ptr1[i] !='\0' || ptr2[i] !='\0')
	{
		if( ptr1[i] != ptr2[i] )
		{
			return FALSE;
		}
		i++;
	}
	return TRUE;
}
int main(void)
{

	Usart_ConfigType config = {ON,EIGHT,DISABLED,ONE,9600};
	UART_init(&config);


	ST_LED_config_t green_led =  {A,0};
	ST_LED_config_t yellow_led = {A,1};
	ST_LED_config_t red_led =    {A,2};

	LED_init(&green_led);
	LED_init(&yellow_led);
	LED_init(&red_led);

	uint8_t Str[10];
	while(1)
	{
		UART_receiveString(Str); // Receive String from the terminal
		UART_sendString(Str);
		UART_sendByte((uint8_t)ASCII_ENTER);

		if(IS_EQUAL(Str,(uint8_t*)"START"))
		{
			LED_on(&green_led);
			LED_off(&yellow_led);
			LED_off(&red_led);
			UART_sendString("Green LED is on");
			UART_sendByte((uint8_t)ASCII_ENTER);
		}
		else if(IS_EQUAL(Str,(uint8_t*)"WAIT"))
		{
			LED_off(&green_led);
			LED_on(&yellow_led);
			LED_off(&red_led);
			UART_sendString("Yellow LED is on");
			UART_sendByte((uint8_t)ASCII_ENTER);
		}
		else if(IS_EQUAL(Str,(uint8_t*)"STOP"))
		{
			LED_off(&green_led);
			LED_off(&yellow_led);
			LED_on(&red_led);
			UART_sendString("Red LED is on");
			UART_sendByte((uint8_t)ASCII_ENTER);
		}
		else
		{
			UART_sendString("OK\n");
			UART_sendByte((uint8_t)ASCII_ENTER);
		}

	}

}
