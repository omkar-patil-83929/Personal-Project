/*
 * 003_switch_interrupt.c
 *
 *  Created on: May 1, 2025
 *      Author: omkar
 */


#include "stm32f407xx.h"

#include<string.h>

void delay(void)
{
	for(uint32_t i =0 ; i < 500000/2; ++i)
	{

	}
}
int main(void)
{

	GPIO_Handle_t GpioLed,Gpiobtn;
	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&Gpiobtn,0,sizeof(Gpiobtn));
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
				Gpiobtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
				Gpiobtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
				Gpiobtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

				GPIO_PeriClockControl(GPIOA,ENABLE);
				GPIO_Init(&Gpiobtn);

				GPIO_IRQPriorityConfig(IRQ_NO_EXTI0  ,0);
				GPIO_IRQInterruptConfig(IRQ_NO_EXTI0  ,ENABLE );

	return (0);
}

void EXTI0_IRQHandler(void)
{
	delay();
	GPIO_IRQHandling(GPIO_PIN_NO_0);

	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);

}







