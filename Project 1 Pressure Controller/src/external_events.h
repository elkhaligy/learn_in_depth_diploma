/*
 * 	external_events.h
 *
 *  Created on: Nov 29, 2023
 *  Author: Shehab Elkhaligy
 */
#ifndef EXTEVENTS_H
#define EXTEVENTS_H


// External event for Detector module
void DT_PS_Get_Pressure(unsigned int Pressure_Value);

// External event for buzzer
void BUZZ_Stop();
void BUZZ_Start();

// External event for Alarm
void ALARM_Set_Alarm(unsigned int i);
#endif