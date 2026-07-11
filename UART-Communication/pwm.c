
/*
 * pwm.c
 *
 * Created: 30-06-2026 23:54:53
 *  Author: ADMIN
 */ 
#include <avr/io.h>
#include "pwm.h"

void pwm0_init(void)
{
	/* OC0A (PD6) as output */
	DDRD |= (1 << DDD6);

	/* Fast PWM Mode */
	TCCR0A |= (1 << WGM00) |
	(1 << WGM01);

	TCCR0B &= ~(1 << WGM02);

	/* Non-Inverting Mode */
	TCCR0A |= (1 << COM0A1);
	TCCR0A &= ~(1 << COM0A0);

	/* Prescaler = 64 */
	TCCR0B |= (1 << CS01) |
	(1 << CS00);

	OCR0A = 0;
}
