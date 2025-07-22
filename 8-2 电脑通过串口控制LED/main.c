#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;

void main()
{
	UART_Init();
	while(1)
	{
		
	}
}  

void UART_Routine() interrupt 4
{
	if(RI==1)
	{
        P2 = SBUF;       // 直接输出到LED
        UART_SendByte(SBUF); // 回显
        RI = 0;
	}
}