/*
 * LED-Running-Pattern.c
 *
 * Created: 10-06-2026 18:57:10
 * Author : ADMIN
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0XFF; //set all PORTB pin as o/p
    while (1) 
    { for (uint8_t i=0 ; i<8 ; i++)
		{
			PORTB = ( 1 << i);  //Turn on only LED
			
			_delay_ms(200); //delay
    }
}
}

