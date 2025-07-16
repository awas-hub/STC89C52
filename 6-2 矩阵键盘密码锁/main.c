#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if (KeyNum)
		{
			if(KeyNum<=10)
			{
				if (Count<4)
				{
					Password*=10;        //��������һλ
					Password+=KeyNum%10; //��ȡһλ����
					Count++;
				}
				LCD_ShowNum(2,1,Password,4); //������ʾ
			}
			
			if(KeyNum==13) //ȷ��
			{
				if(Password==1112)
				{
					LCD_ShowString(1,12,"OK"); //��ʾOK
					Password=0; //�������
					Count=0;    //�ƴ�����
					LCD_ShowNum(2,1,Password,4); //������ʾ
				}
				else
				{
					LCD_ShowString(1,12,"ERR"); //��ʾERR
					Password=0; //�������
					Count=0;    //�ƴ�����
					LCD_ShowNum(2,1,Password,4); //������ʾ
				}
			}
			
			if(KeyNum==14) //�˸�
			{
				if(Count>0) //ֻ���Ѿ������ִ���˸�
				{
					Password/=10;  //ɾ�����һ����
					Count--;         //��������1
				}
				else //û����������ǿ�����
				{
					Password=0;    //�������
					Count=0;       //�ƴ�����
				}
				LCD_ShowNum(2,1,Password,4); //������ʾ
			}
			
			if(KeyNum==15) //ɾ�����
			{
				Password=0; //�������
				Count=0;    //�ƴ�����
				LCD_ShowNum(2,1,Password,4); //������ʾ
			}
		}
	}
}