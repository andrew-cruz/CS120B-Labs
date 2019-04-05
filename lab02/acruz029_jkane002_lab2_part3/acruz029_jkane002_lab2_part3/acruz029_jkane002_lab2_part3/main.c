/*
 * Andrew Cruz acruz029@ucr.edu
 * Jonathan Kaneshiro jkane002@ucr.edu
 * Lab Section: 24
 * Assignment: Lab #2 Exercise #3
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
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char tmp;
	//unsigned char cntavail = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		//unsigned char cntavail = 0x00;
		tmp = PINA;
		
		
		if(tmp != 0x0F) {
			PORTC = ~tmp;
			PORTC = SetBit(PORTC, 4, 0);
			PORTC = SetBit(PORTC, 5, 0);
			PORTC = SetBit(PORTC, 6, 0);
			PORTC = SetBit(PORTC, 7, 0);
		} else {
			PORTC = 0x80;
		}
		
    }
}
