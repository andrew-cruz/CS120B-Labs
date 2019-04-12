/* Partner 1 Name & E-mail: Andrew Cruz acruz029@ucr.edu
* Partner 2 Name & E-mail: Jonathan Kaneshiro jkane002@ucr.edu
* Lab Section: 24
* Assignment: Lab #4 Exercise #3
* Exercise Description: [optional - include for your own benefit]
*	A household has a digital combination deadbolt lock system on the doorway.
*	The system has buttons on a keypad. Button 'X' connects to PA0, 'Y' to PA1,
*	and '#' to PA2. Pressing and releasing '#', then pressing 'Y', should unlock the door by setting PB0 to 1.
*	Any other sequence fails to unlock. Pressing a button from inside the house (PA7) locks the door (PB0=0).
*	For debugging purposes, give each state a number, and always write the current state to PORTC (consider using the enum state variable).
*	Also, be sure to check that only one button is pressed at a time.
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>
#define locked 0x00;
#define unlocked 0x01;

enum Lock_States {Lock, One, Two, Three, Four, Five} Lock_State;

void SM_Door_Lock() {
	unsigned char PA_0 = PINA & 0x01;
	unsigned char PA_1 = PINA & 0x02;
	unsigned char PA_2 = PINA & 0x04;
	unsigned char PA_7= PINA & 0x80;
	
	switch(Lock_State) {
		case Lock: { //Start State and locking state
			Lock_State = One;
		}
		case One: {
			if( (!PA_0 && !PA_1) && (PA_2 && !PA_7) ) { //Move to Next State if Pressing only '#'(PA_2) and door is not being locked from inside(PA_7)
				Lock_State = Two;
			} else if(PA_7) { //If PA_7 is pressed go to lock state
				Lock_State = Lock;
			} else { //Any other combination will bring you back to start state(One)
				Lock_State = One;
			}
			break;
		}
		case Two: { //'#' pressed state
			if( (!PA_0 && !PA_1) && (PA_2 && !PA_7) ) { //Stay in stat if still holding '#'(PA_2) down and door is not being locked from inside(PA_7)
				Lock_State = Two;
			} else if(PA_7) { //If PA_7 is pressed go to lock state
				Lock_State = Lock;
			} else if( (!PA_0 && !PA_1) && (!PA_2 && !PA_7)  ) { //Move to Next State if nothing is being held down
				Lock_State = Three;
			} else { //Any other combination will bring you back to start state(One)
				Lock_State = One;
			}
			break;
		}
		case Three: { //'#' release state
			if( (!PA_0 && !PA_1) && (!PA_2 && !PA_7) ) { //Stay in stat if still not holding anything down
				Lock_State = Three;
			} else if(PA_7) { //If PA_7 is pressed go to lock state
				Lock_State = Lock;
			} else if( (!PA_0 && PA_1) && (!PA_2 && !PA_7)  ) { //Move to Next State if 'Y'(PA_1) is held down and  door is not being locked from inside(PA_7)
				Lock_State = Four;
			} else { //Any other combination will bring you back to start state(One)
				Lock_State = One;
			}
			break;
		}
		case Four: { //Y pressed but not released state
			if( (!PA_0 && PA_1) && (!PA_2 && !PA_7) ) { //Stay in state if still 'Y'(PA_1) is held down and  door is not being locked from inside(PA_7)
				Lock_State = Four;
			} else if(PA_7) { //If PA_7 is pressed go to lock state
				Lock_State = Lock;
			} else if( (!PA_0 && !PA_1) && (!PA_2 && !PA_7)  ) { //Move to Next State if nothing is being held down
				Lock_State = Five;
			} else { //Any other combination will bring you back to start state(One)
				Lock_State = One;
			}
			break;
		}
		case Five: { //Unlock State
			if( PA_7 ) { //If door is locked from inside(PA_7) then go to lock state(One)
				Lock_State = One;
			} else if(PA_7) { //If PA_7 is pressed go to lock state
				Lock_State = Lock;
			} else if( (!PA_0 && !PA_1) && (PA_2 && !PA_7) ) { //Pressing '#' will continue to State 2 to check sequence 
				Lock_State = Two;
			} else { //Anything other than door being locked from inside(PA_7) will keep door unlocked
				Lock_State = Five;
			}
			break;
		}
		default: { //Any error brings us back to Lock State
			Lock_State = Lock;
			break;
		}
	} //Transitions
	
	//Stores where door is locked or unlocked
	unsigned char tempB;
	//Stores what state we are in
	unsigned char tempC;
	unsigned char previousB = PORTB & 0x01;
	switch(Lock_State) {
		case Lock: {
			tempB = locked;
			tempC = 0x00;
			break;
		}
		case One: {	//State One door is locked
			tempB = previousB;
			tempC = 0x01;
			break;
		}
		case Two: { //State Two door is locked
			tempB = previousB;
			tempC = 0x02;
			break;
		}
		case Three: { //State Three door is locked
			tempB = previousB;
			tempC = 0x03;
			break;
		}
		case Four: { //State Four door is locked
			tempB = previousB;
			tempC = 0x04;
			break;
		}
		case Five: { //State Five door is unlocked
			tempB = (previousB) ? locked : unlocked;
			tempC = 0x05;
			break;
		}
		default: {
			tempB = locked;
			tempC = 0x01;
			break;
		}
	} //Actions
	
	//Set PORTB and PORTC to values
	PORTB = tempB;
	PORTC = tempC;
	
}

int main(void)
{
	//Init SM to first state
	Lock_State = Lock;
	
	while (1)
	{
		SM_Door_Lock();
		
	}
}

