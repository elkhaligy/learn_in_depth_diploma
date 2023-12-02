/*
 * 	fifo.c
 *
 *  Created on: 15 Nov 2023
 *  Author: Shehab Elkhaligy
 */
#include "Database.h"
#include "fifo.h"
#include "stdio.h"

FIFO_Status FIFO_Init(Queue_T *FIFO_Buffer, ELEMENT_TYPE *Buffer, unsigned int Length){
	if(Buffer == NULL)
		return FIFO_Null;
	FIFO_Buffer -> Base		= Buffer;
	FIFO_Buffer -> Head		= Buffer;
	FIFO_Buffer -> Tail		= Buffer;
	FIFO_Buffer -> Count	= 0;
	FIFO_Buffer -> Length	= Length;
	//printf("Hello,%f\n",Buffer[0].GPA);
	//printf("sizeo of %lld\n",sizeof(Student_T));
	return FIFO_Good;
}
FIFO_Status FIFO_Enqueue(Queue_T *FIFO_Buffer, ELEMENT_TYPE Data){
	// Check if any of the pointers is missing
	if(!FIFO_Buffer -> Head || !FIFO_Buffer -> Base || !FIFO_Buffer -> Tail)
		return FIFO_Null;
	// if(FIFO_Is_Full(FIFO_Buffer) == FIFO_Full)
	// 	return FIFO_Full;
	*(FIFO_Buffer -> Head) = Data;
	FIFO_Buffer -> Count += 1;
	if(FIFO_Buffer -> Count > FIFO_Buffer -> Length)
		FIFO_Buffer -> Count = FIFO_Buffer -> Length;
	if(FIFO_Buffer -> Head == (FIFO_Buffer -> Base + FIFO_Buffer -> Length * sizeof(ELEMENT_TYPE))) 
		FIFO_Buffer -> Head = FIFO_Buffer -> Base;
	else
		FIFO_Buffer -> Head += 1;
	return FIFO_Good;
}
// FIFO_Status FIFO_Dequeue(Queue_T *FIFO_Buffer, ELEMENT_TYPE *Data){
// 	if(!FIFO_Buffer -> Head || !FIFO_Buffer -> Base || !FIFO_Buffer -> Tail)
// 		return FIFO_Null;
// 	if(FIFO_Buffer -> Count == 0)
// 		return FIFO_Empty;
// 	*Data = *(FIFO_Buffer -> Tail);
// 	if(FIFO_Buffer -> Tail == (FIFO_Buffer -> Base + FIFO_Buffer -> Length * sizeof(ELEMENT_TYPE))) 
// 		FIFO_Buffer -> Tail = FIFO_Buffer -> Base;
// 	else
// 		FIFO_Buffer -> Tail += 1;
// 	FIFO_Buffer -> Count -= 1;
// 	return FIFO_Good;
// }
FIFO_Status FIFO_Dequeue(Queue_T *FIFO_Buffer){
	if(!FIFO_Buffer -> Head || !FIFO_Buffer -> Base || !FIFO_Buffer -> Tail)
		return FIFO_Null;
	if(FIFO_Buffer -> Count == 0)
		return FIFO_Empty;
	FIFO_Buffer->Count--;
    if(FIFO_Buffer->Tail == (FIFO_Buffer->Base + FIFO_Buffer->Length * sizeof(ELEMENT_TYPE)))
        FIFO_Buffer->Tail = FIFO_Buffer->Base;
    else{
        FIFO_Buffer->Tail++;
	}
	
	return FIFO_Good;
}
FIFO_Status FIFO_Is_Full(Queue_T *FIFO_Buffer){
	if(!FIFO_Buffer -> Head || !FIFO_Buffer -> Base || !FIFO_Buffer -> Tail)
		return FIFO_Null;
	if(FIFO_Buffer -> Count == FIFO_Buffer -> Length)
		return FIFO_Full;
	return FIFO_Good;
}
// FIFO_Status FIFO_Print(Queue_T *FIFO_Buffer){
// 	ELEMENT_TYPE * Temp = FIFO_Buffer -> Tail;
// 	if(!FIFO_Buffer -> Head || !FIFO_Buffer -> Base || !FIFO_Buffer -> Tail)
// 		return FIFO_Null;
// 	if(FIFO_Buffer -> Count == 0)
// 		return FIFO_Empty;
// 	for (int i = 0; i < FIFO_Buffer -> Count; i++){
// 		printf("%d \n", *Temp);
// 		if(Temp == (FIFO_Buffer -> Base + FIFO_Buffer -> Length * sizeof(ELEMENT_TYPE))) 
// 			Temp = FIFO_Buffer -> Base;
// 		else
// 			Temp += 1;
// 	}
// 	printf("\n");
// 	return FIFO_Good;
// }
