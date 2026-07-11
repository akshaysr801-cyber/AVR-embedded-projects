
/*
 * ACS.C
 *
 * Created: 17-06-2026 15:39:41
 *  Author: ADMIN
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "ACS.H"

void adc_init(void)
{
	
ADMUX |= (( 1 << REFS0) | ( 1 << REFS1));
ADCSRA |= ( 1 << ADEN) | ( 1 << ADPS2 ) | ( 1 << ADPS1) | ( 1 << ADPS0);
}

//Step1 setting reference voltage
 