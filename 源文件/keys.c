#include"keys.h"
#include"lcd.h"

#include<reg51.h>

/*******************************************************************************
* �� �� ��       : keys
* ��������		 : ɨ��������
* ��    ��       : ��
* ��    ��       : m
*******************************************************************************/

uint n,m;
void keys ( )
{  
   key=0x0f;
   if(key!=0x0f)
  {
	delay(5);
	if(key!=0x0f)
	{
	 switch (key)
	 {																						   //��Ӧ��������			      //   ԭ��ֵ
		  case 0x0e:n=1;break;																   //  1  2  3   ����+	13		  //  1  2  3  4
		  case 0x0d:n=5;break;																   //  4  5  6   ����-	14		  //  5  6  7  8
		  case 0x0b:n=9;break;																   //  7  8  9   ��+	15		  //  9  10 11 12
		  case 0x07:n=13;break;																   //  ��  0  #   ��- 	16		  //  13 14 15 16
	 }																						   // 10 11 12
	}
   
	key=0xf0;
	if(key!=0xf0)
   {
     delay(5);
	 if(key!=0xf0);
	 {
	 switch (key)
	 {
		  case 0xe0:n=n;break;											   //�õ�����  n
		  case 0xd0:n=n+1;break;
		  case 0xb0:n=n+2;break;
		  case 0x70:n=n+3;break;
	 }
	 switch(n)
	 {
	 	 case 1:m=1;n=0;break;
		 case 2:m=2;n=0;break;
		 case 3:m=3;n=0;break;
		 case 4:m=13;n=0;break;
		 case 5:m=4;n=0;break;
		 case 6:m=5;n=0;break;
		 case 7:m=6;n=0;break;
		 case 8:m=14;n=0;break;
		 case 9:m=7;n=0;break;
		 case 10:m=8;n=0;break;
		 case 11:m=9;n=0;break;
		 case 12:m=15;n=0;break;
		 case 13:m=10;n=0;break;
		 case 14:m=11;n=0;break;
		 case 15:m=12;n=0;break;
		 case 16:m=16;n=0;break;											//�õ��µĶ�Ӧ��ֵ	 m
	 }
	while(key!=0xf0);
	}
	delay(5);												       
	while(key!=0xf0);
    }
  }
}
