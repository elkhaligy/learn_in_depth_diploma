/*
*	fifo.c
*	Created on: 15 Nov 2023
*	Author: Shehab Elkhaligy
*/

#ifndef FIFO_H
#define FIFO_H


#define ELEMENT_TYPE Student_T

// Forward declaration
typedef struct Student Student_T;

typedef struct Queue{
	unsigned int Length;
	unsigned int Count;
	ELEMENT_TYPE *Base;
	ELEMENT_TYPE *Head;
	ELEMENT_TYPE *Tail;
}Queue_T;

typedef enum{
	FIFO_Good,
	FIFO_Full,
	FIFO_Empty,
	FIFO_Null
}FIFO_Status;

FIFO_Status FIFO_Init (Queue_T *FIFO_Buffer, ELEMENT_TYPE *Buffer, unsigned int Length);
FIFO_Status FIFO_Enqueue(Queue_T *FIFO_Buffer, ELEMENT_TYPE Data);
//FIFO_Status FIFO_Dequeue(Queue_T *FIFO_Buffer, ELEMENT_TYPE *Data);
FIFO_Status FIFO_Dequeue(Queue_T *FIFO_Buffer);
FIFO_Status FIFO_Is_Full(Queue_T *FIFO_Buffer);
FIFO_Status FIFO_Print  (Queue_T *FIFO_Buffer);




#endif