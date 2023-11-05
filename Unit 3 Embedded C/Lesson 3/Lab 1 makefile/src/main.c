#include "uart.h"

unsigned char buffer[100]="learn-in-depth:Shehab";

void c_is_powerful(void){
	uart_send_string(buffer);
}