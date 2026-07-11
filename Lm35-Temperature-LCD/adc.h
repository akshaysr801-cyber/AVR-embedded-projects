
/*
 * adc.h
 *
 * Created: 05-07-2026 19:57:24
 *  Author: ADMIN
 */ 


#ifndef ADC_H_
#define ADC_H_
#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdint.h>

void adc_init();
uint16_t read_adc(uint16_t channel);

#endif 