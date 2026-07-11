/*
 * Toggle led connected to portD5.c
 *
 * Created: 13-06-2026 15:12:05
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
     DDRD |= ( 1 << PD5 );
	
    while (1) 
    {
		 PORTD |= ( 1 << PD5 );
		 _delay_ms(3000);
		 PORTD &=~ ( 1 << PD5 );
		 _delay_ms(5000);
    }
}

