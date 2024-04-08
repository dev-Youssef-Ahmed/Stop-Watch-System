/*
 * my_configs.h
 *
 *  Created on: Mar 14, 2024
 *      Author: Youssef
 */

#ifndef INC_MY_CONFIGS_H_
#define INC_MY_CONFIGS_H_

/* Initial values of seconds, minutes, and hours to be displayed. Normal: 0,0,0 respectively */
#define SEC_MIN					0
#define MIN_MIN					0
#define HRS_MIN					0

/* Final values of seconds, minutes, and hours to be displayed. Normal: 59,59,23 respectively.
 * Note: When any displayed time unit reaches its final value, it overflows to its initial value */
#define SEC_MAX					59
#define MIN_MAX					59
#define HRS_MAX					23

#endif /* INC_MY_CONFIGS_H_ */
