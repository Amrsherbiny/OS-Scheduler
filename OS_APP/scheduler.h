/*
 * scheduler.h
 *
 * Created: 1/6/2018 2:40:52 PM
 *  Author: Amr
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "STDMACROS.h"

extern void start_os(void);
extern void check_button(void);
extern void LED_on(void);
extern void LED_off(void);

typedef struct{
	void (*pf)(void);
	uint8_t periodicity;
	}OS_tasks;

#endif /* SCHEDULER_H_ */