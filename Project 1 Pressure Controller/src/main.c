/*
 * 	main.c
 *
 *  Created on: Nov 27, 2023
 *  Author: Shehab Elkhaligy
 */
#include "detector.h"
#include "pressure_sensor.h"
#include "alarm.h"
#include "driver.h"
void Setup();

int main(void) {
	Setup();
	while(1) {
		PS_State_Pointer();
		DT_State_Pointer();
		ALARM_State_Pointer();
	}
}

void Setup(){
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(0);
	PS_State_Pointer 	= PS_State_Read;
	DT_State_Pointer 	= DT_State_Low;
	ALARM_State_Pointer = ALARM_State_Off;
}