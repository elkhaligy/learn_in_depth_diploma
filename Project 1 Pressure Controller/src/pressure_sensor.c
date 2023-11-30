/*
 * 	ps.c
 *
 *  Created on: Nov 29, 2023
 *  Author: Shehab Elkhaligy
 */

/*
*	Includes: 	This module requires pressure_sensor.h for its own declarations, external_events.h 
*				for external functions declaration and finally driver.h for the getting 
*				pressure value 
*/
#include "pressure_sensor.h"
#include "external_events.h"
#include "driver.h"

/*Global variables: Only a pointer to function that represents the current state function*/
void (*PS_State_Pointer)();

/*States: Each state is represented by a function*/
void PS_State_Read(){
	unsigned int Pressure_Value;
	Pressure_Value = getPressureVal();
	DT_PS_Get_Pressure(Pressure_Value);
	PS_State_Pointer = PS_State_Idle;
}
void PS_State_Idle(){
	// We can add a delay here, but it is not good because it is synchronous
	PS_State_Pointer = PS_State_Read;
}