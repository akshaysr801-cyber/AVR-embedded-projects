/*
 * Traffic light control.c
 *
 * Created: 13-06-2026 16:10:07
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>



void timer0_delay_ms(uint16_t ms)
{
	uint16_t count ;
	for(count = 0; count < ( ms / 16); count++)
	{
		TCNT0;
		
		TCCR0A &= ~( 1 << WGM00 ) | ( 1 << WGM01);
		TCCR0B  |= ( 1 << CS02) | ( 1 << CS00 );
		TCCR0B &=~ ( 1 << CS01);
		
		while(!(TIFR0 & (1 << TOV0)))
		{
			
		}
		TIFR0 |= ( 1 << TOV0 ) ;
		
	}
}


int main(void)
{
    DDRB |= ( 1 << PB1) | ( 1 << PB2 ) | ( 1 << PB3 );
	PORTB |=  ( 1 << PB1) | ( 1 << PB2 ) | ( 1 << PB3 );
    while (1) 
    { 
		PORTB = ( 1 << PB1 );
		timer0_delay_ms(10000);
		PORTB = ( 1 << PB2 );
		timer0_delay_ms(3000);
 		 
		 PORTB = ( 1 << PB3 );
		 timer0_delay_ms(10000);
		
		
    }
}

