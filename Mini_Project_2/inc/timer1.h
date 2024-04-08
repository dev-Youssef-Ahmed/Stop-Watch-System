/*
 * timer1.h
 *
 *  Created on: Mar 14, 2024
 *      Author: Youssef
 */

#ifndef INC_TIMER1_H_
#define INC_TIMER1_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <common_macros.h>

/* Macros group #4: OCR1A register value calculator */
#define F_CLK					0xF4240 /* Internal 1Mhz frequency */
#define F_GEN					0x1		/* 1 Hz, then Time = 1 / F_GEN = 1 second */
#define	PRE_SC					8		/* The suitable pre-scaler value to achieve the desired F_GEN*/
#define TOP						( ( (F_CLK) / (2 * PRE_SC * F_GEN) ) - 1 ) /* = 0xF423 = 62,499 */
#define BOTTOM					0x0000	/* Used as initial value of TCNT1 register*/

void Timer1_CTC_Init(void);

#endif /* INC_TIMER1_H_ */
