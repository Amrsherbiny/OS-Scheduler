/*
 * STD_MACROS.h
 *
 * Created: 12/9/2017 10:49:31 AM
 *  Author: Amr
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#include <avr/io.h>
#include <stdint.h>

#define F_CPU 12000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#define SETBIT(REG,bit) REG |= 1<<bit
#define CLRBIT(REG,bit) REG &= ~(1<<bit)
#define TOGBIT(REG,bit) (REG ^= 1<<bit)
#define READBIT(REG,bit) ((REG>>bit)&1)

#endif /* STD_MACROS_H_ */