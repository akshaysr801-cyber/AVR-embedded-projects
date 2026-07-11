/*
 * 9digit on led screen.c
 *
 * Created: 21-06-2026 19:42:29
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "lcd.h"

uint32_t count = 0;
uint16_t  ButtonHoldTime() 
{
	uint16_t t = 0 ;
	while(!(PIND & (1 << PD2)))
	{
		_delay_ms(10);
		t += 10;
	}
	return t;
} 
void LCD_DisplayNumber(uint32_t num)
{
	char str[12];
	sprintf(str,"%09lu", num);
	
	lcd_clear();
lcd_print(str);
}



int main(void)
{
   DDRD &=~(1 << PD2);
   PORTD |= (1 << PD2);
   
   lcd_init ();
   LCD_DisplayNumber(count);
   
       while (1) 
    {
		 if(!(PIND & (1<<PD2)))
		 {
			 uint16_t hold = ButtonHoldTime();

			 if(hold >= 2000)
			 count = 0;
			 else
			 count++;

			 LCD_DisplayNumber(count);
		 }
    }
}

