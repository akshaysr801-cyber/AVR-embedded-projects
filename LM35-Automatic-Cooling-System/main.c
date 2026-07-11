/*
 * Automated cooling system using LM35.c
 *
 * Created: 16-06-2026 17:29:38
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t system_on =0;

void ADC_Init (void)
{
	ADMUX |= ( 1 << REFS0); 
	ADCSRA |= ( 1 << ADEN) | ( 1 << ADPS2 ) | ( 1 << ADPS1) | ( 1 << ADPS0);
	
}
uint16_t Read_ADC(uint8_t channel)
{
	ADMUX = (ADMUX & 0XF8)|channel;
	ADCSRA |= ( 1 << ADSC);
	while (ADCSRA & ( 1 << ADSC));
	return ADC ;
}

float READ_Temperature()
{
	uint16_t adc_value ;
	adc_value = Read_ADC(0);
	float voltage = (adc_value * 5.0)/ 1023.0;
	float temperature = voltage * 100.0 ;
	return temperature;
}

void PWM_Init()
{
	 DDRD |= (1 << PD6);   // OC0A
	 

	 TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);

	 TCCR0B |= (1 << CS01) | (1 << CS00);

	 OCR0A = 0;
}
void Motor_Control(float temp)
{
	if(temp < 30)
	{
		OCR0A = 30;      // 30%
	}
	else
	{
		OCR0A= 255;     // 100%
	}
}
void Check_button()
{
	if(!(PIND & (1 << PD2)))
	{
		_delay_ms(50);
		
		if(!(PIND & (1 << PD2)))
		{
			system_on ^= 1;
			
			while(!(PIND & (1 << PD2)));
		}
	}
}

int main()
{
    ADC_Init();
    PWM_Init();
	
	DDRD |= ( 1 << PD7);
	DDRB |= ( 1 << PB0);
	
	PORTD |= (1<<PD7);
	PORTB &= ~(1<<PB0);
	

    DDRD &= ~(1 << PD2);      // Button input
    PORTD |= (1 << PD2);      // Internal pull-up

    
    while (1) 
    {
		 Check_button();

		 
		 if(system_on)
		 {
			 float temperature ;
			 temperature = READ_Temperature();
			 Motor_Control(temperature);

			 _delay_ms(200);   // Debounce
		 }
		 else
		 {
			 OCR0A = 0;   // Motor OFF
		 }
		 _delay_ms(200);
	 }
    }


