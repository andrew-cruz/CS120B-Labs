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
	DDRD = 0x00; PORTD = 0x00;
	
	unsigned char actual_weight = 0x00;
	unsigned char edge_weight = 0x00;
	
	while(1){
		//Get total weight
		actual_weight = PINA + PINB + PINC;
		//Get edge weight difference
		edge_weight = PINA > PINC ? PINA - PINC : PINC - PINA;
		
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

