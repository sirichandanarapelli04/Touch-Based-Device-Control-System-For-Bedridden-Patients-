#include"types.h"
void Init_SPI(void);
u8 spi(u8 sDat);
void WriteEnable(void);
void WriteDisable(void);
void spi_eeprom_bytewrite(u16 wBuffAddr,u8 sDat);
u8 spi_eeprom_byteread(u16 rBuffAddr);
void spi_eeprom_pagewrite(u16 Wbuffer,u8 *p,u8 nbytes);
void spi_eeprom_pageread(u16 Wbuffer,u8 *p,u8 nbytes);
void inputpass(char *str);
void setandreadpassword();
void spi1();
