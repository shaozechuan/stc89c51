#include"mo2.h"
#include"mo1.h"
#include"lcd.h"
#include"keys.h"

/*****************************************设定倒计时时间**********************模块2***********************/

unsigned char code zi3[]="Please set time!";
unsigned char code shu2[]="0123456789";
void mo2 ()
{
	lcdwrite_com (0x80);
			for(r=0;r<16;r++)
			{
				lcdwrite_data(zi3[r]);									  //   提示设定倒计时
				delay(1);
			}

			while(1)
			{
				lcdwrite_com (0xc0);
				lcdwrite_data(shu2[m1]);
	
				lcdwrite_com (0xc1);
				lcdwrite_data(shu2[m2]);
	
				lcdwrite_com (0xc2);
				lcdwrite_data(':');
	
				lcdwrite_com (0xc3);
				lcdwrite_data(shu2[s1]);
	
				lcdwrite_com (0xc4);
				lcdwrite_data(shu2[s2]);

				key=0x0f;
				if(key!=0x0f)
				{
					keys();
					if(m==13)
					{
						m2++;
						if(m1==9 & m2==10)
						{
							m1=0;
							m2=0;
						}
						if(m2==10)
						{
							m1++;
							m2=0;
						}
					}

					if(m==14)
					{
						m2--;
						if(m1==0 & m2==-1)
						{
							m1=9;
							m2=9;
						}
						if(m2==-1)
						{
							m1--;
							m2=9;
						}
					}

					if(m==15)
					{
						s2++;
						if(s1==5 & s2==10)
						{
							m2++;
							s1=0;
							s2=0;
						}
						if(s2==10)
						{
							s1++;
							s2=0;
						}
					}

					if(m==16)
					{
						s2--;
						if(s1==0 & s2==-1)
						{	
							m2--;
							s1=5;
							s2=9;
						}
						if(s2==-1)
						{
							s1--;
							s2=9;
						}
					}

					if(m==10)
					{
						goto tt6;
					}
					
				}

			}
			tt6:delay(1);
}