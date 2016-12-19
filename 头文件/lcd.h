#ifndef __lcd_H_
#define __lcd_H_

#include<reg51.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

#define LCD1602_DATAPINS P0
sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;

void delay (uint i);

void lcdwrite_com(uchar com);

void lcdwrite_data(uchar dat);

void init();

#endif

