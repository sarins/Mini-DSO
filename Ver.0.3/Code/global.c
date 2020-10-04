#include "global.h"

uint16 Lsb;                                                //��������˷�ѹϵ��x100 / Input voltage dividing coefficient x 100
uint16 VBat;                                               //��ص�ѹ / Voltage of battery
uint8 WaveLength;                                          //���� / Wave length
uint32 WaveFreq;                                           //��Ƶ�� / Wave frequency
int16 TriLevel;                                            //�û��趨����ֵ��mV / Trigger Level in mV
uint8 TriPos;                                              //����λ�� / Trigger Position
int8 TriPosOffset;                                         //����λ��ƫ���� / Trigger Position Offset
int16 RulerVMin, RulerVMax;                                //�����ѹ�����Сֵ / Min and Max voltage on vertical ruler
uint16 VMax, VMin;                                         //��Ļ���ε�������С��ѹmV������65535mV
uint16 *BGV;                                               //�ڲ�BG�ο���ѹ
uint16 ADCbg;                                              //�ڲ�BG�ο�ADC
uint16 TriggerADC;                                         //����ֵADC
uint16 WaveLengthSumNum;                                   //ƽ�����γ�����ʹ���
uint32 WaveLengthSum;                                      //ƽ�ֲ��γ������
int8 ScaleH_tmp;                                           //��ʱ��¼������ɵ�ʱ������
uint8 OLED_Brightness;                                     //OLED����1-254
// bit OLED_BrightnessChanged;                                //OLED�޸ı�־λ
// bit DisplayUpdate;                                         //������Ļ��Ϣ��־λ
// bit EC11PressAndRotate;                                    //EC11����������ͬʱ��ת��־λ
// bit DisplayUpdate;                                         //������Ļ��Ϣ��־λ
// bit ClearDisplay;                                          //�����Ļ��־λ
// bit ClearWave;                                             //��ղ��α�־λ
// bit ADCRunning;                                            //ADC������־λ
// bit ADCInterrupt;                                          //ADC�����жϱ�־λ
// bit UpdateVbat;                                            //���µ�ص�ѹ��Ϣ��־λ
// bit OptionChanged;                                         //���ñ��޸ı�־λ
// bit InSettings;                                            //�������ý����־λ
// bit PlotMode;                                              //��ͼģʽ 0:Vect 1:Dots
// bit TriSlope;                                              //��������1������������0���½�����
// bit TriFail;                                               //����ʧ�ܱ�־λ
// bit WaveScroll;                                            //���ι�����־λ
// bit WaveUpdate;                                            //���²��α�־λ
// bit ScaleV_Auto;                                           //�Զ����̱�־λ
// bit ADCComplete;                                           //ADC��ɲ�����Ϊ���β�������
__bit OLED_BrightnessChanged;                                //OLED�޸ı�־λ
__bit DisplayUpdate;                                         //������Ļ��Ϣ��־λ
__bit EC11PressAndRotate;                                    //EC11����������ͬʱ��ת��־λ
__bit DisplayUpdate;                                         //������Ļ��Ϣ��־λ
__bit ClearDisplay;                                          //�����Ļ��־λ
__bit ClearWave;                                             //��ղ��α�־λ
__bit ADCRunning;                                            //ADC������־λ
__bit ADCInterrupt;                                          //ADC�����жϱ�־λ
__bit UpdateVbat;                                            //���µ�ص�ѹ��Ϣ��־λ
__bit OptionChanged;                                         //���ñ��޸ı�־λ
__bit InSettings;                                            //�������ý����־λ
__bit PlotMode;                                              //��ͼģʽ 0:Vect 1:Dots
__bit TriSlope;                                              //��������1������������0���½�����
__bit TriFail;                                               //����ʧ�ܱ�־λ
__bit WaveScroll;                                            //���ι�����־λ
__bit WaveUpdate;                                            //���²��α�־λ
__bit ScaleV_Auto;                                           //�Զ����̱�־λ
__bit ADCComplete;
int8 ScaleH = 2;                                           //ʱ�����䣬0-11��Ӧ500ms-100us
int8 OptionInSettings;                                     //���ý����ѡ�����, 0:TriS, 1:PlotMode, 2:LSB
int8 OptionInChart;                                        //�������ѡ�����, 0:ScaleH, 1:ScaleV, 2:TriLevel, 3:TriSlope, 4:TriMode
int8 TriMode;                                              //������ʽ��2:���� 1����ͨ��0���Զ�
                                                           //�Զ�ģʽ:�����������û��ֶ�ֹͣ
                                                           //��ͨ��������ֹͣ���������Զ��ȴ��´δ���
                                                           //���Σ�������ֹͣ�������û��ֶ���ʼ�ȴ��´δ���
uint16 ADCbuf[SAMPLE_NUM];                                 //����ԭʼ��������
uint8 __code *PlotModeTxt[] = {"Vect", "Dots"};              //��ͼģʽ����
uint8 __code *TriModeTxt[] = {"Auto  ", "Normal", "Single"}; //������ʽ����
uint8 __code *ScaleHTxt[] =                                  //ˮƽ�������
    {
        "500ms", //0
        "200ms", //1
        "100ms", //2
        "50ms",  //3
        "20ms",  //4
        "10ms",  //5
        "5ms",   //6
        "2ms",   //7
        "1ms",   //8
        "500us", //9
        "200us", //10
        "100us"  //11
};