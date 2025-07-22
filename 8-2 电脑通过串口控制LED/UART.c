#include <REGX52.H>

/**
  * @brief ���ڳ�ʼ�� 4800bps@11.0592MHz
  * @param ��
  * @retval ��
  */
void UART_Init()    //4800bps@11.0592MHz
{
	SCON = 0x50;  //���п��ƼĴ�������λѰַ�� REN=1�������н���״̬
	PCON &= 0x7F; //��Դ���ƼĴ���������λѰַ��
	
	TMOD &= 0x0F; //���ö�ʱ��ģʽ
	TMOD |= 0x20; //���ö�ʱ��ģʽ
	
	TL1 = 0xFA;		//���ö�ʱ��ֵ
	TH1 = 0xFA;		//���ö�ʱ��װֵ
	
	ET1 = 0;          //��ֹ��ʱ��1�ж�
	TR1 = 1;          //������ʱ��1
	
	//ʹ���ж�
	ES=1;
	EA=1;
	
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

//�����ж�ģ��
/*void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		
		RI=0;
	}
}*/