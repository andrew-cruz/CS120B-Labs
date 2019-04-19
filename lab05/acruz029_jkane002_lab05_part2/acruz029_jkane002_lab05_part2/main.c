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

enum Num_States {Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine} Num_State;

void State_Machine() {
	unsigned char PA_01 = PINA & 0x03;
	
	switch(Num_State) {
		case Zero: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = Zero; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = One;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = Zero;
			}
			break;
		}
		case One: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = Zero; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = Two;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = One;
			}
			break;
		}
		case Two: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = One; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = Three;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = Two;
			}
			break;
		}
		case Three: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = Two; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = Four;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = Three;
			}
			break;
		}
		case Four: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = Three; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = Five;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = Four;
			}
			break;
		}
		case Five: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = Four; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = Six;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = Five;
			}
			break;
		}
		case Six: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = Five; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = Seven;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = Six;
			}
			break;
		}
		case Seven: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = Six; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = Eight;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = Seven;
			}
			break;
		}
		case Eight: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = Seven; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = Nine;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = Eight;
			}
			break;
		}
		case Nine: {
			if(PA_01 == 0x02) { //Decrementing: PA0 is 0 PA1 is 1
				Num_State = Eight; //Stay In Same State
				} else if(PA_01 == 0x01) { //Incrementing: PA0 is 1 PA1 is 0
				Num_State = Nine;
				} else if(PA_01 == 0x03) { //Both Depressed: PA0 is 1 PA1 is 1
				Num_State = Zero;
				} else { //Both Not Pressed
				Num_State = Nine;
			}
			break;
		}
		default : { //Errors go to state Zero
			Num_State = Zero;
			break;
		}
	}
	unsigned char tempB = 0xFF;
	switch(Num_State) {
		case Zero: {
			tempB = 0;
			break;
		}
		case One: {
			tempB = 1;
			break;
		}
		case Two: {
			tempB = 2;
			break;
		}
		case Three: {
			tempB = 3;
			break;
		}
		case Four: {
			tempB = 4;
			break;
		}
		case Five: {
			tempB = 5;
			break;
		}
		case Six: {
			tempB = 6;
			break;
		}
		case Seven: {
			tempB = 7;
			break;
		}
		case Eight: {
			tempB = 8;
			break;
		}
		case Nine: {
			tempB = 9;
			break;
		}
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
		State_Machine();
		
	}
}


