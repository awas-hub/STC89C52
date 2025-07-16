#include <REGX52.H>
unsigned char LEDNum=0;

void Delay(unsigned int t);	

void main()
{
	P2=0xFE;
	while(1)
	{
		//ÓÒÒÆ
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			LEDNum++;
			if(LEDNum>=8)
			LEDNum=0;
		
			P2=~(0x01<<LEDNum); // 0x01----0000 0001
		}
		
		//×óÒÆ
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			if(LEDNum==0)
				LEDNum=7;
			else
				LEDNum--;
			
			P2=~(0x01<<LEDNum);
		}
	}
}

void Delay(unsigned int t)		//@11.0592MHz
{
	unsigned char i, j;

	while(t--)
	{
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}