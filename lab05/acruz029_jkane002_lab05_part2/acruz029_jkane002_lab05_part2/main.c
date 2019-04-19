/*	Partner 1 Name & E-mail: Andrew Cruz acruz029@ucr.edu
 *	Partner 2 Name & E-mail: Jonathan Kaneshiro jkane002@ucr.edu
 *	Lab Section: 24
 *	Assignment: Lab # 5  Exercise # 2 
 *	Exercise Description: [optional - include for your own benefit]
 *		(From an earlier lab) Buttons are connected to PA0 and PA1. 
 *		Output for PORTB is initially 0. 
 *		Pressing PA0 increments PORTB (stopping at 9). 
 *		Pressing PA1 decrements PORTB (stopping at 0). 
 *		If both buttons are depressed (even if not initially simultaneously), PORTB resets to 0. 
 *		If a reset occurs, both buttons should be fully released before additional increments or decrements are allowed to happen. 
 *		Use LEDs (and resistors) on PORTB. 
 *		Use a state machine (not synchronous) captured in C.
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



enum Num_States {Wait, Increment, Decrement, ButtonRelease, Reset, ResetRealse} Num_State;

void State_Machine() {
	unsigned char PA_01 = PINA & 0x03;
	PA_01 = ~PA_01 & 0x03;
	
	switch(Num_State) {
		case Wait: {
			if(PA_01 == 0x01) { //Increment PA1 = 0 PA0 = 1
				Num_State = Increment;
			} else if(PA_01 == 0x02) { //Decrement PA1 = 1 PA0 = 0
				Num_State = Decrement;
			} else if(PA_01 == 0x03) { //Reset PA1 = 1 PA0 = 1
				Num_State = Reset;
			} else { //Anything else resets 
				Num_State = Reset;
			}
		}
		case Increment: {
			Num_State = Wait;
		}
		case Decrement: {
			Num_State = Wait;
		}
		case Reset: {
			if(PA_01 == 0x03) { //Both Button still depressed
				Num_State = Reset;
			} else if (PA_01 == 0x00) { //If both buttons get depressed
				Num_State = Wait;
			} else { //Anything else goes to reset
				Num_State = Reset;
			}
		}
		default : { //Errors go to state Wait
			Num_State = Reset;
			break;
		}
	}
	unsigned char tempB = 0x00;
	
	switch(Num_State) {
		default : { //Errors go to state Zero
			tempB = 0xFF;
			break;
		}
	}
	
	PORTB = tempB;
}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	Num_State = Seven;
	
	while (1)
	{
		//PORTB = PINA;
		State_Machine();
		
	}
}


