/*
*   US.h
*   Created on: 20 Nov 2023
*   Author: Shehab Elkhaligy
*/
#ifndef US_
#define US_
#include "stdio.h"
#include "stdlib.h"

extern void (*US_State_F_P) ();
typedef enum {
	US_Busy
}US_State;


void US_Init();
void US_Idle_State_F();
void US_Busy_State_F();
int ULTRASONIC_Get_Distance(int Low, int High);
int US_Send_Distance();

#endif