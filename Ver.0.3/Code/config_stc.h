/*Register of MCU and Pins defined here*/

#ifndef CONFIG_STC_H
#define CONFIG_STC_H

#include "8051.h"
//#include <STC8.H>
//#define DEBUG

/* ADC����ͨ������
   ADC Channel Setup */
#define ADC_DSO ADC_CHS_06
#define ADC_BAT ADC_CHS_04

/* ���⹦�ܼĴ���
    Special Function Register */
// sfr AUXR = 0x8e;
// sfr P0M0 = 0x94;
// sfr P0M1 = 0x93;
// sfr P1M0 = 0x92;
// sfr P1M1 = 0x91;
// sfr P2M0 = 0x96;
// sfr P2M1 = 0x95;
// sfr P3M0 = 0xb2;
// sfr P3M1 = 0xb1;
__sfr __at (0x8e) AUXR;
__sfr __at (0x94) P0M0;
__sfr __at (0x93) P0M1;
__sfr __at (0x92) P1M0;
__sfr __at (0x91) P1M1;
__sfr __at (0x96) P2M0;
__sfr __at (0x95) P2M1;
__sfr __at (0xb2) P3M0;
__sfr __at (0xb1) P3M1;

/* EC11�������ܽ�����
   Setup EC11 Encoder Pin */
#define EC11_KEY P3_3 //���������������ⲿ�ж�1 connect to External Interrupt 1
#define EC11_A P3_2   //������A���������ⲿ�ж�0 connect to External Interrupt 0
#define EC11_B P3_4   //������B����������ͨIO�� connect to GPIO

/* ��������ָʾ��
   Indicator for sampling running */
#define P_Ready P1_1

/*  OLED Pin */
#define OLED_SCLK P2_7 //ʱ�ӣ�D0/SCLK��
#define OLED_SDIN P2_6 //���ݣ�D1/MOSI��
#define OLED_RST P2_5  //��λ��RES��
#define OLED_DC P2_4   //����/������ƣ�DC��
#define OLED_CS P2_3   //Ƭѡ��CS��

#ifdef DEBUG
#define P15 P1_5
#endif

#endif