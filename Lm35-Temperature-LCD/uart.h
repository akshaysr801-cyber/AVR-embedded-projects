
/*
 * uart.h
 *
 * Created: 05-07-2026 19:55:30
 *  Author: ADMIN
 */ 


#ifndef UART_H_
#define UART_H_


#include <avr/io.h>
#include <stdlib.h>


#define F_CPU 16000000UL
#define BAUDRATE 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUDRATE)) - 1)


void uart_init();
void uart_transmit(char data);
void uart_TxString(const char*str);


#endif 