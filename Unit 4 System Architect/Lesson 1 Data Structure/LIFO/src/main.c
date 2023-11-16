/*
*	main.c
*	Created on: 15 Nov 2023
*	Author: Shehab Elkhaligy
*/
//#include <lifo.h>
#include "stdio.h"
#include "stdlib.h"
#include "lifo.h"

unsigned int Buffer_1[5];

int main() {
    LIFO_Buffer UART_Lifo, I2C_Lifo;
    LIFO_Create(&UART_Lifo, Buffer_1,sizeof(Buffer_1)/sizeof(int));

    unsigned int *Buffer_2 = (unsigned int *)malloc(5*sizeof(int));
    LIFO_Create(&I2C_Lifo, Buffer_2, 5);

    for(int i=0;i<5;i++){
    	if(LIFO_Add(&UART_Lifo, i)==LIFO_Good)
    		printf("Added!\n");
    }

    for(int i=0;i<5;i++){
    	if(LIFO_Add(&I2C_Lifo, i)==LIFO_Good)
    		printf("Added!\n");
    }
    unsigned int data;
    printf("First stack: ");
   	for(int i=0;i<5;i++){
   		if(LIFO_Pop(&UART_Lifo,&data)==LIFO_Good)
   			printf("%d ",data);
   		else{
   			printf("Error!");
   			break;
   		}
    }    
	
    printf("\nSecond stack: ");
   	for(int i=0;i<7;i++){
   		if(LIFO_Pop(&I2C_Lifo,&data)==LIFO_Good)
   			printf("%d ",data);
   		else{
   			printf("Error!");
   			break;
   		}
    	
    }
    free(Buffer_2);
    return 0;
}

