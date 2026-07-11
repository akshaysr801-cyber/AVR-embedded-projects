
/*
 * uart.h
 *
 * Created: 09-07-2026 19:30:56
 *  Author: ADMIN
 */ 

#ifndef UART_H_
#define  UART_H_


#include <avr/io.h>
#include <stdlib.h>


#define F_CPU 16000000UL
#define BAUDRATE 9600
#define  UBRR_VALUE ((F_CPU / (16UL * BAUDRATE)) - 1)



void UART_Init(void);
void UART_Txchar(char data);
void UART_TxString(const char*str);
void UART_TxHex(uint8_t value);
void UART_TxNumber(uint32_t num);



#endif  