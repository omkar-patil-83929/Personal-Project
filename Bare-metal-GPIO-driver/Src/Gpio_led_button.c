/*
 * 002led_button.c
 *
 *  Created on: Apr 28, 2025
 *      Author: omkar
 */
#include "stm32f407xx.h"
#define BTN_PRESSED 1
void delay()
{
	for(uint32_t i =0 ; i < 500000/2 ; ++i);
}
int main(void)
{

	GPIO_Handle_t GpioLed,Gpiobtn;
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);
	GPIO_Init(&GpioLed);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,0);

	Gpiobtn.pGPIOx = GPIOA;
	Gpiobtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	Gpiobtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	Gpiobtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	Gpiobtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIO_Init(&Gpiobtn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0)  == BTN_PRESSED)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
		}
		delay();

	}
	return (0);
}



