#include <reg51.h>
#define dataport P2
sbit rs = P2 ^ 0;
sbit rw = P2 ^ 1;
sbit e = P2 ^ 2;
int x;

void delay(unsigned int msec)
{
    int i, j;
    for (i = 0; i < msec; i++)
    {
        for (j = 0; j < 1275; j++)
            ;
    }
void lcd_cmd(unsigned char item)
{
    
    unsigned char a;
    a = item & 0xf0;
    dataport = a;
    rs = 0;
    rw = 0;
    e = 1;
    delay(1);
    e = 0;

    a = (item << 4) & 0xf0;
    dataport = a;
    rs = 0;
    rw = 0;
    e = 1;
    delay(1);
    e = 0;
}

void lcd_data(unsigned char item)
{

    unsigned char a;
    a = item & 0xf0;
    dataport = a;
    rs = 1;
    rw = 0;
    e = 1;
    delay(1);
    e=0;
    a = (item << 4) & 0xf0;
    dataport = a;
    rs = 1;
    rw = 0;
    e = 1;
    delay(1);
    e = 0;
}

void message(unsigned char *s)
{
    while (*s)
        lcd_data(*s++);
}

void lcdinit()
{
    lcd_cmd(0x33); 
    lcd_cmd(0x32);
    lcd_cmd(0x28); 
    lcd_cmd(0x06); 
    lcd_cmd(0x0C);
    lcd_cmd(0x01); 
}

void main()
{
    lcdinit();
    lcd_cmd(0x80);
    message("Hello world");
    delay(100);
    while (1)
    {
        lcdinit();
        lcd_cmd(0x80);
        message(" Welcome to 8051");
        lcd_cmd(0xc0);
        message(" Microcontroller");
        delay(100);
    }
}