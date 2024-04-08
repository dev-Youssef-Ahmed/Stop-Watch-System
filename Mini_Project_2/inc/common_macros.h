/*
 * all_macros.h
 *
 *  Created on: Mar 14, 2024
 *      Author: Youssef
 */

#ifndef INC_COMMON_MACROS_H_
#define INC_COMMON_MACROS_H_

/* Bits manipulation */
#define SET_BIT(REG,BIT_NUM)	(	REG |=  (1 << BIT_NUM)	)
#define CLR_BIT(REG,BIT_NUM)	(	REG &= ~(1 << BIT_NUM)	)
#define TOG_BIT(REG,BIT_NUM)	(	REG ^=  (1 << BIT_NUM)	)
#define IS1_BIT(REG,BIT_NUM)	(	REG &   (1 << BIT_NUM)	)
#define IS0_BIT(REG,BIT_NUM)	( !(REG &   (1 << BIT_NUM))	)

/* Miscellaneous! */
#define TEN						10		/* Used as denominator of / and % operators to separate digits of a any number */
#define I						7		/* The global interrupt enable bit number (I-bit) */
#define FALSE					0		/* Used for flags*/
#define TRUE					1		/* Used for flags*/
#define ZERO					0		/* ZERO!*/

#endif /* INC_COMMON_MACROS_H_ */
