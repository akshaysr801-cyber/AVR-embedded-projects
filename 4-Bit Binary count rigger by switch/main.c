/*
 * 4-Bit Binary count rigger by switch.c
 *
 * Created: 13-06-2026 15:27:51
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void update_leds(uint8_t count)
{
	PORTB = (PORTB & 0xF0) | (count & 0x0F);
}

int main(void)
{
	DDRB|= ( 1 << PB0 ) | ( 1 << PB1 ) | ( 1 << PB2 ) | ( 1 << PB3 );
    DDRD &=~ ( 1 << PD2);
	
    PORTD |= ( 1 << PD2 );
	 uint8_t count = 0;
	 uint8_t last_button_state = 1;
	 
    while (1) 
    {  
		uint8_t button_state ;
		button_state = (PIND & ( 1 << PD2 )) ? 1:0;
		
		if (last_button_state == 1 && button_state == 0 )
		{
			count ++;
		}
		
		if(count > 15)
		{
			count = 0 ;
       }
    update_leds(count);
	_delay_ms(50);
	last_button_state = button_state ;
	}
	
}

