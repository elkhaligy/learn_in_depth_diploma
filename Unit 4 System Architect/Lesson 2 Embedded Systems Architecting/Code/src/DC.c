/*
*   DC.c
*   Created on: 20 Nov 2023
*   Author: Shehab Elkhaligy
*/

#include "DC.h"
int DC_Speed=0;
DC_State DC_Cur_State;
void (*DC_State_F_P) ();

void DC_Init(){
    printf("DC_Init\n");    
}
void DC_Idle_State_F(){
    DC_Cur_State=DC_Idle;
    DC_Speed = 0;
    printf("(STATE) (DC Idle) (Speed = %d)\n",DC_Speed);
}

void DC_Busy_State_F(){
    DC_Cur_State=DC_Busy;

    DC_State_F_P = DC_Idle_State_F;
    printf("(STATE) (DC Busy) (Speed = %d)\n",DC_Speed);
}

void DC_Set_Speed(int Speed){
    DC_Speed = Speed;
    DC_State_F_P = DC_Busy_State_F;
    printf("(SIGNAL) (CA -> DC) (Data: Speed = %d)\n",DC_Speed);
}
