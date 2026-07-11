
/*
 * adc.h
 *
 * Created: 07-07-2026 17:36:20
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
