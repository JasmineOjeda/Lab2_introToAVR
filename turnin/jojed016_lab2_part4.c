/*	Jasmine Ojeda jojed016@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise # 4
 *	Exercise Description: 
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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;    
    DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    unsigned char tmp_PD0 = 0x00;        
    unsigned char tmp_PD1 = 0x00;
    unsigned char total = 0x00;

    if ((PINA > 140) | (PINB > 140) | (PINC > 140)) {
        tmp_PD0 = 0x01;
    }

    total = PINA + PINB + PINC;

    if (total > 140) {
        tmp_PD0 = 0x01;
    }

    if (((PINA - PINC) > 80) | ((PINC - PINA) > 80)) {
        tmp_PD1 = 0x01;
    }

    total = total & 0xFC;
    
    PORTD = total | tmp_PD0 | tmp_PD1;
    return 1;
}
