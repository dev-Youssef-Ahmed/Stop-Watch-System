/*
 * seven_segment.h
 *
 *  Created on: Mar 14, 2024
 *      Author: Youssef
 */

#ifndef INC_SEVEN_SEGMENT_H_
#define INC_SEVEN_SEGMENT_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <common_macros.h>
#include <my_configs.h>

/* Positions of seconds, minutes, and hours in the current_time array, two digits for each */
#define SEC0					0
#define SEC1					1
#define MIN0					2
#define MIN1					3
#define HRS0					4
#define HRS1					5

/* Display a 4-bits digit on PC0:3 pins only */
#define LOWER_BITS				0x0F
#define UPPER_BITS				0xF0
#define DISPLAY(value)			( (PORTC & UPPER_BITS) | (value & LOWER_BITS) )

/*Enable a single pin in PORTA to be used for once */
#define SEVEN_SEG_BITS			0xC0
#define PORTA_ENABLE_PIN(pin)	do							\
								{							\
                                    PORTA &= SEVEN_SEG_BITS;\
                                    SET_BIT(PORTA,pin);		\
                                } while(FALSE)

extern uint8_t	second;
extern uint8_t	minute;
extern uint8_t	hour;

extern uint8_t	second_digit0;
extern uint8_t	second_digit1;
extern uint8_t	minute_digit0;
extern uint8_t	minute_digit1;
extern uint8_t	hour_digit0;
extern uint8_t	hour_digit1;

void Seven_Segment_Init(void);
void Time_Increment(void);
void Time_Digits_Splitter(void);
void Display_Digit(void);


#endif /* INC_SEVEN_SEGMENT_H_ */
