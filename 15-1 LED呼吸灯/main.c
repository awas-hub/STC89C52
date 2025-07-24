#include <REGX52.H>

sbit LED = P2^0;

// 延时函数
void Delay(unsigned int t)
{
    while(t--);  // 循环计数，每次循环消耗一个机器周期
}

void main()
{
    unsigned char Time, i;  // 定义变量Time用于控制LED亮度，i用于循环计数
    
    while(1)
    {
        // Ts = Ton + Toff（总周期 = 亮时间 + 暗时间）
        
        // 暗-->亮
        for(Time = 0; Time < 100; Time++)  // Time从0增加到99，控制LED逐渐变亮
        {
            for(i = 0; i < 20; i++)  // 重复20次，使LED状态稳定
            {
                LED = 0;  // LED亮（假设低电平点亮）
                Delay(Time);  // 亮时间逐渐增加
                LED = 1;  // LED灭（高电平熄灭）
                Delay(100 - Time);  // 灭时间逐渐减少
            }
        }
        
        // 亮-->暗
        for(Time = 100; Time > 0; Time--)  // Time从100减少到1，控制LED逐渐变暗
        {
            for(i = 0; i < 20; i++)  // 重复20次，使LED状态稳定
            {
                LED = 0;  // LED亮
                Delay(Time);  // 亮时间逐渐减少
                LED = 1;  // LED灭
                Delay(100 - Time);  // 灭时间逐渐增加
            }
        }        
    }
}