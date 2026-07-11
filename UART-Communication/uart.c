
/*
 * uart.c
 *
 * Created: 30-06-2026 23:56:39
 *  Author: ADMIN
 */ 
#include "uart.h"
#include <stdlib.h>

void UART_init(void)
{
	UBRR0H = (unsigned char)(UBRR_VALUE>>8); // 103 -> 0000 0000 0110 0111 >> 8 = 0000 0000
	UBRR0L = (unsigned char)UBRR_VALUE;
	
	//UCSR0B = (1<<TXEN0);
	UCSR0B = (1<<TXEN0) | (1<<RXEN0);
	UCSR0C = ((1 << UCSZ01)|(1<< UCSZ00));
}
void UART_TxChar(char data)
{
	while(!(UCSR0A&(1<<UDRE0)));
	UDR0 =  data;
	
}

void UART_String(const char *str)
{
	
	while(*str)
	{
		UART_TxChar(*str++);
	}
}

void UART_TxHex(uint8_t value)
{
	const char hexChars[] = "0123456789ABCDEF";
	char hex[5];
	hex[0] = hexChars[(value >> 4) & 0x0f];
	hex[1] = hexChars[value & 0x0f];
	hex[2] = '\r';
	hex[3] = '\n';
	hex[4] = '\0';
	UART_String("0x");
	UART_String(hex);
}

void UART_TxNumber(uint32_t num)
{
	
	char buffer[12];
	ltoa(num,buffer,10);
	UART_String(buffer);
}

char UART_RxChar(void)
{
	while(!(UCSR0A & (1<<RXC0)));

	return UDR0;
}

void UART_RxString(char *buffer,uint8_t size)
{
	uint8_t i=0;

	while(i < size-1)
	{
		char ch = UART_RxChar();

		if(ch=='\r' || ch=='\n')
		break;

		buffer[i++] = ch;
	}

	buffer[i]='\0';
}

void UART_TxFloat(float value)
{
	uint16_t int_part;
	uint16_t frac_part;

	int_part=(uint16_t)value;

	frac_part=
	(uint16_t)((value-int_part)*100);

	UART_TxNumber(int_part);

	UART_TxChar('.');

	if(frac_part<10)
	UART_TxChar('0');

	UART_TxNumber(frac_part);
}
uint8_t UART_Available(void)
{
	return (UCSR0A & (1<<RXC0));
}
void UART_ClearBuffer(void)
{
	char dummy;

	while(UCSR0A & (1<<RXC0))
	{
		dummy = UDR0;
	}
}