/*
 * uart.c
 *
 * Created: 09-07-2026 19:31:15
 *  Author: ADMIN
 */ 

#include "uart.h"

void UART_Init(void)
{
	/* Loading baud rate to UBRR0H and UBRR0L */
	UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
	UBRR0L = (unsigned char)UBRR_VALUE;
	
	UCSR0B = (1 << TXEN0);  // Enable transmitter
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);   // 8 bit data 
	
}
/* UART function to print the character*/
void UART_Txchar(char data)
{
	while (!(UCSR0A &(1 << UDRE0)));
	UDR0 = data;
	
}
/* UART function to print a string */
void UART_TxString(const char*str)
{
	while (*str) 
	{
		UART_Txchar(*str++);
	}
}

/* UART  function to print the hex value */
void UART_TxHex(uint8_t value)
{
	const char hexchars[] = "0123456789ABCDEF"	;
	char hex[5];
	hex[0] = hexchars[(value >> 4) & 0x0F];
	hex[1] = hexchars[value & 0x0F];
	hex[2] = '\r';
	hex[3] = '\n';
	hex[4] = '\0';
	UART_TxString("0x");
	UART_TxString(hex);
}
/* UART function to print the number */
void UART_TxNumber(uint32_t num)
{
	char buffer[12];
	ltoa(num, buffer, 10);   // convert to string (long to ASCII)
	UART_TxString(buffer);
}