/*
 * Microcontroller.cpp
 *
 * Created: 18.07.2019 20:49:34
 * Author : Alex
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0b00000111;
	DDRB = 0b00000111;
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(450);
		PORTB = 0b00000111;
		_delay_ms(180);
		PORTB = 0b00000000;
		_delay_ms(180);
		PORTB = 0b00000111;
		_delay_ms(180);
		PORTB = 0b00000000;
		_delay_ms(180);
		PORTC = 0b00000111;
		_delay_ms(280);
		PORTC = 0b00000000;
    }
}

