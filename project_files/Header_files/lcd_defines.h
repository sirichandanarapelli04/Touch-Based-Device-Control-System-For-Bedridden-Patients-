//leds port cfg for leds port pins
#define LCD_DATA 16
#define RS 8
#define RW 10
#define EN 9

//commands of LCD
#define CLEAR_LCD 0x01
#define RET_CUR_HOME 0x02

//selection mode in LCD
#define MODE_4BIT_LINE1 0x20
#define MODE_4BIT_LINE2 0x28
#define MODE_8BIT_LINE1 0x30
#define MODE_8BIT_LINE2 0x38

//slection display in LCD
#define  DIS_OFF 0x08
#define  DIS_ON_CUR_OFF 0x0c
#define  DIS_ON_CUR_ON 0x0E
#define  DIS_ON_CUR_BLINK 0x0f

//position selection in lcd
#define GOTO_LINE1_POS0 0x80
#define GOTO_LINE2_POS0 0xc0

//selection of cgram
#define GOTO_CGRAM 0x40
#define GOTO_DDRAM 0x80
#define SHIFT_CUR_RIGHT 0x06