/*
*
*   alarm.h
*   Created on: 29 Nov 23
*   Author: Shehab Elkhaligy
*/
#ifndef ALARM_H
#define ALARM_H

typedef enum {
	ALARM_Off,
	ALARM_On,
	ALARM_Waiting
}ALARM_Current_State_T;

extern void (*ALARM_State_Pointer)();
void ALARM_State_Off();
void ALARM_State_On();

#endif