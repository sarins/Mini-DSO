/*Register of MCU and Pins defined here*/

#ifndef CONFIG_STC_H
#define CONFIG_STC_H

#include "8051.h"
//#include <STC8.H>
//#define DEBUG

/* ADC采样通道设置
   ADC Channel Setup */
#define ADC_DSO ADC_CHS_06
#define ADC_BAT ADC_CHS_04

/* 特殊功能寄存器
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
__sfr __at(0x8e) AUXR;
__sfr __at(0x94) P0M0;
__sfr __at(0x93) P0M1;
__sfr __at(0x92) P1M0;
__sfr __at(0x91) P1M1;
__sfr __at(0x96) P2M0;
__sfr __at(0x95) P2M1;
__sfr __at(0xb2) P3M0;
__sfr __at(0xb1) P3M1;

/* EC11编码器管脚设置
   Setup EC11 Encoder Pin */
#define EC11_KEY P3_3  //编码器按键连接外部中断1 connect to External Interrupt 1
#define EC11_A P3_2  //编码器A脉冲连接外部中断0 connect to External Interrupt 0
#define EC11_B P3_4  //编码器B脉冲连接普通IO口 connect to GPIO

/* 采样运行指示灯
   Indicator for sampling running */
#define P_Ready P1_1

/*  OLED Pin */
#define OLED_SCLK P2_7  //时钟（D0/SCLK）
#define OLED_SDIN P2_6  //数据（D1/MOSI）
#define OLED_RST P2_5   //复位（RES）
#define OLED_DC P2_4    //数据/命令控制（DC）
#define OLED_CS P2_3    //片选（CS）

#ifdef DEBUG
#define P15 P1_5
#endif

#endif