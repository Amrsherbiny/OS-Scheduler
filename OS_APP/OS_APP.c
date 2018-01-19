/*
 * OS_APP.c
 *
 * Created: 1/6/2018 2:38:02 PM
 *  Author: Amr
 */ 


#include "STDMACROS.h"
#include "scheduler.h"
#include "timer0.h"

int main(void)
{
	timer0_normal_init();
	DDRD = 1<<7 | 1<<6 | 1<<5;
	sei();
    while(1)
    {
		start_os();
        
    }
}