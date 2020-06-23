/*
 * servo atmel.c
 *
 * Created: 08/06/2020 09:48:11 a. m.
 * Author : jesus
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include "util/delay.h"

int main(void){
	
	DDRB = 0xff;  // puesrto b como salida
	PORTB |= (1<<9); 
	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(0<<COM1B1)|(0<<COM1B0)|(1<<WGM11)|(0<<WGM00); // configuracion registro del timer 1, para elegir la salida pwm
	TCCR1B = (0<<ICNC1)|(0<<ICES1)|(1<<WGM13)|(1<<WGM12)|(0<<CS12)|(1<<CS11)|(0<<CS10); // configuracion del timer que contiene el activado o desactivado del mismo
	TCCR1C = (0<<FOC1A)|(0<<FOC1B);
	TCNT1 = 0;
	OCR1A = 0; // valor salida del pwm por el pin OCR1A
	OCR1B = 0;
	ICR1 = 27647; // Valor top del pwm para obtener una frecuencia de 50hz
	TIMSK1 = 0; // se deshabilitan interrupciones
	TIFR1 = 0;
	
	while(1){
	
		OCR1A = 1675; // valor de la salida pwm para que el servo permanezca en cero grados
		_delay_ms(2000);
		OCR1A = 4000; // valor de la salida pwm para que el servo permanezca en noventa grados
		_delay_ms(2000);
	}
}	


