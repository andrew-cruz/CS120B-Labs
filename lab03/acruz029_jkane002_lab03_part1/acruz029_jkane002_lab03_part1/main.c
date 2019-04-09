/*
 * acruz029_jkane002_lab03_part1.c
 *
 * Created: 4/9/2019 10:29:37 AM
 * Author : ucrcse
 */ 

#include <avr/io.h>

unsigned char getBit(unsigned char x, unsigned char k) {
	return((x & (0x01 << k)) != 0); 
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Replace with your application code */
    
	
	while (1) 
    {
		unsigned char count = 0x00;
		for(int i = 0; i < 8; i++) {
			if(getBit(PINA,i) != 0)
				count++;
			if(getBit(PINB, i) != 0)
				count++;
		}
		
		PORTC = count;
    }
}

