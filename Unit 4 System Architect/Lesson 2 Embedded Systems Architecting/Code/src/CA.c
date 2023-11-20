/*
*   CA.c
*   Created on: 20 Nov 2023
*   Author: Shehab Elkhaligy
*/
#include "CA.h"
#include "DC.h"
#include "US.h"
int Speed       =0;
int Distance    =0;
extern int US_Distance;
int Threshold   =50;
CA_State CA_Current_State;

void (*CA_State_F_P) ();

void CA_Waiting_State_F(){
	Speed = 0;
	printf("(STATE) (CA Waiting) (Distance = %d, Speed = %d)\n",Distance,Speed);
	// Set Current State
	CA_Current_State = CA_Waiting;
	// Actions
	DC_Set_Speed(Speed);
	// Event Check
	Distance = US_Send_Distance();
	(Distance <= Threshold) ? (CA_State_F_P = CA_Waiting_State_F) : (CA_State_F_P = CA_Driving_State_F);

}
void CA_Driving_State_F(){
	Speed = 30;
	printf("(STATE) (CA Driving) (Distance = %d, Speed = %d)\n",Distance,Speed);
	// Set Current State
	CA_Current_State = CA_Driving;
	// Actions
	DC_Set_Speed(Speed);
	// Event Check
	Distance = US_Send_Distance();
	(Distance <= Threshold) ? (CA_State_F_P = CA_Waiting_State_F) : (CA_State_F_P = CA_Driving_State_F);
	
}


