/*
 * Andrew Cruz acruz029@ucr.edu
 * Jonathan Kaneshiro jkane002@ucr.edu
 * Lab Section: 24
 * Assignment: Lab #2 Exercise #4
 */
#include <avr/io.h>


int main(void)
{
	// Init output
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char actual_weight = 0x00;
	unsigned char edge_weight = 0x00;
	
	while(1){
		PORTD = 0x00;
		unsigned char tempA = PINA;
		unsigned char tempB = PINB;
		unsigned char tempC = PINC;
		
		if(tempA != 0x00 || tempB != 0x00 || tempC != 0x00) {
				actual_weight = tempA + tempB + tempC;
				if(actual_weight == 0)
					actual_weight = 141;
		} else {
			actual_weight = tempA + tempB + tempC;
		} 
		//Get edge weight difference
		edge_weight = tempA > tempC ? tempA - tempC : tempC - tempA;
		
		//Check to see if weight is exceeded
		if (actual_weight > 140) {
			PORTD = PORTD | 0x01;
		}
		//Check to see if edges are balanced
		if (edge_weight > 80) {
			PORTD = PORTD | 0x02;
		}
		
		//Store actual weight to PORTD 
		PORTD = PORTD | actual_weight;
	}
}

