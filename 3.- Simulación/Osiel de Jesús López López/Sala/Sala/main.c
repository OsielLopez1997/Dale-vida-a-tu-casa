/*
 * Sala.c
 *
 * Created: 20/05/2020 07:05:03 p. m.
 * Author : jesus
 */ 

#include <avr/io.h>
#define F_CPU 16000000L
#include "util/delay.h"

int main(void){
	
	DDRB = 0xff;
	DDRD = 0x00;
	ADCSRA = 0x87;
	ADMUX = 0x40;
	float voltaje = 0;
	
	while (1){
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADIF))){
			ADCSRA |= (1<<ADIF);
			voltaje = (ADCL | (ADCH<<8))*5/1024;
			if (voltaje > 2.0){
				PORTB = 0b00000001;
			} 
			else{
				PORTB = 0b00000000;
			}
			
		}
	}
}

