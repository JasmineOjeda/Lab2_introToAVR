/*	Jasmine Ojeda jojed016@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise # 2
 *	Exercise Description: Parking lot with 4 pins linked to 4 spaces.
 *	                      Output number of available spaces to Port C
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
    DDRC = 0xFF; PORTC = 0x00;    

    /* Insert your solution below */
    unsigned char cntavail = 0x00;    

    while (1) {
        cntavail = ((PINA & 0x08) >> 3) +
                   ((PINA & 0x04) >> 2) +
                   ((PINA & 0x02) >> 1) +
                    (PINA & 0x01);
        cntavail = 4 - cntavail;
        PORTC = cntavail;
    }
    return 1;
}
