#include <timer1.h>

uint8_t	timer1_flag = FALSE;

void Timer1_CTC_Init(void)
{
	/* Timer/Counter 1 - TCNT1 */
	/* Set the initial value */
	TCNT1 = BOTTOM;

	/* Timer/Counter1 Control Register A – TCCR1A */
	/* Force Output Compare for Compare unit A - FOC1A */
	SET_BIT(TCCR1A,FOC1A);
	/* Waveform Generation Mode - WGM1: CTC */
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1A,WGM12);
	CLR_BIT(TCCR1A,WGM13);

	/* Output Compare Register 1 A – OCR1A */
	/* Set the TOP value */
	OCR1A = TOP;

	/* Timer/Counter Interrupt Mask Register – TIMSK */
	/* Timer/Counter1, Output Compare A Match Interrupt Enable - OCIE1A */
	SET_BIT(TIMSK,OCIE1A);

	/* Timer/Counter Interrupt Flag Register – TIFR */
	/* Timer/Counter1, Output Compare A Match Flag - OCF1A */
	SET_BIT(TIFR,OCF1A);

	/* Timer/Counter1 Control Register B – TCCR1B */
	/* Clock Select - CS1: N = 8 */
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}

ISR(TIMER1_COMPA_vect)
{
	/* This interrupt will raise a flag as an indicator for a single tick completion */
	timer1_flag = TRUE;
}
