#include<lpc21xx.h>
#include"delay.h"
#include"define.h"
#include"lcd_defines.h"
#include"lcd.h"
void cmdLCD(unsigned char cmd)
{
   IOCLR0=(1<<RS);
   writeLCD(cmd);
}
void writeLCD(unsigned char data)
{
   IOCLR0=(1<<RW);
   WRITEBYTE(IOPIN0,LCD_DATA,data);
   IOSET0=(1<<EN);
   delay_us(1);
   IOCLR0=(1<<EN);
   delay_ms(2);
}

 void charLCD(unsigned char ascii)
{
   IOSET0=(1<<RS);
   writeLCD(ascii);
}
void intialize_LCD(void)
{
  //cfg the output pins in leds
  WRITEBYTE(IODIR0,LCD_DATA,0xff);

  //cfg as output
  IODIR0|=(1<<RS);
  IODIR0|=(1<<RW);
  IODIR0|=(1<<EN);
  delay_ms(15);
  cmdLCD(MODE_8BIT_LINE1);
  delay_ms(1);
  cmdLCD(MODE_8BIT_LINE1);
  delay_ms(1);
  cmdLCD(MODE_8BIT_LINE1);

  cmdLCD(MODE_8BIT_LINE2);
  cmdLCD(DIS_ON_CUR_OFF);
  cmdLCD(CLEAR_LCD);
  cmdLCD(SHIFT_CUR_RIGHT);
}
void strLCD(signed char *str)
{
   while(*str)
   {
       charLCD(*str);
           str++;
   }
}
void intLCD(int n)
{
     int i=0;
   int a[10];
   if(n==0)
   {
     charLCD('0');
   }
   else
   {
       while(n)
           {
       a[i++]=(n%10)+48;
       n=n/10;
           }
       for(--i;i>=0;i--)
       {
         charLCD(a[i]);
       }
    }
}