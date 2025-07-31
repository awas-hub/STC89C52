#include <REGX52.H>

sbit DS1302_SCLK = P3^6;  // DS1302 时钟信号引脚
sbit DS1302_IO = P3^4;    // DS1302 数据信号引脚
sbit DS1302_CE = P3^5;    // DS1302 片选信号引脚

// 写入指令地址定义
#define DS1302_SECOND     0x80
#define DS1302_MINUTE     0x82
#define DS1302_HOUR       0x84
#define DS1302_DATE       0x86
#define DS1302_MONTH      0x88
#define DS1302_DAY        0x8A
#define DS1302_YEAR       0x8C
#define DS1302_WP         0x8E //芯片写保护开关地址

// 时间数据数组，格式：年 月 日 时 分 秒 星期
unsigned DS1302_Time[]={25,7,23,15,30,44,3};


/**
  * @brief DS1302时钟初始化
  * @param 无
  * @retval 无
  */
void DS1302_Init(void)
{
	DS1302_CE = 0;        // 拉低片选信号，选择DS1302芯片
    DS1302_SCLK = 0;      // 拉低时钟信号，初始化时钟
}


/**
  * @brief 写入指令 + 数据
  * @param Command 写入的指令
  * @param Data 写入的数据
  * @retval 无
  */
void DS1302_WriteByte(unsigned char Command, unsigned char Data)
{
	unsigned char i;
    DS1302_CE = 1;        // 拉高片选信号，开始通信
	
	 // 发送指令字节（8位）
	for(i = 0; i < 8; i++)
	{
        DS1302_IO = Command & (0x01 << i);  // 逐位发送指令
        DS1302_SCLK = 1;                    // 上升沿发送数据
        DS1302_SCLK = 0;                    // 下降沿完成数据传输
	}
	
	 // 发送数据字节（8位）
	for(i = 0; i < 8; i++)
	{
        DS1302_IO = Data & (0x01 << i);     // 逐位发送数据
        DS1302_SCLK = 1;                    // 上升沿发送数据
        DS1302_SCLK = 0;                    // 下降沿完成数据传输
	}
	DS1302_CE = 0;
}


/**
  * @brief DS1302读取指令
  * @param Command 指令
  * @retval Data 需要返回的数据
  */
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i, Data = 0x00;
    Command |= 0x01;      // 设置读操作标志位（根据DS1302手册Figure3）
    DS1302_CE = 1;        // 拉高片选信号，开始通信
	
    // 发送指令字节（8位）
    for(i = 0; i < 8; i++)
    {
        DS1302_IO = Command & (0x01 << i);  // 逐位发送指令
        DS1302_SCLK = 0;                    // 下降沿准备读取数据
        DS1302_SCLK = 1;                    // 上升沿完成数据读取
    }
    
    // 读取数据字节（8位）
    for(i = 0; i < 8; i++)
    {
        DS1302_SCLK = 1;                    // 上升沿准备读取数据
        DS1302_SCLK = 0;                    // 下降沿完成数据读取
        if(DS1302_IO){Data |= (0x01 << i);} // 逐位接收数据
    }
    
    DS1302_CE = 0;        // 拉低片选信号，结束通信
    DS1302_IO = 0;        // 拉低数据线，释放总线
    return Data;          // 返回读取的数据
}


/**
  * @brief DS1302写入时间
  * @param 无
  * @retval 无
  */
void DS1302_SetTime(void)
{
	/*
    如果读出时间为一个大于59并且不动的数，
    则芯片有可能是处于写保护状态
    */
    
    // 1. 解除芯片写保护
    DS1302_WriteByte(DS1302_WP, 0x00); // BIT7=0，解除写保护
    
    // 2. 写入时间数据（BCD码格式）
	//注：BCD码转换逻辑，运算符的优先级 例：DS1302_Time[0] / 10 * 16 + DS1302_Time[0] % 10 运算符的逻辑顺序
    DS1302_WriteByte(DS1302_YEAR,    (DS1302_Time[0] / 10) * 16 + (DS1302_Time[0] % 10));  // 年
    DS1302_WriteByte(DS1302_MONTH,   (DS1302_Time[1] / 10) * 16 + (DS1302_Time[1] % 10));  // 月
    DS1302_WriteByte(DS1302_DATE,    (DS1302_Time[2] / 10) * 16 + (DS1302_Time[2] % 10));  // 日
    DS1302_WriteByte(DS1302_HOUR,    (DS1302_Time[3] / 10) * 16 + (DS1302_Time[3] % 10));  // 时
    DS1302_WriteByte(DS1302_MINUTE,  (DS1302_Time[4] / 10) * 16 + (DS1302_Time[4] % 10));  // 分
    DS1302_WriteByte(DS1302_SECOND,  (DS1302_Time[5] / 10) * 16 + (DS1302_Time[5] % 10));  // 秒
    DS1302_WriteByte(DS1302_DAY,     (DS1302_Time[6] / 10) * 16 + (DS1302_Time[6] % 10));  // 星期
    
    // 3. 重新启用写保护
    DS1302_WriteByte(DS1302_WP, 0x80); // BIT7=1，启用写保护

}


/**
  * @brief DS1302读出时间
  * @param 无
  * @retval 无
  */
void DS1302_ReadTime(void)
{
	 // 执行指令，读取时间数据
    unsigned char Temp;
    
    Temp = DS1302_ReadByte(DS1302_YEAR);
    DS1302_Time[0] = Temp / 16 * 10 + Temp % 16;  // BCD码转十进制 -- Temp
    
    Temp = DS1302_ReadByte(DS1302_MONTH);
    DS1302_Time[1] = Temp / 16 * 10 + Temp % 16;
    
    Temp = DS1302_ReadByte(DS1302_DATE);
    DS1302_Time[2] = Temp / 16 * 10 + Temp % 16;
    
    Temp = DS1302_ReadByte(DS1302_HOUR);
    DS1302_Time[3] = Temp / 16 * 10 + Temp % 16;
    
    Temp = DS1302_ReadByte(DS1302_MINUTE);
    DS1302_Time[4] = Temp / 16 * 10 + Temp % 16;
    
    Temp = DS1302_ReadByte(DS1302_SECOND);
    DS1302_Time[5] = Temp / 16 * 10 + Temp % 16;
    
    Temp = DS1302_ReadByte(DS1302_DAY);
    DS1302_Time[6] = Temp / 16 * 10 + Temp % 16;
    
    /*
    RTC的寄存器是以BCD码形式存储的
    用4位二进制数来表示1位十进制数
    例：0001 0011 表示 13  1000 0101 表示 85
    
    BCD码转十进制：DEC = BCD / 16 * 10 + BCD % 16;(2位BCD)
    十进制转BCD码：BCD = DEC / 10 * 16 + DEC % 10;(2位BCD)
    */
}