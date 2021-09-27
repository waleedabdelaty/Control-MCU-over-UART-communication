#include "led.h"

void LED_init(ST_LED_config_t* config)
{
	EN_port port = config->port;
	uint8_t pin = config->pin;
	DIO_init(port,pin,OUTPUT);
}
void LED_write(ST_LED_config_t* led,uint8_t value)
{
	EN_port port = led->port;
	uint8_t pin = led->pin;
	DIO_write(port,pin,value);
}
void LED_on(ST_LED_config_t* led)
{
	EN_port port = led->port;
	uint8_t pin = led->pin;
	DIO_write(port,pin,HIGH);
}
void LED_off(ST_LED_config_t* led)
{
	EN_port port = led->port;
	uint8_t pin = led->pin;
	DIO_write(port,pin,LOW);
}


