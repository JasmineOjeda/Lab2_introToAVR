/*	Jasmine Ojeda jojed016@ucr.edu 
 *	Lab Section: 022
 *	Assignment: Lab 1  Exercise 1
 *	Exercise Description: Garage door, two sensors
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    unsigned char tmpPA0 = 0x00;
    unsigned char tmpPA1 = 0x00;
    /* Insert your solution below */
    while (1) {
        tmpPA0 = PINA & 0x01;
        tmpPA1 = (PINA & 0x02) >> 1;

        PORTB = tmpPA0 && !tmpPA1;
    }
    return 1;
}
