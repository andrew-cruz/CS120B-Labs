/*
 * Andrew Cruz acruz029@ucr.edu
 * Jonathan Kaneshiro jkane002@ucr.edu
 * Lab Section: 24
 * Assignment: Lab #2 Exercise #1
 *
 * I acknowledge all content contained herein, excluding template or example
 * code. is my own original work.
 */ 

#include <avr/io.h>


int main(void)
{
	// Garage Door - Bit 1; Light - Bit 0;
	DDRA = 0x00; PORTA = 0xFF;
	//LED Light
	DDRB = 0xFF; PORTB = 0x00;
	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		tmpA = PINA;
		
		if(tmpA == 0x00) {
			tmpB = (tmpB & 0xFC) | 0x00;
		} else if(tmpA == 0x01) {
			tmpB = (tmpB & 0xFC) | 0x01;
		} else if(tmpA == 0x02) {
			tmpB = (tmpB & 0xFC) | 0x00;
		} else if(tmpA == 0x03) {
			tmpB = (tmpB & 0xFC) | 0x00;
		}
		
		PORTB = tmpB;
    }
	
	return 0;
}

