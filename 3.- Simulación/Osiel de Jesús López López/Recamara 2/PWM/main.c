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
	
	DDRD |= (1<<6); // pin 6 del puerto d como salida
	DDRC = 0; // puerto c como entrada
	OCR0A = 0; // inicializacion del OCR0A (salida PWM en el pin pd6) como 0
	TCCR0A |= (1<<COM0A1)|(1<<WGM01)|(1<<WGM00); // configuracion del registro del timer 0 para el tipo de salida PWM
	TCCR0B = 0x01;
	
	ADCSRA = 0x87; // configuracion del registro que se encarga de controlar las acciones del adc
	ADMUX = 0x40; // se configura el pin A0 del adc como entrada,la referencia de voltaje,entre otras cosas
	float voltaje = 0; // variable que servira para convertir el valor digital a su correspondiente en analogico

	while (1){
		ADCSRA |= (1<<ADSC); // se incia la conversion del adc
		while ((ADCSRA & (1<<ADIF))){ // bucle que ordena que mientras se cumpla la condicion realizara lo que a continuacion se describe
			ADCSRA |= (1<<ADIF); // se para la conversion del adc
			voltaje = (ADCL | (ADCH<<8))*5/1024; // se convierte el valor digital a voltaje
			OCR0A = (voltaje*255)/5; // Esta linea de codigo hace que la salida PWM dependa del valor de voltaje que hay a la entrada del micro
		}
	}
}

