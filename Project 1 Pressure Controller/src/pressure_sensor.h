/*
 * 	ps.c (Pressure sensor module)
 *
 *  Created on: Nov 29, 2023
 *  Author: Shehab Elkhaligy
 */

#ifndef PS_H
#define PS_H

typedef enum{
	PS_Read,
	PS_Idle
}PS_Current_State_T;

extern void (*PS_State_Pointer)();
void PS_State_Read();
void PS_State_Idle();

#endif