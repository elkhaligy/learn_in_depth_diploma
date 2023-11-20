/*
*   Collision_Avoidance.c
*   Created on: 20 Nov 2023
*   Author: Shehab Elkhaligy
*/
#include "CA.h"

int Speed       =0;
int Distance    =0;
int Threshold   =50;
CA_State CA_Current_State;

void (*CA_State_F_P) ();

void CA_Waiting_State_F(){
	// Set Current State
	CA_Current_State = CA_Waiting;
	// Actions
	Speed = 0;
		// MOTOR_Set_Speed(Speed);
	// Event Check
	Distance = ULTRASONIC_Get_Distance(45,55);
	(Distance <= Threshold) ? (CA_State_F_P = CA_Waiting_State_F) : (CA_State_F_P = CA_Driving_State_F);
	printf("CA_Waiting_State: Distance is %d, Speed is %d\n",Distance,Speed);
}
void CA_Driving_State_F(){
	// Set Current State
	CA_Current_State = CA_Driving;
	// Actions
	Speed = 30;
		// MOTOR_Set_Speed(Speed);
	// Event Check
	Distance = ULTRASONIC_Get_Distance(45,55);
	(Distance <= Threshold) ? (CA_State_F_P = CA_Waiting_State_F) : (CA_State_F_P = CA_Driving_State_F);
	printf("CA_Driving_State: Distance is %d, Speed is %d\n",Distance,Speed);
}


int ULTRASONIC_Get_Distance(int Low, int High){
	return ((rand() % (High-Low+1)) + Low);
}