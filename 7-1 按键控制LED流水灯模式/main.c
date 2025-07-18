#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>


unsigned char KeyNum, LEDMode;
void main()
{
	P2=0xFE;
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
//			if(KeyNum==1) P2_1=~P2_1;
//			if(KeyNum==2) P2_2=~P2_2;
//			if(KeyNum==3) P2_3=~P2_3;
//			if(KeyNum==4) P2_4=~P2_4;
			
			if(KeyNum==1)
			{
				LEDMode++;
				if(LEDMode>=2)LEDMode=0;
			}
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	T0Count++;
	if (T0Count>=500)
	{
		T0Count=0;
//		P2_0=~P2_0;
		if(LEDMode==0)
			P2=_crol_(P2,1);
		if(LEDMode==1)
			P2=_cror_(P2,1);
	}
}