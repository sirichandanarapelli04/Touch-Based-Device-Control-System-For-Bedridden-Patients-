#include<lpc21xx.h>
#include"define.h"
#include"kpm_defines.h"
unsigned int kpmLUT[4][4]={{'1','2','3','+'},
                           {'4','5','6','-'},
                           {'7','8','9','*'},
                           {'*','0','#','/'}};
void intialize_kpm(void)
{
    //cfg row pins as output
        WRITEBYTE(IODIR1,ROW0,0xf);
        //colums defaultly zero so no need to configured
}

int ColScan(void)
{
   if(((IOPIN1>>COL0)&15)<15)
   {
       return 0;
   }
   else
   {
       return 1;
   }
}
int rowcheck(void)
{
   int rno;
   for(rno=0;rno<=3;rno++)
   {
      WRITENIBBLE(IOPIN1,ROW0,~(1<<rno));
          if(ColScan()==0)
          {
             break;
          }
   }
          WRITENIBBLE(IOPIN1,ROW0,0x0);
          return rno;
}
int colcheck(void)
{
      int cno;
          for(cno=0;cno<3;cno++)
          {
              if(STATUSBIT(IOPIN1,(COL0+cno))==0)
                  {
                     break;
                  }
    }
        return cno;
}
int KeyScan(void)
{
    int rno,cno;
        int keyv;
   //wait for switch press
   while(ColScan());
   //take the row no
   rno=rowcheck();
   //take the col no
   cno=colcheck();
   //collect keyvalue from kpmlut
   keyv=kpmLUT[rno][cno];

   return keyv;

}
