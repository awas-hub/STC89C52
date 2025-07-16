#include <REGX52.H>
#include "LCD1602.h"

void main()
{
	LCD_Init();
	LCD_ShowChar(1,1,'A');
	LCD_ShowString(1,3,"AWAS");
	LCD_ShowNum(1,8,414,3);
	LCD_ShowSignedNum(1,12,-64,2);
	LCD_ShowHexNum(2,1,0xFE,2);
	LCD_ShowBinNum(2,4,0xAA,8);  
	while(1)
	{
		
	}
}
