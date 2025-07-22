#include <REGX52.H>
#include "Delay.h"

#define Matrix_LED_PORT P0

sbit RCK = P3^5;    //RCLK
sbit SCK = P3^6;    //SRCLK
sbit SER = P3^4;    //SER

/**
  * @brief ����ͼ��ʼ��
  * @param ��
  * @retval ��
  */
void MatrixLED_Init()
{
	SCK = 0;
	RCK = 0;
}

/**
  * @brief 74HC595д��һ���ֽ�
  * @param Byte Ҫд����ֽ�
  * @retval ��
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
  * @brief LED��������ʾһ������
  * @param Column Ҫѡ����У���0��ʼ,0~7,0������ߣ�
  * @param Data ѡ����Ҫ��ʾ�����ݣ���λ���ϣ�1Ϊ����0ΪϨ
  * @retval ��
  */
void MatrixLED_ShowColumn(unsigned char Column, Data)
{
	_74HC595_WriteByte(Data);
	Matrix_LED_PORT = ~(0x80 >> Column);
	Delay(1);                //��Ӱ
	Matrix_LED_PORT = 0xFF;  //��Ӱ
}
