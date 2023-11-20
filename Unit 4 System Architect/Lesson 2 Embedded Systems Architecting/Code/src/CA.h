/*
*   Collision_Avoidance.h
*   Created on: 20 Nov 2023
*   Author: Shehab Elkhaligy
*/
#ifndef CA_
#define CA_

#include "stdio.h"
#include "stdlib.h"

extern void (*CA_State_F_P) ();
#define hello 1
typedef enum {
	CA_Waiting,
	CA_Driving
}CA_State;


void CA_Waiting_State_F();
void CA_Driving_State_F();
int ULTRASONIC_Get_Distance(int Low, int High);


#endif