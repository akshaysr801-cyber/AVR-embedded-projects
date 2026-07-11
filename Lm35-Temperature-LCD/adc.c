
/*
 * adc.c
 *
 * Created: 05-07-2026 19:57:11
 *  Author: ADMIN
 */ 



#include "adc.h"
#include <avr/io.h>

void adc_init()
{
	ADMUX &= (1 << REFS1);
	ADMUX |= (1 << REFS0);
	
	
	ADCSRA |= (1 << ADEN);
	
	ADCSRA |= ((1 << ADPS0)|(1 << ADPS1)|(1 << ADPS2));
}


uint16_t read_adc(uint16_t channel)
{
	
	
	
	channel &=0x07;
	
	
	ADMUX =(ADMUX & 0xF0) | channel;
	
	ADCSRA |= (1 << ADSC);
	
	
	while (ADCSRA & (1 << ADSC));
	
	
	return ADC;
}