/*
 * Read temperature by BMP280  I2C.c
 *
 * Created: 08-07-2026 19:08:11
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"


int main(void)
{
	char data = 'H';
	char string[] = "HELLO";
	uint8_t value = 0xAC;
	UART_Init();
    while (1) 
    {
		UART_Txchar(data);
		UART_TxString(string);
		UART_TxHex(value);
		_delay_ms(1000);
		
    }
}

