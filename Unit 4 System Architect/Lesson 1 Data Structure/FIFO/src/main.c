/*
*	main.c
*	Created on: 15 Nov 2023
*	Author: Shehab Elkhaligy
*/

#include "stdio.h"
#include "stdlib.h"
#include "../inc/fifo.h"

ELEMENT_TYPE Buffer[5];
int main() {
	FIFO_Buffer FIFO_UART;
	if(FIFO_Create(&FIFO_UART,Buffer,5) == FIFO_Good)
		printf("FIFO Created Successfully!\n");

	for (int i = 0; i < 7; i++){
		if(FIFO_Enqueue(&FIFO_UART,i) == FIFO_Good)
			printf("Enqueued: %d\n",i);
		else
			printf("Enqueue Failed\n");
	}
	

	FIFO_Print(&FIFO_UART);
	ELEMENT_TYPE Data;
	FIFO_Dequeue(&FIFO_UART,&Data);
	FIFO_Dequeue(&FIFO_UART,&Data);
	FIFO_Print(&FIFO_UART);
	FIFO_Print(&FIFO_UART);
	FIFO_Print(&FIFO_UART);
	return 0;
}

