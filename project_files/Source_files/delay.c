void delay_s(unsigned int a)
{
     a*=12000000;
         while(a--);

}
void delay_us(unsigned int a)
{
   a*=12;
   while(a--);
}
void delay_ms(unsigned int a)
{
a*=12000;
while(a--);
}