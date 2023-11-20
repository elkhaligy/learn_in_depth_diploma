/*
*   Main.c
*   Created on: 20 Nov 2023
*   Author: Shehab Elkhaligy
*/

#include "CA.h"
#include "DC.h"
#include "US.h"
void Setup(){
	US_Init();
	DC_Init();
	CA_State_F_P = CA_Waiting_State_F;
	US_State_F_P = US_Busy_State_F;
	DC_State_F_P = DC_Idle_State_F;

}
int main(){
	Setup();
	volatile int i;
	while(1){
		US_State_F_P();
		DC_State_F_P();
		CA_State_F_P();
		for(i=0;i<100000000;i++);
	}

	return 0;
}