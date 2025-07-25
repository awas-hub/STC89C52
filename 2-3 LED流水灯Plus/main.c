#include <REGX52.H>

void Delay1ms(unsigned int t)		//@11.0592MHz
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
	P2=0xFE;//1111 1110
	Delay1ms(50);	
		
	P2=0xFD;//1111 1101
	Delay1ms(50);		
		
	P2=0xFB;//1111 1011
	Delay1ms(50);	
		
	P2=0xF7;//1111 0111
	Delay1ms(50);	
		
	P2=0xEF;//1110 1111 
	Delay1ms(50);	
		
	P2=0xDF;//1101 1111
	Delay1ms(50);	
		
	P2=0xBF;//1011 1111
	Delay1ms(50);	
		
	P2=0x7F;//0111 1111
	Delay1ms(50);	
}
