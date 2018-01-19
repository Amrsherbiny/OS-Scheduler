/*
 * scheduler.c
 *
 * Created: 1/6/2018 2:40:41 PM
 *  Author: Amr
 */ 
#include "scheduler.h"
#include "timer0.h"

uint8_t i;
uint8_t flag1,flag2,flag3;
volatile uint32_t count = 0;
volatile uint32_t count1 = 0,count2 = 0,count3 = 0;

void LED_off(void)
{
	if(count1 >= 20)
	{
		CLRBIT(PORTD,PD7);	
	}
	if(count2 >= 20)
	{
		CLRBIT(PORTD,PD6);
	}
	if(count3 >= 20)
	{
		CLRBIT(PORTD,PD5);
	}
}
void LED_on(void)
{
	//SETBIT(PORTD,PD7);
	if(flag1 == 1)
	{
	   SETBIT(PORTD,PD7);
	   flag1 = 0;	
	   count1 = 0;
	}
	if(flag2 == 1)
	{
		SETBIT(PORTD,PD6);
		flag2 = 0;
		count2 = 0;
	}
	if(flag3 == 1)
	{
		SETBIT(PORTD,PD5);
		flag3 = 0;
		count3 = 0;
	}
}
void check_button(void)
{
	//SETBIT(PORTD,PD6);
	if(READBIT(PIND,PD0))
	{
		flag1 = 1;
	}
	if(READBIT(PIND,PD1))
	{
		flag2 = 1;
	}
	if(READBIT(PIND,PD2))
	{
		flag3 = 1;
	}
}

OS_tasks tasks[] = {check_button,2,LED_on,11,LED_off,12};
void start_os(void)
{
	//SETBIT(PORTD,PD7);
	for( i=0; i<3; i++ )
	{
		if( (count % tasks[i].periodicity)  == 0)
		{
            tasks[i].pf();
		}
	}
}
