#include <REGX52.H>

void Delay(unsigned int t)		//@11.0592MHz
{
	unsigned char i, j;

	while(t)
	{
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		t--;
	}
}


void main()
{
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			P2_0=~P2_0;
		}
	}
}
