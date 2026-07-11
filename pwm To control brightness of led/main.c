/*
 * pwm To control brightness of led.c
 *
 * Created: 13-06-2026 23:38:01
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


uint8_t dutyLevels[] = {64,128,192,255};
uint8_t level = 0;
void updatepwm(uint8_t duty)
{
	OCR0A = duty ;
	
}
void PWMInit(void)
{
	

DDRD |= ( 1 << PD6); // Port 6 as o/p
DDRB &=~ ( 1 << PB2 ); // Port 2 as i/p
PORTB |= ( 1 << PB2); // Enable pull up resistor

TCCR0A |= ( 1 << COM0A1) | ( 1 << WGM00) | ( 1 << WGM01) ;  //  Fast PWM mode,non inverting o/p
TCCR0B |= ( 1 << CS00) | ( 1 << CS01) ;    // Prescaler 64
}


int main(void)
{  
	PWMInit();
	
	
    while (1) 
    {
		if (!(PINB&(1 << PB2)))
		{
			_delay_ms(50);
			
			if (!(PINB & ( 1 << PB2)))
			{
				level++;
				if (level >= 4)
				{
					level = 0;
				 }
				 updatepwm(dutyLevels[level]);
				 while (!(PINB & (1 << PB2)))
				 {
					 // Wait until button is released
				 }

				 _delay_ms(50);
				 
}
		}
	}
}

