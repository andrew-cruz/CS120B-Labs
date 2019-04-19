/* Partner 1 Name & E-mail: Andrew Cruz acruz029@ucr.edu
* Partner 2 Name & E-mail: Jonathan Kaneshiro jkane002@ucr.edu
* Lab Section: 24
* Assignment: Lab #4 Exercise #1
* Exercise Description: [optional - include for your own benefit]
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/ 

#include <avr/io.h>

enum LED_States { FM_LED1ON , FM_LED2ON} LED_State;

//State Machine
void LightSwitch() {
	//Access PA0
	unsigned char PA_0 = PINA & 0x01;
	

	switch(LED_State) {
		case FM_LED1ON : { //Start State
			if(PA_0) { //Button Press
				LED_State = FM_LED2ON;
			} else {
				LED_State = FM_LED1ON;
			}
			break;
		}
		case FM_LED2ON: { //State with LED2 turned on
			if(PA_0) { //Button Press
				LED_State = FM_LED1ON;
			} else {
				LED_State = FM_LED2ON;
			}
			break;
		}
		default: {
			LED_State = FM_LED1ON;
			break;
		}
	}//Transitions
	
	unsigned char tempB = 0x00;
	
	switch(LED_State) {
		case FM_LED1ON : { //Set PB0 to 1 PB1 to 0
			tempB = 0x01;		
			break;
		}
		case FM_LED2ON: { //Set PB0 to 0 PB1 to 1
			tempB = 0x02;
			break;
		}
		default: {
			tempB = 0x00;
			break;
		}
	} //State Actions
	
	//Assign To PORTB
	PORTB = tempB;
	
	
	
}

int main(void)
{
	//Init State state
    LED_State = FM_LED1ON;
	
    while (1) 
    {
		LightSwitch();
		
    }
}

