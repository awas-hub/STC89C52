#include <REGX52.H>

/**
  * @brief ���ڳ�ʼ�� 4800bps@11.0592MHz
  * @param ��
  * @retval ��
  */
void UART_Init()    //4800bps@11.0592MHz
{
	SCON = 0x40;  //���п��ƼĴ�������λѰַ��
	PCON = 0x80; //��Դ���ƼĴ���������λѰַ��
	
	TMOD &= 0x0F; //���ö�ʱ��ģʽ
	TMOD |= 0x20; //���ö�ʱ��ģʽ
	
	TL1 = 0xF3;		//���ö�ʱ��ֵ
	TH1 = 0xF3;		//���ö�ʱ��װֵ
	
	ET1 = 0;          //��ֹ��ʱ��1�ж�
	TR1 = 1;          //������ʱ��1
}

 /**
  * @brief ���ڷ���һ���ֽ�����
  * @param Byte Ҫ���͵�һ���ֽ�����
  * @retval ��
  */
void UART_SendByte(unsigned char Byte) 
{
	SBUF = Byte;
	while(TI==0);
	TI=0;
}