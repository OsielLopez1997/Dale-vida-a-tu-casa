/*
 * ADC.h
 *
 * Created: 26/03/2019 06:43:42 p.m.
 *  Author: Marlon
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>

void ADC_init();
int ADC_GetData(int canal);

#endif /* ADC_H_ */