#include <REGX52.H>
#include "Delay.h"

#define Matrix_LED_PORT P0

sbit RCK = P3^5;    //RCLK
sbit SCK = P3^6;    //SRCLK
sbit SER = P3^4;    //SER

/**
  * @brief 点阵图初始化
  * @param 无
  * @retval 无
  */
void MatrixLED_Init()
{
	SCK = 0;
	RCK = 0;
}

/**
  * @brief 74HC595写入一个字节
  * @param Byte 要写入的字节
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i = 0;
	for(i = 0; i < 8; i++)
	{
		SER = Byte & (0x80 >> i) ;
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}

/**
  * @brief LED点阵屏显示一列数据
  * @param Column 要选择的列（从0开始,0~7,0在最左边）
  * @param Data 选择列要显示的数据，高位在上，1为亮，0为熄
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char Column, Data)
{
	_74HC595_WriteByte(Data);
	Matrix_LED_PORT = ~(0x80 >> Column);
	Delay(1);                //消影
	Matrix_LED_PORT = 0xFF;  //消影
}
