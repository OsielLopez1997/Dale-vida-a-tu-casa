/*
 * PWM.c
 *
 * Created: 04/06/2020 11:35:52 a. m.
 * Author : jesus
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include "util/delay.h"

int main(void){
	DDRB = 0xff;
	DDRD |= (1<<6);
	DDRC = 0;
	OCR0A = 0;
	TCCR0A |= (1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
	TCCR0B = 0x01;
	
	ADCSRA = 0x87;
	ADMUX = 0x40;
	float voltaje = 0;

	while (1){
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADIF))){
			ADCSRA |= (1<<ADIF);
			voltaje = (ADCL | (ADCH<<8))*5/1024;
			OCR0A = (voltaje*255)/5;
		}
		
		if (PIND & (1<<PIND0)){
			PORTB |= (1<<PORTB5);
		} 
		else{
			PORTB &=~ (1<<PORTB5);
		}
	}
}

