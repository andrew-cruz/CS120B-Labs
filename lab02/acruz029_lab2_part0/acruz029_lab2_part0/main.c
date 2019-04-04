/*
 * acruz029_lab2_part0.c
 *
 * Created: 4/4/2019 9:52:39 AM
 * Author : ucrcse
 */ 

#include <avr/io.h>


int main(void)
{
    /*DDRB = 0XFF; // Configure port B's 8 pins as outputs
	PORTB = 0X00; // Initialize PORTB output to 0's
	
	while(1) {
		PORTB = 0x0f; // Writes port B's 8 pins with 00001111
	}*/
	
	/*DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as outputs
	DDRB = 0xFF; PORTB = 0X00; // Initialize PORTB output to 0's
	
	unsigned char temp_input = 0x00;
	
	while(1) {
		temp_input = PINA;
		PORTB = temp_input; // Writes port B's 8 pins with 00001111
	}*/
	
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as outputs
	DDRB = 0xFF; PORTB = 0X00; // Initialize PORTB output to 0's
	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	
	
	while(1) {
		// 1) Read input
		tmpA = PINA & 0x01;
		// 2) Perform computation
		// if PAO is 1, set PB1PB0 = 01, else = 10
		if(tmpA == 0x01) { //true if PAO is 1
			tmpB = (tmpB & 0xFC) | 0x01; //Set tmpB to bbbbbb01
										// (clear rightmost 2 bits, then set to 01)
		} else{
			tmpB = (tmpB & 0xFC) | 0x02; //Set tmpB to bbbbbb10
			// (clear rightmost 2 bits, then set to 10)
		}
		//3) Write output
		PORTB = tmpB;
	}
	
	return 0;
}

