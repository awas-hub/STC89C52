#include <REGX52.H>
#include "LCD1602.h" 
#include "Delay.h" 

void main()
{
	LCD_Init();
	LCD_ShowChar(1, 2, '\\');
	LCD_ShowString(2, 4, "13");
	LCD_ShowNum(1, 5, 789, 4);
	LCD_ShowSignedNum(1, 10, -88, 2);
	LCD_ShowHexNum(2, 1, 0xA5, 2);
	LCD_ShowBinNum(2, 7, 0xFE, 8);
	LCD_ShowChar(1, 14, 0xDF);
	LCD_ShowChar(1, 15, 0x43);
	LCD_ShowString(2, 16, "Welcome to China!");
	while(1)
	{
		LCD_WriteCommand(0x18);
		Delay(500);
	}
		
}