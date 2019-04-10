/*	Partner 1 Name & E-mail: Andrew Cruz acruz029@ucr.edu
 *	Partner 2 Name & E-mail: Jonathan Kaneshiro jkane002@ucr.edu
 *	Lab Section: 24
 *	Assignment: Lab # 3  Exercise # 1 
 *	Exercise Description: [optional - include for your own benefit]
 *		Count the number of 1s on ports A and B and output that number on port C.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

unsigned char getBit(unsigned char x, unsigned char k) {
	return((x & (0x01 << k)) != 0); 
}

int main(void)
{
		//init inputs
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
		//init outputs
	DDRC = 0xFF; PORTC = 0x00;
    
		//Temp variables for read
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	while (1) 
    {
			//keep count
		unsigned char count = 0x00;
		tempA = PINA;
		tempB = PINB;
		
			//check number of 1's in PINA and PINB
		for(int i = 0; i < 8; i++) {
			if(getBit(tempA,i) != 0)
				count++;
			if(getBit(tempB, i) != 0)
				count++;
		}
			//Set to PORTC
		PORTC = count;
    }
}

