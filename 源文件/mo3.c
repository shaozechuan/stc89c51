#include"mo3.h"
#include"mo1.h"
#include"mo4.h"
#include"mo5.h"
#include"lcd.h"
#include"keys.h"


unsigned char code shu3[]="0123456789";
void mo3 ()
{
	TMOD=0x01;
	        TH0=(65536-50000)/256;
			TL0=(65536-50000)%256;
			EA=1;
			ET0=1;TR0=1;																     //�򿪼�ʱ��
		tt8:lcdinit();
			if(r==3)
			{
				goto tt9;
			}
			while(1)
			{									
				lcdwrite_com (0xc0);
				lcdwrite_data(shu3[m1]);
	
				lcdwrite_com (0xc1);
				lcdwrite_data(shu3[m2]);
	
				lcdwrite_com (0xc2);
				lcdwrite_data(':');
	
				lcdwrite_com (0xc3);
				lcdwrite_data(shu3[s1]);
	
				lcdwrite_com (0xc4);
				lcdwrite_data(shu3[s2]);
								   
		        key=0x0f;										  
				if(key!=0x0f)
				{
					
				    uchar wei[4]={0x80,0x81,0x82,0x83};
					keys();															  
					if(z==0)
					{
					    a2=m;
					    m=0;
						lcdwrite_com (wei[0]);				                    
						lcdwrite_data (shu3[a2]);							//��һλ����w
					}
					if(z==1)
					{
						b2=m;
						m=0;
						lcdwrite_com (wei[1]);				                    
						lcdwrite_data (shu3[b2]);							   //�ڶ�λ����w
					}
					if(z==2)
					{
						c2=m;
						m=0;
						lcdwrite_com (wei[2]);				              //����λ����w     
						lcdwrite_data (shu3[c2]);
					}
					if(z==3)
					{
						d2=m;
						m=0;										      //����λ����z
						lcdwrite_com (wei[3]);				                    
						lcdwrite_data (shu3[d2]);
						goto tt7;						
					}
					z++;				   
				}																												
			}	  	
			tt7:delay(1);
				if(a1==a2 & b1==b2)
				{				
					if(c1==c2 & d1==d2)
					{
						void mo5 ();					     /*******������ȷʱִ�е�����***************ģ��5********************/
					}
				}
				else
				{	
					z=0;
					r++;
					goto tt8;
				}
				
			tt9:while(1);										 /*******�����������ִ�е�����*******ģ��4***************/															
}