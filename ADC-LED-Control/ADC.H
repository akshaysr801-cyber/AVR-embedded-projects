
/*
 * ADC.H
 *
 * Created: 17-06-2026 12:25:44
 *  Author: ADMIN
 */ 

#ifndef ADC_H_
#define  ADC_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>

void adc_init(void);
uint16_t read_adc(uint8_t channel);


#endif