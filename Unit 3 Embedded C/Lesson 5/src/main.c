/*
*	main.c
*	Created on 8 Nov 23
*	Author: Shehab Elkhaligy
*	Description: A simple bare-metal LED toggle code for TM4C123 MCU based on Cortex-M4 processor  
*/


/*
*	SYSCTL_RCGC2_R		: A register to enable gpio ports
*	GPIO_PORTF_DIR_R	: Port F pin direction register
*	GPIO_PORTF_DEN_R	: Port F pin enable register
*	GPIO_PORTF_DATA_R	: Port F pin data register
*/
// There's additional ( ) just for best compatibility when the preprocessor replace the macro
#define SYSCTL_RCGC2_R		(*((volatile unsigned int *)0x400FE108))
#define GPIO_PORTF_DIR_R	(*((volatile unsigned int *)0x40025400))
#define GPIO_PORTF_DEN_R 	(*((volatile unsigned int *)0x4002551C))
#define GPIO_PORTF_DATA_R 	(*((volatile unsigned int *)0x400253FC))

#include <stdlib.h>

void * _sbrk(int Increment){
	extern unsigned int _E_Bss;
	extern unsigned int _Heap_End;
	static unsigned char * Heap_Ptr = NULL;
	static unsigned char * Prev_Heap_Ptr = NULL;
	if(Heap_Ptr==NULL)
		Heap_Ptr = (unsigned char *)&_E_Bss;
	Prev_Heap_Ptr = Heap_Ptr;

	if( (Heap_Ptr + Increment) > (unsigned char *)&_Heap_End )
		return (void *) NULL;

	Heap_Ptr += Increment; 
	return (void *)Prev_Heap_Ptr;
}

int main(){
	// Enable GPIOF pripheral clock
	SYSCTL_RCGC2_R = 0x20;
	// A small delay to ensure GPIOF signals are stable enough
	// ensure that compiler optimizations won't affect Delay_Count variable
	volatile unsigned int Delay_Count = 0;
	for(Delay_Count = 0; Delay_Count<200; Delay_Count++);
	GPIO_PORTF_DIR_R |= 1<<3; // Set pin 3 on port F to output pin
	GPIO_PORTF_DEN_R |= 1<<3; // Enable pin 3 on port F


	// Trying to use malloc function from standard library stdlib.h
	int *p = (int *)malloc(20*sizeof(int));
	while(1){
		GPIO_PORTF_DATA_R |= 1<<3;
		for(Delay_Count = 0; Delay_Count<200000; Delay_Count++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(Delay_Count = 0; Delay_Count<200000; Delay_Count++);
	}


	return 0;
}