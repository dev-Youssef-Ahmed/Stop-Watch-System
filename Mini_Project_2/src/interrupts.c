#include <interrupts.h>

/* Global variables */
uint8_t	second			= 		SEC_MIN;
uint8_t	minute			= 		MIN_MIN;
uint8_t	hour			= 		HRS_MIN;

uint8_t	second_digit0	= 		SEC_MIN;
uint8_t	second_digit1	= 		SEC_MIN;
uint8_t	minute_digit0	= 		MIN_MIN;
uint8_t	minute_digit1	= 		MIN_MIN;
uint8_t	hour_digit0		= 		HRS_MIN;
uint8_t	hour_digit1		= 		HRS_MIN;

/* Interrupt Service Routine (ISR) functions */

ISR(INT0_vect)
{
	/* This interrupt will reset the seven-segments */

	/* Display 0 on the seven-segments */
	PORTC			= DISPLAY(ZERO);

	/* Reset seconds variables */
	second			= SEC_MIN;
	second_digit0	= SEC_MIN;
	second_digit1	= SEC_MIN;

	/* Reset minutes variables */
	minute			= MIN_MIN;
	minute_digit0	= MIN_MIN;
	minute_digit1	= MIN_MIN;

	/* Reset hours variables */
	hour			= HRS_MIN;
	hour_digit0		= HRS_MIN;
	hour_digit1		= HRS_MIN;
}

ISR(INT1_vect)
{
	/* This interrupt will pause the seven-segments by disable the timer's clock */

	/* Timer/Counter1 Control Register B – TCCR1B */
	/* Clock Select - CS1: STOP the clock */
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}

ISR(INT2_vect)
{
	/* This interrupt will resume the seven-segments by enable the timer's clock */

	/* Timer/Counter1 Control Register B – TCCR1B */
	/* Clock Select - CS1: N = 8 */
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}

void INT0_Init(void)
{
	/* Port D Data Direction Register – DDRD */
	/* Use the RESET button as input - PD2 */
	CLR_BIT(DDRD,PD2);

	/* Port D Data Register – PORTD */
	/* Activate the internal pull-up resistor - PD2 */
	SET_BIT(PORTD,PD2);

	/*MCU Control Register – MCUCR*/
	/* Interrupt Sense Control - ISC0: Falling edge */
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);

	/* General Interrupt Control Register – GICR */
	/* External Interrupt Request 0 Enable - INT0 */
	SET_BIT(GICR,INT0);

	/* General Interrupt Flag Register – GIFR */
	/* External Interrupt Request 0 Enable - INTF0 */
	/* SET_BIT(GIFR,INTF0); */
}

void INT1_Init(void)
{
	/* Port D Data Direction Register – DDRD */
	/* Use the PAUSE button as input - PD3 */
	CLR_BIT(DDRD,PD3);

	/*MCU Control Register – MCUCR*/
	/* Interrupt Sense Control - ISC1: Rising edge */
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);

	/* General Interrupt Control Register – GICR */
	/* External Interrupt Request 0 Enable - INT0 */
	SET_BIT(GICR,INT1);

	/* General Interrupt Flag Register – GIFR */
	/* External Interrupt Request 0 Enable - INTF0 */
	/* SET_BIT(GIFR,INTF1); */
}

void INT2_Init(void)
{
	/* Port B Data Direction Register – DDRB */
	/* Set the RESUME button as input - PB2 */
	CLR_BIT(DDRB,PB2);

	/* Port B Data Register – PORTB */
	/* Activate the internal pull-up resistor - PB2 */
	SET_BIT(PORTB,PB2);

	/*MCU Control and Status Register – MCUCSR*/
	/* Interrupt Sense Control 2 - ISC2: CLR for Falling edge */
	SET_BIT(MCUCSR,ISC2);

	/* General Interrupt Control Register – GICR */
	/* External Interrupt Request 0 Enable - INT2 */
	SET_BIT(GICR,INT2);

	/* General Interrupt Flag Register – GIFR */
	/* External Interrupt Request 0 Enable - INTF2 */
	/* SET_BIT(GIFR,INTF2); */
}
