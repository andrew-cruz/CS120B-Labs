/*	Partner 1 Name & E-mail: Andrew Cruz acruz029@ucr.edu
 *	Partner 2 Name & E-mail: Jonathan Kaneshiro jkane002@ucr.edu
 *	Lab Section: 24
 *	Assignment: Lab # 3  Exercise # 4 
 *	Exercise Description: [optional - include for your own benefit]
 *		(Challenge): Read an 8-bit value on PA7..PA0 and write that value on PB3..PB0PC7..PC4. 
 *		That is to say,  take the upper nibble of PINA and map it to the lower nibble of PORTB, 
 *		likewise take the lower nibble of PINA and map it to the upper nibble of PORTC 
 *		(PA7 -> PB3, PA6 -> PB2, … PA1 -> PC5, PA0 -> PC4).
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}


int main(void)
{
	//Init inputs
	DDRA = 0x00; PORTA = 0xFF;
	//Init outputs
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	
	//Get inputs
	unsigned char tempA = 0x00;
	//Stores outputs
	unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;
	//Stores bit
	unsigned char bit = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		tempA = PINA;
		tempB = 0x00;
		tempC = 0x00;
		
		//Set PA7 -> PB3
		bit = GetBit(tempA,7);
		tempB = SetBit(tempB,3,bit); 	
		
		//Set PA6 -> PB2
		bit = GetBit(tempA,6);
		tempB = SetBit(tempB,2,bit);
		
		//Set PA5 -> PB1
		bit = GetBit(tempA,5);
		tempB = SetBit(tempB,1,bit);
		
		//Set PA4 -> PB0
		bit = GetBit(tempA,4);
		tempB = SetBit(tempB,0,bit);
		
		//Set PA3 -> PC7
		bit = GetBit(tempA,3);
		tempC = SetBit(tempC,7,bit);
		
		//Set PA2 -> PC6
		bit = GetBit(tempA,2);
		tempC = SetBit(tempC,6,bit);
		
		//Set PA1 -> PC5
		bit = GetBit(tempA,1);
		tempC = SetBit(tempC,5,bit);
    
		//Set PA0 -> PC4
		bit = GetBit(tempA,0);
		tempC = SetBit(tempC,4,bit);
		
		PORTB = tempB;
		PORTC = tempC;
	}
}

