#include"spi_defines.h"
#include<lpc21xx.h>
#include"delay.h"
#include"types.h"
#include"kpm.h"
#include"lcd.h"
char password[4];
char checker[4];
void Init_SPI(void)
{
   //cfg p0.4 p0.5 p0.6 pin using PINSEL0
   PINSEL0|=0x00000100;
   PINSEL0|=0x00000400;
   PINSEL0|=0x00001000;

   //make p0.7(cs) as high using IOSET0/IOPIN0
  IOSET0=1<<CS;
   //cfg p0.7 as gpio output pin using IODIR0
   IODIR0|=1<<CS;
   //cfg spi clock speed using S0SPCCR
  S0SPCCR=LOADVAL;
   //cfg spi peripheral for Master Mode & Mode3
   S0SPCR=1<<MSTR|3<<CPHA;
}



u8 spi(u8 sDat)
{
   //load sDat into S0SPDR
   S0SPDR=sDat;
   // wait for transmission to complete
   //using S0SPSR and   monitoring SPIF bit
  while(((S0SPSR>>SPIF)&1)==0);
   // return read data from S0SPDR;
  return S0SPDR;
}

void WriteEnable(void)
{
  //make chip select low
  IOCLR0=1<<CS;
  //issue WREN via spi tranfer
  spi(WREN);
 //make chip select high
 IOSET0=1<<CS;
}

void WriteDisable(void)
{
  //make chip select low
                IOCLR0=1<<CS;
   //issue WRDI via spi transfer
                        spi(WRDI);
  //make chip select high
                IOSET0=1<<CS;
}

void spi_eeprom_bytewrite(u16 wBuffAddr,u8 sDat)
{
   //Enable Write Enable Latch
                WriteEnable();
   //make chip select low
 IOCLR0=1<<CS;
   //issue WRITE instruction via spi transfer
  spi(WRITE);
   //msbyte of 16-bit address loc via spi transfer
  spi(wBuffAddr>>8);

  //lsbyte of 16-bit address loc via spi transfer
        spi(wBuffAddr);
  //data for that address loc
        spi(sDat);
  //make chip select high
  IOSET0=1<<CS;
 //delay for internal write cycle
 delay_ms(5);
 //Disable Write Enable Latch
  WriteDisable();
}


u8 spi_eeprom_byteread(u16 rBuffAddr)
{
  u8 rDat;
  //make chip select low
  IOCLR0=1<<CS;
  //issue READ instruction
    spi(READ);
 //msbyte of 16-bit address loc to be read via spi
 spi(rBuffAddr>>8);
  //lsbyte of 16-bit address loc to be read via spi
   spi(rBuffAddr);
  //sending garbage & reading data at loc
  rDat=spi(0X00);
  //make chip select high
 IOSET0=1<<CS;
  return rDat;
}
void spi_eeprom_pagewrite(u16 Wbufferaddr,u8 *p,u8 nbytes)
{
   u8 i;
   WriteEnable();
   IOCLR0=1<<CS;
   spi(WRITE);
   spi(Wbufferaddr>>8);
   spi(Wbufferaddr);
   for(i=0;i<nbytes;i++)
   {
      spi(p[i]);
   }
   IOSET0=1<<CS;
   delay_ms(100);
   WriteDisable();
}
void spi_eeprom_pageread(u16 Wbufferaddr,u8 *p,u8 nbytes)
{
   u8 i;
   IOCLR0=1<<CS;
   spi(READ);
   spi(Wbufferaddr>>8);
   spi(Wbufferaddr);
   for(i=0;i<nbytes;i++)
   {
      p[i]=spi(0x00);
   }
   p[i]='\0';
   IOSET0=1<<CS;

}
void setandreadpassword()
{
        spi_eeprom_pageread(0x0000,(u8 *)password,4);    //This is same as checker, just used to copy the new updated password and stored in the this variable, and this statement is used to read that.
        delay_ms(5);
        spi_eeprom_pageread(0x0000,(u8 *)checker,4); //Will read the password from the EEEPROM and store in checker
}
void inputpass(char *str)
{
        int vflag=0;
                int i=0;
        cmdLCD(0xc0);
        for(i=0;i<5;i++)         // total 5 inputs, last one is for the enter key, I took enter key as any key other than digits
        {
                if(vflag)
                {
                        i=0;
                        vflag=0;
                }
                str[i]=KeyScan();        //takes the key values
                if(str[i]=='+')  //"+" is treated as backspace here
                {
                        i=i-1;   //to delete the previously entered key 'o' is decremented.
                        cmdLCD(0xc0 + i);         //position will be travelled to the 'o' that is previous position
                        charLCD(' ');     //space is printed in that previous position
                        if(i==0)
                        {
                                vflag=1;          //if o==0,that is in the starting if we press the backspace then oflag will be "1".
                        }
                        i=i-1;   //This decrementation is because to replace the next iteration in the previous iteration, because in the for loop it will automatically increment, so to get the proper position we decremented it
                        if(i<0)
                                i=0;     //if 'o' is negative then we made it '0'.
                }
                else                     //if the pressed key is some digit instead of back space then it will enter this block
                {
                        if(i!=4)         //From 0 to 4, 4th key is enter key, this condition is while it is not enter key
                        {
                                cmdLCD(0xc0 + i);         //Travel to the particular position
                                //charLCD(str[i]);
                                charLCD('*');     //Will Print the Encripted Password.
                        }
                }
                delay_ms(500);
        }
}




