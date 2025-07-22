#include <REGX52.H>

/**
  * @brief 串口初始化 4800bps@11.0592MHz
  * @param 无
  * @retval 无
  */
void UART_Init()    //4800bps@11.0592MHz
{
	SCON = 0x40;  //串行控制寄存器（可位寻址）
	PCON = 0x80; //电源控制寄存器（不可位寻址）
	
	TMOD &= 0x0F; //设置定时器模式
	TMOD |= 0x20; //设置定时器模式
	
	TL1 = 0xF3;		//设置定时初值
	TH1 = 0xF3;		//设置定时重装值
	
	ET1 = 0;          //禁止定时器1中断
	TR1 = 1;          //启动定时器1
}

 /**
  * @brief 串口发送一个字节数据
  * @param Byte 要发送的一个字节数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte) 
{
	SBUF = Byte;
	while(TI==0);
	TI=0;
}