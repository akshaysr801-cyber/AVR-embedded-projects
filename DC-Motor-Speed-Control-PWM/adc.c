
/*
 * adc.c
 *
 * Created: 07-07-2026 17:36:05
 *  Author: ADMIN
 */ 


#include "adc.h"
#include  <avr/io.h>

void adc_init()   //ADC initialization
{
	
ADMUX  |= (1 << REFS0);  //stp1- setting reference voltage  
ADCSRA |=(1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

uint16_t read_adc(uint16_t channel)
{
	channel &= 0x07;
	
	ADMUX = (ADMUX & 0xF0) | channel;
	
	ADCSRA |= (1<<ADSC);                 // Start conversion

	while (ADCSRA & (1<<ADSC));          // Wait till conversion complete

	return ADC;
}