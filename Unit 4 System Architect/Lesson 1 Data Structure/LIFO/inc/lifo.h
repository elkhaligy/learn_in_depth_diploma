/*
*	main.c
*	Created on: 15 Nov 2023
*	Author: Shehab Elkhaligy
*/
#ifndef LIFO_H
#define LIFO_H

typedef struct {
	unsigned int Length;
	unsigned int Count;
	unsigned int *Base;
	unsigned int *Head;
}LIFO_Buffer;

typedef enum {
	LIFO_Good,
	LIFO_Full,
	LIFO_Empty,
	LIFO_Null
}LIFO_Status;

// APIS
LIFO_Status	LIFO_Create	(LIFO_Buffer * LIFO_Buffer, unsigned int * Buffer, unsigned int Length);
LIFO_Status LIFO_Add	(LIFO_Buffer * LIFO_Buffer, unsigned int Data);
LIFO_Status LIFO_Pop	(LIFO_Buffer * LIFO_Buffer, unsigned int *Storage);

#endif