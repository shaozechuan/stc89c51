#include"mo1.h"
#include"lcd.h"
#include"keys.h"

/***********************************显示  Are you ready?及提示设置密码******************模块1**************/
unsigned char code zi1[]=" Are you ready? ";
unsigned char code zi2[]="  Set password! ";
unsigned char code shu1[]="0123456789";

uint r=0;
uint m=0;
uint z=0;
uint a1=0;
uint b1=0;
uint c1=0;
uint d1=0;
uint a2=0;
uint b2=0;
uint c2=0;
uint d2=0;
uint m1=0;
uint m2=0;
uint s1=0;
uint s2=0;
 
void mo1 ()
{
	lcdinit();
	lcdwrite_com (0x80);
	for(r=0;r<16;r++)
	{
		lcdwrite_data (zi1[r]);									  //   Are you sure ?
		delay(1);
	}
	while(1)
	{
		key=0x0f;
		if(key!=0x0f)
		{	keys();
			if(m==10)
			{
				goto tt0;
			}
		}
	}
	tt0:delay(1);
	lcdinit();
	lcdwrite_com (0x80);
	for(r=0;r<16;r++)
	{
		lcdwrite_data (zi2[r]);									  //  提示设置密码
		delay(1);
	}
												  
			while(1)														 
			{						   										   
	            key=0x0f;										  
				if(key!=0x0f)
				{
					keys();
					a1=m;
					lcdwrite_com (0xc0);				                    
					lcdwrite_data (shu1[a1]);
					goto tt1;					                     			//第一位
				}
			}
			tt1:delay(1);

			while(1)
			{
				key=0x0f;
				if(key!=0x0f)
				{
					keys();
					b1=m;
					lcdwrite_com (0xc1);				                    
					lcdwrite_data (shu1[b1]);
					goto tt2;					                     
				}
			}
			tt2:delay(1);														//第二位

			while(1)
			{
				key=0x0f;
				if(key!=0x0f)
				{
					keys();
					c1=m;
					lcdwrite_com (0xc2);				                    
					lcdwrite_data (shu1[c1]);
					goto tt3;					                     
				}																//第三位				}

			}
			tt3:delay(1);

			while(1)
			{
				key=0x0f;
				if(key!=0x0f)
				{
					keys();
					d1=m;
					lcdwrite_com (0xc3);				       
					lcdwrite_data (shu1[d1]);
					goto tt4;													//第四位
				}
			}						                           
			tt4:delay(1);

			lcdinit();
	        lcdwrite_com (0x80);
	        for(r=0;r<16;r++)
	        {
				lcdwrite_data (zi1[r]);									  //  提示是否确定
				delay(1);
	        }
			while(1)
			{
				key=0x0f;
				if(key!=0x0f)
				{	keys();
					if(m==10)
					{
						goto tt5;
					}
					if(m==12)
					{
						goto tt0;
					}
				}
			}
			tt5:delay(1);
			lcdinit();
}