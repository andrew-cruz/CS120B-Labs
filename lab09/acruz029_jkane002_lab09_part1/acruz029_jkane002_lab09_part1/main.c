/*
 * acruz029_jkane002_lab09_part1.c
 *
 * Created: 5/2/2019 10:13:52 AM
 * Author : Andrew Cruz
 */ 

#include <avr/io.h>

// 0.954 hz is lowest frequency possible with this function,
// based on settings in PWM_on()
// Passing in 0 as the frequency will stop the speaker from generating sound
void set_PWM(double frequency) {
	static double current_frequency; // Keeps track of the currently set frequency
	// Will only update the registers when the frequency changes, otherwise allows
	// music to play uninterrupted.
	if (frequency != current_frequency) {
		if (!frequency) { TCCR0B &= 0x08; } //stops timer/counter
		else { TCCR0B |= 0x03; } // resumes/continues timer/counter
		
		// prevents OCR3A from overflowing, using prescaler 64
		// 0.954 is smallest frequency that will not result in overflow
		if (frequency < 0.954) { OCR0A = 0xFFFF; }
		
		// prevents OCR0A from underflowing, using prescaler 64					// 31250 is largest frequency that will not result in underflow
		else if (frequency > 31250) { OCR0A = 0x0000; }
		
		// set OCR3A based on desired frequency
		else { OCR0A = (short)(8000000 / (128 * frequency)) - 1; }

		TCNT0 = 0; // resets counter
		current_frequency = frequency; // Updates the current frequency
	}
}

void PWM_on() {
	TCCR0A = (1 << COM0A0);
	// COM3A0: Toggle PB3 on compare match between counter and OCR0A
	TCCR0B = (1 << WGM02) | (1 << CS01) | (1 << CS00);
	// WGM02: When counter (TCNT0) matches OCR0A, reset counter
	// CS01 & CS30: Set a prescaler of 64
	set_PWM(0);
}

void PWM_off() {
	TCCR0A = 0x00;
}

enum Notes{C, D, E, Silent} Note;
	
void Tick() {
	unsigned char A0 = ~PINA & 0x01;
	unsigned char A1 = ~PINA & 0x02;
	unsigned char A2 = ~PINA & 0x04;
	double sound = 0;
	
	switch (Note) {
		case C: {
			if(A0 & !A1 & !A2) {
				Note = C;
			} else if(!A0 & A1 & !A2) {
				Note = D;
			} else if(!A0 & !A1 & A2) {
				Note = E;
			} else {
				Note = Silent;
			}
			sound = 261.63;
			break;
		}
		case D: {
			if(A0 & !A1 & !A2) {
				Note = C;
			} else if(!A0 & A1 & !A2) {
				Note = D;
			} else if(!A0 & !A1 & A2) {
				Note = E;
			} else {
				Note = Silent;
			}
			sound = 293.66;
			break;
		}
		case E: {
			if(A0 & !A1 & !A2) {
				Note = C;
			} else if(!A0 & A1 & !A2) {
				Note = D;
			} else if(!A0 & !A1 & A2) {
				Note = E;
			} else {
				Note = Silent;
			}
			sound = 329.63;
			break;
		} 
		case Silent: {
			if(A0 & !A1 & !A2) {
				Note = C;
			} else if(!A0 & A1 & !A2) {
				Note = D;
			} else if(!A0 & !A1 & !A2) {
				Note = E;	
			} else {
				Note = Silent;
			}
			sound = 0;
			break;
		}
		default: {
			sound = 392.00;
			break;
		}
	}
	
	set_PWM(sound);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00; 
	
	PWM_on();
	Note = Silent;
    /* Replace with your application code */
    while (1) 
    {
		Tick();
    }
}

