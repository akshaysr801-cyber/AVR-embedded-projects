
/*
 * ADC.C
 *
 * Created: 17-06-2026 12:25:29
 *  Author: ADMIN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "ADC.H"

void adc_init(void)
{
	// step1 setting reference voltage
	ADMUX |= (( 1 << REFS1) | ( 1 << REFS0));
	//step2 ADC Enable
	ADCSRA |= ( 1 << ADEN);
	//step3 choosing Prescaler value 128 ~ 125hz
	ADCSRA |=(( 1 << ADPS2) | ( 1 << ADPS1) | ( 1 << ADPS0)) ;
}
// read ADC from corresponding given channel (0-7)
    uint16_t read_adc(uint8_t channel)
	{
		//step4 if i choose channel no: 8 it will be 0000 1000  so if we do this 0000 1000 & 0000 0111 = 0000 0000
		channel &= 0x07 ;
		//step5 To clear previous channel and update the register with the new chosen channel
		ADMUX = ( ADMUX & 0XF0) | channel;
		//step6 To start ADC conversion 
		ADCSRA |= ( 1 << ADSC);
		//step7 with the conversation to complete
		while ( ADCSRA &( 1 << ADSC));
		//step8 Return ADC 
		return ADC;
		
		
		
		
	}