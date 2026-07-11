/*
 * Two independed timer task simultaniously.c
 *
 * Created: 16-06-2026 11:04:29
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t timer1_count = 0 ;
volatile uint8_t timer2_count = 0;

ISR(TIMER1_COMPA_vect)
{
	timer1_count++;
	if(timer1_count >= 2 ) 
	{
		PORTB ^= ( 1 << PB1);
		timer1_count = 0;
	
	}
}
ISR(TIMER2_COMPA_vect)
{
	timer2_count++;

	if(timer2_count >= 31)   // ? 500 ms
	{
		PORTB ^= (1 << PB2);
		timer2_count = 0;
	}
}
void timer1_init(void)
{
	/* CTC Mode */
	TCCR1B |= (1 << WGM12);

	/* Prescaler = 1024 */
	TCCR1B |= (1 << CS12) | (1 << CS10);

	/* 1 second interrupt */
	OCR1A = 15624;   // 16000000/1024 = 15625 -1 = 15624

	/* Enable Compare Match A Interrupt */
	TIMSK1 |= (1 << OCIE1A);
}

void timer2_init(void)
{
	/* CTC Mode */
	TCCR2A |= (1 << WGM21);

	/* Prescaler = 1024 */
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);

	/* Compare value */
	OCR2A = 249;

	/* Enable Compare Match A Interrupt */
	TIMSK2 |= (1 << OCIE2A);
}



int main(void)
{
     DDRB |= ( 1 << PB1 ) | ( 1 << PB2); 
	 
	 timer1_init();
	 timer2_init();
	 sei();
    while (1) 
    {
    }
}

