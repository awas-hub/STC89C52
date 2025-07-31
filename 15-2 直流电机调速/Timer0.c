#include <REGX52.H>

/**
  * @brief 定时器0初始化，//100微秒@11.0592MHz
  * @param 无
  * @retval 无
  */

void Timer0_Init(void)
{
	TMOD&=0xF0; //把TMOD的低四位清零，高四位保持不变
	TMOD|=0x01; //把TMOD的最低位置1，高四位保持不变
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	ET0=1;
	EA=1;
	PT0=0;
}