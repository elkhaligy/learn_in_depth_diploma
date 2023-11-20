/*
*   US.c
*   Created on: 20 Nov 2023
*   Author: Shehab Elkhaligy
*/
#include "US.h"
int US_Distance;
US_State US_Cur_State;
void (*US_State_F_P) ();

void US_Init(){
    printf("US_Init\n");    
}
void US_Busy_State_F(){
    US_Cur_State=US_Busy;
    US_Distance = ULTRASONIC_Get_Distance(45,55);
    printf("(STATE) (US Busy) (Distance = %d)\n",US_Distance);
    US_State_F_P = US_Busy_State_F;
}

int ULTRASONIC_Get_Distance(int Low, int High){
	return ((rand() % (High-Low+1)) + Low);
}

int US_Send_Distance(){
    printf("(SIGNAL) (US -> CA) (Data: Distance = %d)\n",US_Distance);
    return US_Distance;
}