#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"

void main()
{
    LCD_Init(); // 初始化LCD显示
    DS1302_Init(); // 初始化DS1302时钟芯片
    LCD_ShowString(1, 1, "  -  -  "); // 第一行显示日期占位符
    LCD_ShowString(2, 1, "  :  :  "); // 第二行显示时间占位符
    
    DS1302_SetTime(); // 设置初始时间（注意：实际使用时可能需要取消写保护）

    while(1)
    {
        DS1302_ReadTime(); // 从DS1302读取当前时间
		
        // 显示年月日
        LCD_ShowNum(1, 1, DS1302_Time[0], 2); // 显示年份（2位）
        LCD_ShowNum(1, 4, DS1302_Time[1], 2); // 显示月份（2位）
        LCD_ShowNum(1, 7, DS1302_Time[2], 2); // 显示日期（2位）
		
        // 显示时分秒
        LCD_ShowNum(2, 1, DS1302_Time[3], 2); // 显示小时（2位）
        LCD_ShowNum(2, 4, DS1302_Time[4], 2); // 显示分钟（2位）
        LCD_ShowNum(2, 7, DS1302_Time[5], 2); // 显示秒钟（2位）        
    }
}
