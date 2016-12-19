#include<reg51.h>
#include"keys.h"
#include"lcd.h"
#include"temp.h"
#include"mo1.h"
#include"mo2.h"
#include"mo3.h"
#include"mo4.h"
										  

void main ()
{
	mo1 ();
	mo2 ();
	mo3 ();
}

/*******************************************************************************
* 函 数 名         : jishi
* 函数功能		   : 准确计时
* 输    入         : num,a,b
* 输    出         : 无
*******************************************************************************/

void jishi ( ) interrupt 1
{
   uchar num; 
   num++;
   if(num==20)
   {
	   s2--;
	   num=0;
   }
   if(s2==-1)
   {
   	   s1--;
	   s2=6;
   }
   if(s1==-1)
   {
   	   m2--;
   	   s1=5;s2=9;
   }
   if(m2==-1)
   {
   	   m1--;
	   m2=9;
   }
   if(s1==0 & s2==0)
   {
   	   if(m1==0 & m2==0)													
	   {
			void mo4 ();							/******倒计时结束时执行的命令******模块4‘和模块4一样的命令*******/											                 
	   }	  	   	
   }
}