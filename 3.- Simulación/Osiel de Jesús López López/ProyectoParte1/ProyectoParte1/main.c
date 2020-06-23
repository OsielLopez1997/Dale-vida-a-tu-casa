/*
 * ProyectoParte1.c
 *
 * Created: 21/06/2020 08:46:20 a. m.
 * Author : jesus
 */ 

#include <avr/io.h>
#define F_CPU 16000000L
#include "util/delay.h"

int main(void){
	
	DDRB = 0xff;
	DDRD = 0x00;
	DDRC = 0x00;
	ADCSRA = 0x87;
	ADMUX = 0x40;
	float voltaje = 0;
	
	PORTB |= (1<<9);
	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(0<<COM1B1)|(0<<COM1B0)|(1<<WGM11)|(0<<WGM00);
	TCCR1B = (0<<ICNC1)|(0<<ICES1)|(1<<WGM13)|(1<<WGM12)|(0<<CS12)|(1<<CS11)|(0<<CS10);
	TCCR1C = (0<<FOC1A)|(0<<FOC1B);
	TCNT1 = 0;
	OCR1A = 0;
	ICR1 = 27647;
	TIMSK1 = 0;
	TIFR1 = 0;
	
	while (1){
		
		if (PIND & 0b00000001){
			PORTB = (1<<2);
		}
		if (PIND & 0b00000010){
			PORTB &=~ (1<<2);
		}
		
		if (PIND & 0b00000100){
			OCR1A = 4000;
			_delay_ms(5000);
			OCR1A = 1675;
		}
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA & (1<<ADIF))){
			ADCSRA |= (1<<ADIF);
			voltaje = (ADCL | (ADCH<<8))*5/1024;
			if (voltaje > 2.0){
				PORTB |= (1<<0);
			}
			else{
				PORTB &=~ (1<<0);
			}
		}
	}
}

