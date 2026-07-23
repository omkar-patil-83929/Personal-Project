/*
 * stm32f407xx.h
 *
 *  Created on: Apr 23, 2025
 *      Author: omkar
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>




#define   __vo             volatile
/*
 * ARM cortex M4 specific NVIC ISERx register Base addresses
 */

#define  NVIC_ISER0      ((uint32_t *)0xE000E100U)
#define  NVIC_ISER1      ((uint32_t *)0xE000E104U)
#define  NVIC_ISER2      ((uint32_t *)0xE000E108U)
#define  NVIC_ISER3      ((uint32_t *)0xE000E10CU)


/*
 * ARM cortex M4 specific NVIC ICERx register Base  addresses
 */

#define  NVIC_ICER0      ((uint32_t *)0XE000E180U)
#define  NVIC_ICER1      ((uint32_t *)0XE000E184U)
#define  NVIC_ICER2      ((uint32_t *)0XE000E188U)
#define  NVIC_ICER3      ((uint32_t *)0XE000E18CU)
/*
 * priority handling specific register Base addresses.
 *
*/
#define NVIC_IPR0        ((uint32_t *)0xE000E400U)
/*
 * NUMBER OF PRIOITY BIT IMPLEMENTED PER BIT FIELD
 */

#define    NO_PR_BITS_IMPLEMENTED  4
/*
 *
 *
 *
 *
 * Base addresses of SRAM AND FLASH MEMORY(MAIN MMEMORY)
 * SYSTEM MEMORY(ROM)
 */


#define FLASH_BASEADDR   (0x08000000U)
#define SRAM1_BASEADDR   (0x20000000U)
#define SRAM2_BASEADDR   (0x2001C000U)
#define ROM   			 (0x1FFF0000U )
#define SRAM             (SRAM1_BASEADDR)


/*
 * Buses base address i.e. AHB1 AHB2 , APB1, APB2
 * peripheral base addresses
 */

#define PERIPH_BASE       (0x40000000U)
#define APB1PERIPH_BASE   (PERIPH_BASE)
#define APB2PERIPH_BASE   (0x40010000U)
#define AHB1PERIPH_BASE   (0x40020000U)
#define AHB2PERIPH_BASE   (0x50000000U)

/*
 * DEFINE Base addresses of those peripheral which hanging on
 * AHB1 bus
 */
#define GPIOA_BASEADDR   (AHB1PERIPH_BASE + 0x0000)   //(bus base address + offset)
#define GPIOB_BASEADDR   (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR   (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR   (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR   (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR   (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR   (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR   (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASEADDR   (AHB1PERIPH_BASE + 0x2000)
#define RCC_BASEADDR     (AHB1PERIPH_BASE + 0x3800)

/*
 * Define base addresses of peripheral which hanging on
 * APB1 Bus
 */

#define SPI2_BASEADDR    (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR    (APB1PERIPH_BASE + 0x3c00)
#define USART2_BASEADDR  (APB1PERIPH_BASE + 0x4400)
#define USART3_BASEADDR  (APB1PERIPH_BASE + 0x4800)
#define UART4_BASEADDR   (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR   (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASEADDR    (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR    (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR    (APB1PERIPH_BASE + 0x5C00)


/*
 * Define base address of peripheral which hanging  on
 * APB2 Bus
 */

#define USART1_BASEADDR (APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR (APB2PERIPH_BASE + 0x1400)
#define SPI1_BASEADDR   (APB2PERIPH_BASE + 0x3000)
#define SYSCFG_BASEADDR (APB2PERIPH_BASE + 0x3800)
#define EXTI_BASEADDR   (APB2PERIPH_BASE + 0x3C00)

/*****************************peripheral register defination structure********************************
 * peripheral defination structure of GPIO
 */

typedef struct
{
	__vo uint32_t MODER;                         //offset 0x00  GPIO port mode register
	__vo uint32_t OTYPER;                       // offset 0x04  GPIO port output type register
	__vo uint32_t OSPEEDR;                      //offset 0x08   GPIO port output speed register
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];                       //offset 0x20   GPIO alternate function low register
										//AFR[0] = AFRL   AFR[1] = AFRH
}GPIO_RegDef_t;
/*
 * peripheral defination structure RCC
 */
typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR ;
	__vo uint32_t CFGR;
	__vo uint32_t CIR ;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	__vo uint32_t reserved0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t reserved1;
	__vo uint32_t reserved2;
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t RESERVED3;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t RESERVED4;
	__vo uint32_t RESERVED5;
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t RESERVED6;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t RESERVED7;
	__vo uint32_t RESERVED8;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t RESERVED9;
	__vo uint32_t RESERVED10;
	__vo uint32_t  SSCGR;
	__vo uint32_t  PLLI2SCFGR;
	__vo uint32_t  PLLSAICFGR;
	__vo uint32_t  DCKCFGR;

}RCC_RegDef_t;

/*
 * peripheral defination structure of SYCFG
 */
typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;

}EXTI_RegDef_t;
/*
 * peripheral defination structure of syscfg
 */
typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
		 uint32_t RESERVED[2];
	__vo uint32_t CMPCR;


}SYSCFG_RegDef_t;
/*
 * peripheral definations (peripheral base address typecasted to respective structure
 */

#define    GPIOA       ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define    GPIOB       ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define    GPIOC       ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define    GPIOD       ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define    GPIOE       ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define    GPIOF       ((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define    GPIOG       ((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define    GPIOH       ((GPIO_RegDef_t *)GPIOH_BASEADDR)
#define    GPIOI       ((GPIO_RegDef_t *)GPIOI_BASEADDR)
#define    RCC   	   ((RCC_RegDef_t *)RCC_BASEADDR)
#define    EXTI        ((EXTI_RegDef_t *)EXTI_BASEADDR)
#define    SYSCFG      ((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)



/*
 * clock enable macro for GPIOx peripheral WHICH HANG ON AHB1 BUS
 */

#define GPIOA_PCLK_EN()   ( RCC->AHB1ENR |= (1 << 0 ))  // WE ENABLE PORT A CLOCK
#define GPIOB_PCLK_EN()   ( RCC->AHB1ENR |= (1 << 1 ))
#define GPIOC_PCLK_EN()   ( RCC->AHB1ENR |= (1 << 2 ))
#define GPIOD_PCLK_EN()   ( RCC->AHB1ENR |= (1 << 3 ))
#define GPIOE_PCLK_EN()   ( RCC->AHB1ENR |= (1 << 4 ))
#define GPIOF_PCLK_EN()   ( RCC->AHB1ENR |= (1 << 5 ))
#define GPIOG_PCLK_EN()   ( RCC->AHB1ENR |= (1 << 6 ))
#define GPIOH_PCLK_EN()   ( RCC->AHB1ENR |= (1 << 7 ))
#define GPIOI_PCLK_EN()   ( RCC->AHB1ENR |= (1 << 8 ))  //WE ENABLE PORT I CLOCK


/*
 * CLOCK ENABLE MACRO FOR I2C PERIPHERAL
 */
#define I2C1_PCLK_EN()	  ( RCC->APB1ENR |= (1 << 21 ))
#define I2C2_PCLK_EN()    ( RCC->APB1ENR |= (1 << 22 ))
#define I2C3_PCLK_EN()    ( RCC->APB1ENR |= (1 << 23 ))

/*
 * CLOCK ENABLE MACRO FOR SPI PERIPHERAL
 */
#define SPI2_PCLK_EN()    ( RCC->APB1ENR |= (1 << 14 ))
#define SPI3_PCLK_EN()    ( RCC->APB1ENR |= (1 << 15 ))

/*
 * CLOCK ENABLE MACRO FOR USART PERPHERAL WHICH HANG ON APB1 BUS
 */
#define USART2_PCLK_EN()   ( RCC->APB1ENR |= (1 << 17 ))
#define USART3_PCLK_EN()   ( RCC->APB1ENR |= (1 << 18 ))

/*
 * CLOCK ENABLE MACRO FOR UART PERPHERAL WHICH HANG ON APB1 BUS
 */
#define UART4_PCLK_EN()    ( RCC->APB1ENR |= (1 << 19 ))
#define UART5_PCLK_EN()    ( RCC->APB1ENR |= (1 << 20 ))

/*
 * CLOCK ENABLE MACRO FOR USART PERIPHERAL WHICH HANG ON APB2 BUS
 */
#define USART1_PCLK_EN()   ( RCC->APB2ENR |= (1 << 4 ))
#define USART6_PCLK_EN()   ( RCC->APB2ENR |= (1 << 5 ))

/*
 * CLOCK ENABLE MACRO FOR SPI PERIPHERAL WHICH HANG ON APB2 BUS
*/
#define SPI_PCLK_EN()     ( RCC->APB2ENR |= ( 1 << 12 ))

/*
 * CLOCK ENABLE MACRO FOR SYSCFG PERIPHERAL WHICH HANG ON APB2 BUS
 */
#define SYSCFG_PCLK_EN()  ( RCC->APB2ENR |= ( 1 << 14 ))




/*
 * CLOCK DISABLE MACRO FOR GPIOx periphearl which hang on AHB1 BUS
 */

#define GPIOA_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 0 ))  // WE ENABLE PORT A CLOCK
#define GPIOB_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 1 ))
#define GPIOC_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 2 ))
#define GPIOD_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 3 ))
#define GPIOE_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 4 ))
#define GPIOF_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 5 ))
#define GPIOG_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 6 ))
#define GPIOH_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 7 ))
#define GPIOI_PCLK_DI()   ( RCC->AHB1ENR &= ~(1 << 8 ))  //WE ENABLE PORT I CLOCK

/*
 * CLOCK DISABLE MACRO FOR I2C PERIPHERAL which hang on APB1 BUS
 */
#define I2C1_PCLK_DI()	  ( RCC->APB1ENR &= ~(1 << 21 ))
#define I2C2_PCLK_DI()    ( RCC->APB1ENR &= ~(1 << 22 ))
#define I2C3_PCLK_DI()    ( RCC->APB1ENR &= ~(1 << 23 ))

/*
 * CLOCK DISABLE MACRO FOR SPI PERIPHERAL WHICH HANG ON APB1 BUS
 */
#define SPI2_PCLK_DI()    ( RCC->APB1ENR &= ~(1 << 14 ))
#define SPI3_PCLK_DI()    ( RCC->APB1ENR &= ~(1 << 15 ))


/*
 * CLOCK DISABLE MACRO FOR USART PERPHERAL WHICH HANG ON APB1 BUS
 */
#define USART2_PCLK_DI()   ( RCC->APB1ENR &= ~(1 << 17 ))
#define USART3_PCLK_DI()   ( RCC->APB1ENR &= ~(1 << 18 ))

/*
 * CLOCK ENABLE MACRO FOR UART PERPHERAL WHICH HANG ON APB1 BUS
 */
#define UART4_PCLK_DI()    ( RCC->APB1ENR &= ~(1 << 19 ))
#define UART5_PCLK_DI()    ( RCC->APB1ENR &= ~(1 << 20 ))

/*
 * CLOCK DISABLE MACRO FOR USART PERIPHERAL WHICH HANG ON APB2 BUS
 */
#define USART1_PCLK_DI()   ( RCC->APB2ENR &= ~(1 << 4 ))
#define USART6_PCLK_DI()   ( RCC->APB2ENR &= ~(1 << 5 ))

/*
 * CLOCK DISABLE MACRO FOR SPI PERIPHERAL WHICH HANG ON APB2 BUS
*/
#define SPI_PCLK_DI()     ( RCC->APB2ENR &= ~( 1 << 12 ))


/*
 * CLOCK DISABLE MACRO FOR SYSCFG PERIPHERAL WHICH HANG ON APB2 BUS
 */
#define SYSCFG_PCLK_DI()  ( RCC->APB2ENR &= ~( 1 << 14 ))

#define     GPIO_BASEADDR_TO_CODE(x)   ((x == GPIOA) ? 0 : \
										(x == GPIOB) ? 1 : \
										(x == GPIOC) ? 2 : \
										(x == GPIOD) ? 3 : \
										(x == GPIOE) ? 4 : \
										(x == GPIOF) ? 5 : \
										(x == GPIOG) ? 6 : \
										(x == GPIOH) ? 7 : \
										(x == GPIOI) ? 8 : 0 )





/*
 * some generic macro
 */

#define ENABLE          (1)
#define DISABLE  		(0)
#define SET       		ENABLE
#define RESET     		DISABLE
#define GPIO_PIN_SET  	SET
#define GPIO_PIN_RESET 	RESET

/*
 * EXTI interrupt request numer i.e.IRQ number
 */
#define  IRQ_NO_EXTI0   	6
#define  IRQ_NO_EXTI1   	7
#define  IRQ_NO_EXTI2   	8
#define  IRQ_NO_EXTI3   	9
#define  IRQ_NO_EXTI4   	10
#define  IRQ_NO_EXTI9_5 	23
#define  IRQ_NO_EXTI15_10   40




#include "stm32f407xx_gpio_driver.h"

#endif /* INC_STM32F407XX_H_ */
