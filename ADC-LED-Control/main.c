


#define  F_CPU 16000000UL
#include <avr/io.h>
#include "ADC.H"

int main(void)
{
	DDRD |=((1 << PD0) | (1 << PD1) | (1 << PD2) | (1 << PD3) | (1 << PD4));
    while (1)
	{
		uint16_t adc_value = read_adc(0);
		if (adc_value < 100)
		{
			PORTD = 0x00;
		}
		else if (adc_value <= 204)
		{
			PORTD = 0x01;
		}
		else if (adc_value <= 409)
		{
			PORTD = 0x03;
		}
		else if (adc_value <= 614)
		{
			PORTD = 0x07;
		}
		else if (adc_value <= 819)
		{
			PORTD = 0x0F;
		}
		else
		{
			PORTD = 0x1F;
		}
	}
			return 0;
}