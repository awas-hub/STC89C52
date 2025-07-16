#include <REGX52.H>

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

void main()
{
	unsigned char LEDNum=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
//			//P2³õÊ¼×´Ì¬ 1111 1111
//			P2++; // 0000 0000
			
//			LEDNum++;
//			P2=~LEDNum;
			P2--;
		}
	}
}

--0000 0001----1
~1111 1110

--0000 0010----2
~1111 1101

--0000 0011----3
~1111 1100