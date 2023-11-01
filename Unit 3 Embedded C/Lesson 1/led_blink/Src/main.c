/*
 * main.c
 *
 *  Created on: Nov 1, 2023
 *      Author: Shehab Elkhaligy
 */

#include <platform_types.h>

#define RCC_BASE   0x40021000
#define GPIOC_BASE 0x40011000


#define RCC_APB2ENR *(volatile uint32_t *) (RCC_BASE+0x18)
#define GPIOC_CRH 	*(volatile uint32_t *) (GPIOC_BASE+0x04)


typedef union {
	volatile uint32_t all_bits;
	struct {
		volatile uint32_t reserved:13;
		volatile uint32_t pin13:1;
	};
}GPIO_ODR_t;

volatile GPIO_ODR_t * GPIO_ODR = (volatile GPIO_ODR_t *)(GPIOC_BASE+0x0C);

int main(void)
{
	// Enable GPIOC peripheral clock
	RCC_APB2ENR |= 1<<4;
	// Configure GPIOC pin 13 as output
	GPIOC_CRH &= 0xFF0FFFFF;
	GPIOC_CRH |= 0x00200000;
	while(1)
	{
		GPIO_ODR->pin13=0;
		for(uint32_t i=0;i<200000;i++);
		GPIO_ODR->pin13=1;
		for(uint32_t i=0;i<200000;i++);
	}
}
