#include <REGX52.H>

sbit LED = P2^0;

// ��ʱ����
void Delay(unsigned int t)
{
    while(t--);  // ѭ��������ÿ��ѭ������һ����������
}

void main()
{
    unsigned char Time, i;  // �������Time���ڿ���LED���ȣ�i����ѭ������
    
    while(1)
    {
        // Ts = Ton + Toff�������� = ��ʱ�� + ��ʱ�䣩
        
        // ��-->��
        for(Time = 0; Time < 100; Time++)  // Time��0���ӵ�99������LED�𽥱���
        {
            for(i = 0; i < 20; i++)  // �ظ�20�Σ�ʹLED״̬�ȶ�
            {
                LED = 0;  // LED��������͵�ƽ������
                Delay(Time);  // ��ʱ��������
                LED = 1;  // LED�𣨸ߵ�ƽϨ��
                Delay(100 - Time);  // ��ʱ���𽥼���
            }
        }
        
        // ��-->��
        for(Time = 100; Time > 0; Time--)  // Time��100���ٵ�1������LED�𽥱䰵
        {
            for(i = 0; i < 20; i++)  // �ظ�20�Σ�ʹLED״̬�ȶ�
            {
                LED = 0;  // LED��
                Delay(Time);  // ��ʱ���𽥼���
                LED = 1;  // LED��
                Delay(100 - Time);  // ��ʱ��������
            }
        }        
    }
}