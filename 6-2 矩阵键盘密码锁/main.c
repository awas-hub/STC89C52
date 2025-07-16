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
					Password*=10;        //密码左移一位
					Password+=KeyNum%10; //获取一位密码
					Count++;
				}
				LCD_ShowNum(2,1,Password,4); //更新显示
			}
			
			if(KeyNum==13) //确认
			{
				if(Password==1112)
				{
					LCD_ShowString(1,12,"OK"); //显示OK
					Password=0; //密码归零
					Count=0;    //计次清零
					LCD_ShowNum(2,1,Password,4); //更新显示
				}
				else
				{
					LCD_ShowString(1,12,"ERR"); //显示ERR
					Password=0; //密码归零
					Count=0;    //计次清零
					LCD_ShowNum(2,1,Password,4); //更新显示
				}
			}
			
			if(KeyNum==14) //退格
			{
				if(Count>0) //只有已经输入才执行退格
				{
					Password/=10;  //删除最后一数字
					Count--;         //计数器减1
				}
				else //没有输入或已是空密码
				{
					Password=0;    //密码归零
					Count=0;       //计次清零
				}
				LCD_ShowNum(2,1,Password,4); //更新显示
			}
			
			if(KeyNum==15) //删除清空
			{
				Password=0; //密码归零
				Count=0;    //计次清零
				LCD_ShowNum(2,1,Password,4); //更新显示
			}
		}
	}
}