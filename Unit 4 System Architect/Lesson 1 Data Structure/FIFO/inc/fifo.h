/*
*	fifo.c
*	Created on: 15 Nov 2023
*	Author: Shehab Elkhaligy
*/

#ifndef FIFO_H
#define FIFO_H

#define ELEMENT_TYPE unsigned char

typedef struct{
	unsigned int Length;
	unsigned int Count;
	ELEMENT_TYPE *Base;
	ELEMENT_TYPE *Head;
	ELEMENT_TYPE *Tail;
}FIFO_Buffer;

typedef enum{
	FIFO_Good,
	FIFO_Full,
	FIFO_Empty,
	FIFO_Null
}FIFO_Status;

FIFO_Status FIFO_Create (FIFO_Buffer *FIFO_Buffer, ELEMENT_TYPE *Buffer, unsigned int Length);
FIFO_Status FIFO_Enqueue(FIFO_Buffer *FIFO_Buffer, ELEMENT_TYPE Data);
FIFO_Status FIFO_Dequeue(FIFO_Buffer *FIFO_Buffer, ELEMENT_TYPE *Data);
FIFO_Status FIFO_Is_Full(FIFO_Buffer *FIFO_Buffer);
FIFO_Status FIFO_Print  (FIFO_Buffer *FIFO_Buffer);




#endif