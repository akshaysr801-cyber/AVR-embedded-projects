/*
 * UART.c
 *
 * Created: 24-06-2026 00:32:04
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
  
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "uart.h"
#include "pwm.h"

char rx_buffer[10];
uint8_t brightness = 0;

void pwm_set_brightness(uint8_t percent) {
	OCR0A = ((uint32_t)percent * 255) / 100;
}
int main(void) {
	UART_init();
	pwm0_init();
	UART_String("UART LED Control Ready\r\n");
	while (1) {
		UART_RxString(rx_buffer, sizeof(rx_buffer)); // RECEIVE. FUCTION

		if (rx_buffer[0] == '\0') { // EMPTY CHECK
			continue;
		}

		//if (strcmp(rx_buffer, "ON") == 0) { // CHECK ON

		if(rx_buffer[0] == 'O' && rx_buffer[1] == 'N' && rx_buffer[2] == '\0')

		{
			OCR0A = 255;
			UART_String("LED is now ON\r\n");
		}
		//  else if (strcmp(rx_buffer, "OFF") == 0) { // CHECK OFF
		else if(rx_buffer[0] == 'O' && rx_buffer[1] == 'F' &&  rx_buffer[2] == 'F' && rx_buffer[3] == '\0')

		{

			OCR0A = 0;
			UART_String("LED is now OFF\r\n");
			} else {
			uint8_t valid = 1;
			for (uint8_t i = 0; rx_buffer[i] != '\0'; i++) {
				if (rx_buffer[i] < '0' || rx_buffer[i] > '9') { // CHECKING ALPHABETS CHARACTERS ONLY VALID NUMBERS 0 TO 99
					valid = 0;
					break;
				}
			}
			if (valid) {
				brightness = 0;

				for (uint8_t i = 0; rx_buffer[i] != '\0'; i++) {
					brightness =(brightness * 10) + (rx_buffer[i] - '0'); // SET BRIGHTNESS
				}
				if (brightness <= 100) {
					pwm_set_brightness(brightness);
					UART_String("Brightness set to ");
					UART_TxNumber(brightness);
					UART_String("%\r\n");
					} else {
					UART_String("Invalid Command\r\n");
				}
				} else {
				UART_String("Invalid Command\r\n");
			}
		
				}
			}
			}
		
		
	

	

		
			 
  		




