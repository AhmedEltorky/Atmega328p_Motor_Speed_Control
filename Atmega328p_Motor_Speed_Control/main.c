/*
 * Atmega328p_Motor_Speed_Control.c
 *
 * Created: 3/20/19 5:05:07 PM
 * Author : Ahmed El-Torky
 */ 

#define F_CPU 1000000ul

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB = 0x00;		  // set port B as input port
	DDRC |= (1 << PINC0); // set pin 0 in port C as input

	// Timer0 initialization as fast PWM mode
	TCCR0A |= (1 << WGM00) | (1 << WGM01); // set Timer0 to fast PWM mode
	DDRD |= (1 << PIND6);				   // set the OC0A pin in port D to output
	TCCR0A |= (1 << COM0A1);			   // set OC0A to non-inverting mode
	TIMSK0 |= (1 << TOIE0);				   // set Timer0 overflow interrupt
	OCR0A = 0;							   // represent the duty cycle
	TCCR0B |= (1 << CS01);				   // set prescaler to 8

	// Timer2 initialization as phase Correct PWM
	TCCR2A |= (1 << WGM20) | (1 << WGM22); // set Timer2 to phase correct PWM mode
	DDRB |= (1 << PINB3);				   // set the OC2A pin in port B to output
	TCCR2A |= (1 << COM2A1);			   // set OC2A to non-inverting mode
	TIMSK2 |= (1 << TOIE2);				   // set Timer2 overflow interrupt
	OCR2A = 0;							   // represent the duty cycle
	TCCR2B |= (1 << CS21);				   // set prescaler to 8

	sei(); // set global interrupt

	while (1)
	{
	}
}

ISR(TIMER0_OVF_vect)
{
	OCR0A = (PINB & 0xF7) | ((PINC & 0x01) << 3);
}

ISR(TIMER2_OVF_vect)
{
	OCR2A = (PINB & 0xF7) | ((PINC & 0x01) << 3);
}
