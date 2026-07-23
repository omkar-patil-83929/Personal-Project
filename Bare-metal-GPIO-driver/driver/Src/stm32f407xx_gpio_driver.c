
/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Apr 26, 2025
 *      Author: omkar
 */

#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx.h"

/*
 * peripheral clock setup API
 */

/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{

		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DI();
		}
	}

}

/*
 * GPIO init/DeInit API
 */
/*********************************************************************
 * @fn      		  - GPIO_Init
 *
 * @brief             - This function initialise required mode of port  and respective pin
 *
 * @param[in]         - base address of the gpio Handle structure
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0 ;
	//1. configure the mode of gpio pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->MODER |= temp;

	}
	else
	{
		//it is interrupt part
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			//1.configure the FTSR
			EXTI->FTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			//1.configure the RTSR
			EXTI->RTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			//1.configure both FTSR and RTSR
			EXTI->RTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->FTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}
		//2.configure GPIO port selection in SYSCFG_EXTICR  register.

		uint32_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
		uint32_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[temp1] |= portcode << ( temp2 * 4);


		//3.enable exti interrupt delivery using IMR.
		EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	}
	temp = 0;
	//2.configure the speed
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;
	//3.configure pupd setting
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp = 0 ;
	//4.configure the otype
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (1 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	temp = 0 ;

	//5.configure the alt functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint32_t temp1,temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8 ;  //this is for choose register
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;  // this for configure pin
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0XF << ( 4 * temp2));

		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << ( 4 * temp2));


	}

}


/*
 * GPIO read write API
 */
/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPin() *
 * @brief             - This function read current status of respective pin
 *
 * @param[in]         - Base Address of GPIO Handle Structure
 * @param[in]         -GPIO pin number
 * @param[in]         -
 *
 * @return            -  uint8_t pin status i.e.HIGH or LOW
 *
 * @Note              -  none

 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	uint8_t value  = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x1);
	return (value);
}
/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort() *
 * @brief             - This function read current status of respective port
 *
 * @param[in]         - Base Address of GPIO register Structure
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  uint16_t port status
 *
 * @Note              -  none

 */
uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = pGPIOx->IDR;
	return (value);
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin() *
 * @brief             - write set or reset to respective pin
 *
 * @param[in]         - Base Address of GPIO register structure
 * @param[in]         - Pin number on which you want to write 1 or 0.
 * @param[in]         - val is value i.e. 1 or 0.
 *
 * @return            - void
 *
 * @Note              -  none

 */

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t val)
{
	//pGPIOx->ODR |= (value << PinNumber);  this is also correct logic

	if(val == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= ( 1 << PinNumber);  // set 1 to respective pin number.
	}
	else
	{
		//pGPIOx->ODR |= ( 0 << PinNumber); // set 0 to respective pin number.
		pGPIOx->ODR &= ~( 1 << PinNumber );
	}
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort() *
 * @brief             - write set or reset to respective port
 *
 * @param[in]         - Base Address of GPIO register structure
 * @param[in]         -
 *  * @param[in]      - val is value i.e. 1 or 0.
 *
 * @return            - void
 *
 * @Note              -  none

 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t val)
{
	pGPIOx->ODR = val;
}
/*********************************************************************
 * @fn      		  - GPIO_TogglePin() *
 * @brief             - write  Toggle respective pin
 *
 * @param[in]         - Base Address of GPIO register structure
 * @param[in]         - Pin number on which you want toggle
 * @param[in]         -
 *
 * @return            - void
 *
 * @Note              -  none

 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 * IRQ configuration and ISR Handling API
 */
/*********************************************************************
 * @fn      		  - GPIO_IRQInterruptConfig() *
 * @brief             - enable and disable interrupt w.r.t. IRQ number using ISER and ICER register.
 *
 * @param[in]         - IRQ number specified in MCU reference manual
 * @param[in]         - EnorDi  for enable and disable  irq
 * @param[in]         -
 *
 * @return            - void
 *
 * @Note              -  none

 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber,uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(IRQNumber <= 31)
		{
			*NVIC_ISER0 |= ( 1 << IRQNumber);
		}
		else if(IRQNumber > 31 && IRQNumber <= 64)
		{
			*NVIC_ISER1  |= (1 << (IRQNumber % 32));
		}
		else if(IRQNumber > 64 && IRQNumber <= 96)
		{
			*NVIC_ISER2  |= ( 1 << (IRQNumber % 64));
		}
	}
	else
	{
				if(IRQNumber <= 31)
				{
							*NVIC_ICER0 |= ( 1 << IRQNumber);
				}
				else if(IRQNumber > 31 && IRQNumber <= 64)
				{
							*NVIC_ICER1 |= ( 1 << (IRQNumber % 32));
				}
				else if(IRQNumber > 64 && IRQNumber <= 96)
				{
							*NVIC_ICER2 |= ( 1 << (IRQNumber % 64));
				}
	}
}
/*********************************************************************
 * @fn      		  - GPIO_IRQPriorityConfig() *
 * @brief             - set priority odf respective IRQ number.
 *
 * @param[in]         - IRQ number specified in MCU reference manual
 * @param[in]         - priority number i.e. lower the prioroty number highest the priority.
 * @param[in]         -
 *
 * @return            - void
 *
 * @Note              -  none

 */
void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority)
{
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;
	uint8_t shift_amount = ( 8 * iprx_section) + ( 8 - NO_PR_BITS_IMPLEMENTED) ;

	*(NVIC_IPR0 + iprx) |= (IRQPriority << shift_amount);
}
void GPIO_IRQHandling(uint8_t PinNumber)
{
	if(EXTI->PR & (1 << PinNumber))
	{
		EXTI->PR |= ( 1 << PinNumber); //it actually clear pending register.in EXTI circuit.

	}

}














