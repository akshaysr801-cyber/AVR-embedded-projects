/*
 * Toggle with pushbutton switch.c
 *
 * Created: 08-06-2026 17:52:53
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// PB5 and PB4 as output pins for LEDs
	DDRB |= (1 << PB5);
	DDRB |= (1 << PB4);

	// PD2 as input pin for push button
	DDRD &= ~(1 << PD2);

	// Enable internal pull-up resistor on PD2
	PORTD |= (1 << PD2);

	uint8_t led_state = 0;
	uint8_t last_button_state = 1;

	// Initial condition: LED1 OFF, LED2 ON
	PORTB &= ~(1 << PB5);
	PORTB |= (1 << PB4);

	while (1)
	{
		uint8_t button_state = (PIND & (1 << PD2)) ? 1 : 0;

		// Detect new button press: HIGH to LOW
		if (last_button_state == 1 && button_state == 0)
		{
			_delay_ms(50); // debounce

			if (!(PIND & (1 << PD2)))
			{
				led_state = !led_state;

				if (led_state)
				{
					PORTB |= (1 << PB5);   // LED1 ON
					PORTB &= ~(1 << PB4);  // LED2 OFF
				}
				else
				{
					PORTB &= ~(1 << PB5);  // LED1 OFF
					PORTB |= (1 << PB4);   // LED2 ON
				}
			}
		}

		last_button_state = button_state;
	}
}
