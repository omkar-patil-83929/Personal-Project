/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Apr 26, 2025
 *      Author: omkar
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/*
 * This is Configuration structure for Gpio pin.
 */
typedef struct
{
	uint8_t GPIO_PinNumber; //@GPO_PinNumber
	uint8_t GPIO_PinMode; //possible value from @GPIO_MODE
	uint8_t GPIO_PinSpeed; // possible value from @GPIO_SPEED
	uint8_t GPIO_PinPuPdControl; //possible value from @GPIO_PULL_UP_PULL_DOWN
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;






/*
 * this is handle structure for gpio pin.
 */

typedef struct
{

	GPIO_RegDef_t *pGPIOx; //This hold base address of GPIO to which pin belong
	GPIO_PinConfig_t GPIO_PinConfig;


}GPIO_Handle_t;

/*@GPO_PinNumber
 * GPIO PIN NUMBER
 */
#define GPIO_PIN_NO_0 	   0
#define GPIO_PIN_NO_1 	   1
#define GPIO_PIN_NO_2 	   2
#define GPIO_PIN_NO_3 	   3
#define GPIO_PIN_NO_4 	   4
#define GPIO_PIN_NO_5 	   5
#define GPIO_PIN_NO_6 	   6
#define GPIO_PIN_NO_7 	   7
#define GPIO_PIN_NO_8 	   8
#define GPIO_PIN_NO_9 	   9
#define GPIO_PIN_NO_10 	   10
#define GPIO_PIN_NO_11 	   11
#define GPIO_PIN_NO_12	   12
#define GPIO_PIN_NO_13	   13
#define GPIO_PIN_NO_14	   14
#define GPIO_PIN_NO_15	   15
/*
 * @GPIO_MODE
 * GPIO pin possible  mode Register
 */

#define GPIO_MODE_IN   		0
#define GPIO_MODE_OUT   	1
#define GPIO_MODE_ALTFN     2
#define GPIO_MODE_ANALOG    3
#define GPIO_MODE_IT_FT     4
#define GPIO_MODE_IT_RT     5
#define GPIO_MODE_IT_RFT    6

/*
 * GPIO pin possible output type
 */
#define GPIO_OP_TYPE_PP      0
#define GPIO_OP_TYPE_OD      1

/*
 * @GPIO_SPEED
 * gpio pin possible output speed
 */
#define GPIO_SPEED_LOW      	0
#define GPIO_SPEED_MEDIUM    	1
#define GPIO_SPEED_HIGH      	2
#define GPIO_SPEED_VERY_HIGH 	3


/*
 * @GPIO_PULL_UP_PULL_DOWN
 *GPIO PIN PULL UP AND PULL DOWN CONFIG MACRO
 */
#define 	GPIO_NO_PUPD        0
#define 	GPIO_PU             1
#define     GPIO_PD				2



/*
 * peripheral clock setup API
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t EnOrDi);

/*
 * GPIO init/DeInit API
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);


/*
 * GPIO read write API
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
 uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t val);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t val);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);

/*
 * IRQ configuration and ISR Handling API
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber,uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);

























#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
