/*
*	main.c
*	Created on: 15 Nov 2023
*	Author: Shehab Elkhaligy
*/
#include <stdio.h>
#include "../inc/lifo.h"

LIFO_Status	LIFO_Create(LIFO_Buffer * LIFO_Buffer, unsigned int * Buffer, unsigned int Length){
	if(Buffer == NULL)
		return LIFO_Null;
	LIFO_Buffer -> Base 	= Buffer;
	LIFO_Buffer -> Head 	= Buffer;
	LIFO_Buffer -> Length 	= Length;
	LIFO_Buffer -> Count	= 0;
	return LIFO_Good;
}

LIFO_Status LIFO_Add(LIFO_Buffer * LIFO_Buffer, unsigned int Data){
	// Error checks
	if(LIFO_Buffer -> Count == LIFO_Buffer -> Length)
		return LIFO_Full;
	if(LIFO_Buffer -> Base == NULL || LIFO_Buffer -> Head == NULL)
		return LIFO_Null;
	// Adding data
	*(LIFO_Buffer -> Head)	= Data; 
	LIFO_Buffer -> Head 	+= 1;
	LIFO_Buffer -> Count 	+= 1;
	return LIFO_Good;
}		

LIFO_Status LIFO_Pop(LIFO_Buffer * LIFO_Buffer, unsigned int *Storage){
	// ERROR CHECKS
	// Check if stack is valid
	if(LIFO_Buffer -> Base == NULL || LIFO_Buffer -> Head == NULL)
		return LIFO_Null;
	// Check if stack is empty
	if(LIFO_Buffer -> Count == 0)
		return LIFO_Empty;

	LIFO_Buffer -> Head -= 1;
	*Storage = *(LIFO_Buffer -> Head);
	LIFO_Buffer -> Count -=1;
	return LIFO_Good;
}
