
/*
 * uart.h
 *
 * Created: 30-06-2026 23:57:52
 *  Author: ADMIN
 */ 
#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL
#define BAUDRATE 9600

#define UBRR_VALUE ((F_CPU / (16UL * BAUDRATE)) - 1)

#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>

// void UART_init(void);

// void UART_TxChar(char data);

// void UART_String(const char *str);

// void UART_TxHex(uint8_t value); 

// void UART_TxNumber(uint32_t num);

void UART_init(void);

void UART_TxChar(char data);
char UART_RxChar(void);

void UART_String(const char *str);
void UART_RxString(char *buffer, uint8_t size);

void UART_TxHex(uint8_t value);

void UART_TxNumber(uint32_t num);
void UART_TxInt(int32_t num);

void UART_TxFloat(float value);

uint8_t UART_Available(void);

void UART_NewLine(void);

void UART_ClearBuffer(void);

#endif /* UART_H_ */