/*
 * 	detector.c
 *
 *  Created on: Nov 29, 2023
 *  Author: Shehab Elkhaligy
 */
#ifndef DETECTOR_H
#define DETECTOR_H

typedef enum {
	DT_Normal,
	DT_High
}DT_Current_State_T;

extern void (*DT_State_Pointer)();
void DT_State_Low();
void DT_State_High();

#endif