/*
*   Main.c
*   Created on: 20 Nov 2023
*   Author: Shehab Elkhaligy
*/

#include "CA.h"

void Setup(){
	CA_State_F_P = CA_Waiting_State_F;
}
int main(){
	Setup();
	volatile int i;
	while(1){
		CA_State_F_P();
		for(i=0;i<100000000;i++);
	}

	return 0;
}