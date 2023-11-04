#include "uart.h"

#define UART0DR *((volatile unsigned int *)(0x101F1000))

void uart_send_string(unsigned char* tx_string){
	while(*tx_string!='\0'){
		UART0DR= (unsigned int) *tx_string;
		tx_string++;
	}
}