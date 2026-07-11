/*
 * Regulate speed of motor.c
 *
 * Created: 07-07-2026 17:30:17
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"



void fast_pwm_init()
{
	DDRD |=(1 << PD6);
	
	
	TCCR0A |= (1 << WGM00) | (1 << WGM01);
	TCCR0B &=~ (1 << WGM02);
	
	TCCR0A &=~(1 << COM0A0);
	TCCR0A |= (1 << COM0A1);
	
	TCCR0B |= (1 << CS01)|(1 << CS00);
	TCCR0B &=~(1 << CS02);
	
	OCR0A = 0;
	
}


int main(void)
{
  fast_pwm_init();
  adc_init();

    while (1) 
    {
		uint16_t adc_value = read_adc(0);
		
		
		
		
		OCR0A = (uint8_t)(adc_value >> 2);
		
		_delay_ms(10);
    }
}

