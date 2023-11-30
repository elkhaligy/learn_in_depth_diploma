/*
 * 	detector.c
 *
 *  Created on: Nov 29, 2023
 *  Author: Shehab Elkhaligy
 */

/*
*	Includes: 	This module requires detector.h for its own declarations, external_events.h 
*				for external functions declaration
*/
#include "detector.h"
#include "external_events.h"

/*Global variables: a pointer to function that represents the current state function
*					and a global variable that holds the pressure max threshold
*/
void (*DT_State_Pointer)();
unsigned int Pressure_Threshold;

/*States: Each state is represented by a function*/
void DT_State_Low(){
}
void DT_State_High(){
	ALARM_Set_Alarm(1);
	DT_State_Pointer = DT_State_Low;
}

/*External Events: Each external event to this module is represented by a function*/
void DT_PS_Get_Pressure(unsigned int Pressure_Value){
	Pressure_Threshold = 20;
	if(Pressure_Value > Pressure_Threshold)
		DT_State_Pointer = DT_State_High;
	else
		DT_State_Pointer = DT_State_Low;
}
