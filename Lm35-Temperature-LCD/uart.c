
/*
 * uart.c
 *
 * Created: 05-07-2026 19:55:15
 *  Author: ADMIN
 */ 


#include "uart.h"

void uart_init()
{
	
	UBRR0H = 0;
	UBRR0L = 103;
	
	
	UCSR0B |= ((1 << TXEN0)|(1 << RXEN0));
	
	
	UCSR0B &=~(1 << UCSZ02);
	UCSR0C |=((1 << UCSZ01)|(1 << UCSZ00));
	
	UCSR0C &=~ ((1 << UPM00)|(1 << UPM01));
	
	UCSR0C &=~ (1 << USBS0);
}


void uart_transmit(char data)
{
	
	
	while (!(UCSR0A &(1 << UDRE0)));
	
	UDR0 = data;
}


void uart_TxString(const char*str)
{
	while(*str)
	{
		
		uart_transmit(*str++);
	}
}