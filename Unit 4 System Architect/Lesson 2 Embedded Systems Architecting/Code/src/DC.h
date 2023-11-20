/*
*   DC.h
*   Created on: 20 Nov 2023
*   Author: Shehab Elkhaligy
*/

#ifndef DC_
#define DC_
#include "stdio.h"
#include "stdlib.h"


extern void (*DC_State_F_P) ();
typedef enum {
	DC_Idle,
	DC_Busy
}DC_State;

void DC_Init();
void DC_Idle_State_F();
void DC_Busy_State_F();
void DC_Set_Speed(int Speed);




#endif