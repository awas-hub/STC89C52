#include <REGX52.H>

/**
  * @brief 串口初始化 4800bps@11.0592MHz
  * @param 无
  * @retval 无
  */
void UART_Init()    //4800bps@11.0592MHz
{
	SCON = 0x50;  //串行控制寄存器（可位寻址） REN=1，允许串行接收状态
	PCON &= 0x7F; //电源控制寄存器（不可位寻址）
	
	TMOD &= 0x0F; //设置定时器模式
	TMOD |= 0x20; //设置定时器模式
	
	TL1 = 0xFA;		//设置定时初值
	TH1 = 0xFA;		//设置定时重装值
	
	ET1 = 0;          //禁止定时器1中断
	TR1 = 1;          //启动定时器1
	
	//使能中断
	ES=1;
	EA=1;
	
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

//串口中断模板
/*void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		
		RI=0;
	}
}*/