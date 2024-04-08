/*
 * interrupts.h
 *
 *  Created on: Mar 14, 2024
 *      Author: Youssef
 */

#ifndef INC_INTERRUPTS_H_
#define INC_INTERRUPTS_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <common_macros.h>
#include <my_configs.h>
#include <seven_segment.h>

void INT0_Init(void);
void INT1_Init(void);
void INT2_Init(void);

#endif /* INC_INTERRUPTS_H_ */
