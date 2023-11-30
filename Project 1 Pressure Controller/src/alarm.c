/*
*   alarm.c
*   Created on: 29 Nov 23
*   Author: Shehab Elkhaligy
*/

/*
*	Includes: 	This module requires alarm.h for its own declarations, external_events.h 
*				for external functions declaration and finally driver.h for the delay 
*/
#include "alarm.h"
#include "external_events.h"
#include "driver.h"

/*Global variables: Only a pointer to function that represents the current state function*/
void (*ALARM_State_Pointer)();

/*States: Each state is represented by a function*/
void ALARM_State_Off(){
	Set_Alarm_actuator(0);
}
void ALARM_State_On(){
	Set_Alarm_actuator(1);
	Delay(4000000);
	ALARM_State_Pointer = ALARM_State_Off;
}

/*External Events: Each external event to this module is represented by a function*/
void ALARM_Set_Alarm(unsigned int i){
	if(i==1)
		ALARM_State_Pointer = ALARM_State_On;
	else
		ALARM_State_Pointer = ALARM_State_Off;

}
