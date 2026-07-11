/*
 * POT using for control of SERVO.c
 *
 * Created: 21-06-2026 15:46:40
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>



void ADC_Init ()
{
	ADMUX |= (1 << REFS0);   // reference vcc
	ADCSRA |=((1 << ADEN)|(1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0));
}
uint16_t ADC_Read (uint8_t ch)
{
	ADMUX =(ADMUX & 0XF0) | ch;
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));
	
	return ADC;
}
void Servo_pwm_init ()
{
	DDRB |= (1 << PB1);  // 0CA1
	
	TCCR1A |= (1 << COM1A1) | (1 << WGM11);
	TCCR1B |=(1 << WGM13) | (1 << WGM12)|( 1 << CS11);
	
	ICR1 = 40000;
}
uint16_t Mapservo(uint16_t adc)
{
	return 2000 +((uint32_t)adc * 2000)/1023;
}



int main(void)
{
   uint16_t adc_value;
   uint16_t pulse_width;
   
   ADC_Init () ;
   Servo_pwm_init ();
   
    

    while (1) 
    {
		adc_value = ADC_Read(0);
		pulse_width = Mapservo(adc_value);
		
		OCR1A = pulse_width;
		
		
    }
}

