/*
 * 	startup.c
 *  Created on: Nov 27, 2023
 *  Author: Shehab Elkhaligy
 */


/*These symbols are not defined in this file, extern tells the compiler
  not to worry about them, as linker will resolve them later*/
extern int main(void);
extern unsigned int _E_Text; // start of data section in flash
extern unsigned int _S_Data;
extern unsigned int _E_Data;
extern unsigned int _S_Bss;
extern unsigned int _E_Bss;
extern unsigned int _Stack_Top;

void Reset_Handler();

void Default_Handler(){
	Reset_Handler();
}

/*This mean that NMI_Handler symbol can be defined in another file
but not just that, if it is not defined in another file it will be treated as
 Default_Handler symbol*/
void NMI_Handler()			__attribute__((weak,alias("Default_Handler")));
void H_Fault_Handler()		__attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler()		__attribute__((weak,alias("Default_Handler")));
void Bus_Fault()			__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler()	__attribute__((weak,alias("Default_Handler")));

/*We want this array to be places on 0x08000000
  But the problem is that this array is in the .data section
  So we will use __attribute__ to pass an option to the compiler
*/
unsigned int vectors[] __attribute__((section(".vectors")))={
	(unsigned int) &_Stack_Top,
	(unsigned int) &Reset_Handler,
	(unsigned int) &NMI_Handler,
	(unsigned int) &H_Fault_Handler,
	(unsigned int) &Bus_Fault,
	(unsigned int) &Usage_Fault_Handler
};


void Reset_Handler(){
	/* Copy data section from flash to ram byte by byte*/
	unsigned int Data_Size 	= (unsigned char *)&_E_Data - (unsigned char *)&_S_Data;
	unsigned char * P_Src 	= (unsigned char *)_E_Text;
	unsigned char * P_Dis 	= (unsigned char *)_S_Data;
	for (int i = 0; i < Data_Size; ++i) {
		*P_Dis=*P_Src;
		P_Src++;
		P_Dis++;
	}

	/* Initilaize .bss section in ram with 0 */
	unsigned int Bss_Size = (unsigned char *)&_E_Bss - (unsigned char *)&_S_Bss;
	P_Dis = (unsigned char *)_S_Bss;
	for (int i = 0; i < Bss_Size; ++i) {
		*P_Dis = (unsigned char)0;
		P_Dis++;
	}
	/* ============ */

	main();
}