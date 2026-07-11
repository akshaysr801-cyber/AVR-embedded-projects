/*
 * Traffic light controller using INTERRUPT.c
 *
 * Created: 15-06-2026 19:44:27
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h> 
#include <util/delay.h>

#define  GREEN   PB0
#define  ORANGE  PB1
#define  RED     PB2

volatile uint8_t emergencyFlag = 0;
void delay_sec(uint8_t sec)
{
	while(sec--)
	{
		for(uint16_t i =0; i < 1000; i++)
		{
			_delay_ms(1);
		}
	}
}
void setLight(uint8_t light)
{
	PORTB &=~ (( 1 << GREEN) | ( 1 << ORANGE) | ( 1 << RED));
	PORTB |= ( 1 << light);
	}

void setup(void)
{
  DDRB |= ( 1 << PB0) | ( 1 << PB1) | ( 1 << PB2 ); // o/p
  DDRD &=~ ( 1 << PD2 );
  PORTD |= ( 1 << PD2 );
  
  EICRA |= ( 1 << ISC01);
  EICRA &=~ ( 1 << ISC00);
  
  EIMSK |= ( 1 << INT0);
  
  sei();
    
	}
ISR(INT0_vect)
{
	emergencyFlag = 1;
} 
void handleEmeregencyifNeeded(void)
{
	if(emergencyFlag)
	{
		setLight(GREEN);
		delay_sec(10);
		emergencyFlag = 0;
	}
}
  int main (void)
  {
	  setup();
  

    while (1) 
    {
		setLight(GREEN);
		delay_sec(10);
		handleEmeregencyifNeeded();
		
		
		setLight(ORANGE);
		delay_sec(3);
		handleEmeregencyifNeeded();
		
		setLight(RED);
		delay_sec(10);
		handleEmeregencyifNeeded();
		
		
    }
  }


