/*
 * timer0.c
 *
 * Created: 12/9/2017 1:08:09 PM
 *  Author: Amr
 */ 
#include "timer0.h"

extern count,count1,count2,count3;

void timer0_normal_init()
{
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1 << CS02); // prescalar 1024 
	SETBIT(TIMSK,TOIE0);
	SREG = 1 << 7; // turn on global interrupt
}
void timer0_ctc_init()
{
	TCCR0 |= 	(1<<FOC0) | (1<<WGM01) | (1<<CS00) | (1 << CS02);
	SETBIT(TIMSK,OCIE0); 
	SREG = 1 << 7;
	OCR0 = 0b11000111;
} 

ISR(TIMER0_OVF_vect)
{
	count++;
	count1++;
	count2++;
	count3++;
}
