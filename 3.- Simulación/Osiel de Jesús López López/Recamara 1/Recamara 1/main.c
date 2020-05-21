/*
 * Recamara 1.c
 *
 * Created: 20/05/2020 07:17:03 p. m.
 * Author : jesus
 */ 

#include <avr/io.h>
#define F_CPU 16000000L
#include "util/delay.h"

int main(void)
{
    DDRD = 0x00;
	DDRB = 0xff;
	
    while (1){
		if (PIND & 0b00000001){
			PORTB = 0b00000001;
		}
		if (PIND & 0b00000010){
			PORTB = 0b00000000;
		}
    }
}

