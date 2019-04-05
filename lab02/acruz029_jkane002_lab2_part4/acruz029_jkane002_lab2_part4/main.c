/*
 * Andrew Cruz acruz029@ucr.edu
 * Jonathan Kaneshiro jkane002@ucr.edu
 * Lab Section: 24
 * Assignment: Lab #2 Exercise #4
 */
#include <avr/io.h>

unsigned char GetBit(char port, char bit_pos) {
	return ( port & (0x01 << bit_pos) );
}

unsigned char SetBit(char  pin, char bit_pos, char bit_val) {
	return (bit_val ? pin | (0x01 << bit_pos) : pin & ~(0x01 << bit_pos));
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char actual_weight = 0x00;
	unsigned char shifted_weight = 0x00; 
	
	unsigned char tempA;
	unsigned char tempB;
	unsigned char tempC;
	unsigned char tempD;
	
    /* Replace with your application code */
    while (1) 
    {
		tempA = PINA;
		tempB = PINB;
		tempC = PINC;
		
		if(tempA >= 128) {
			tempA = tempA >> 1;
		}
		if(tempB >= 128) {
			tempB = tempB >> 1;
		}
		if(tempC >= 128) {
			tempC = tempC >> 1;
		}
		
		actual_weight = tempA + tempB + tempC;
		
		if(actual_weight >= 140) {
			PORTD = SetBit(PORTD, 0, 1);
		} else {
			PORTD = 0x00;
		}
		
	}
}

