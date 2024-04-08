#include <seven_segment.h>

/* Global variables */
uint8_t	digit			= 		ZERO;

uint8_t	current_time[]	= 		{SEC_MIN , SEC_MIN , MIN_MIN , MIN_MIN , HRS_MIN , HRS_MIN};

void Seven_Segment_Init(void)
{
	/* Port C Data Direction Register – DDRC */
	/* Use the 7447 decoder as output - PC */
	SET_BIT(DDRC,PC0);
	SET_BIT(DDRC,PC1);
	SET_BIT(DDRC,PC2);
	SET_BIT(DDRC,PC3);

	/* Port C Data Register – PORTC */
	/* Set value as ZERO for ON (since it is common anode) - PC */
	CLR_BIT(PORTC,PC0);
	CLR_BIT(PORTC,PC1);
	CLR_BIT(PORTC,PC2);
	CLR_BIT(PORTC,PC3);
}

void Time_Increment(void)
{
	/* Start by increment the seconds */
	second ++;

	/* Check if 59 seconds occurs to reset the seconds and increment the minutes */
	if(second > SEC_MAX)
	{
		second	= ZERO;
		minute	++;
	}

	/* Check if 59 minutes occurs to reset the minutes and increment the hours */
	if(minute > MIN_MAX)
	{
		minute	= ZERO;
		hour 	++;
	}

	/* Check if 23 hours occurs to reset all of second, minute, and the hour digits */
	if(hour > HRS_MAX)
	{
		second	= ZERO;
		minute	= ZERO;
		hour	= ZERO;
	}
}

void Time_Digits_Splitter(void)
{
	/* This function will separate the pre-incremented time digits using the
	 * decimal separator "10" with divide and modulus operators. And it will
	 * assign these digits to its corresponding index in curren_time array */

	current_time[SEC0] = second%TEN;
	current_time[SEC1] = second/TEN;

	current_time[MIN0] = minute%TEN;
	current_time[MIN1] = minute/TEN;

	current_time[HRS0] = hour%TEN;
	current_time[HRS1] = hour/TEN;
}

void Display_Digit(void)
{
	/* This function will split time digits using Time_Digits_Splitter function,
	 * then display each digit on its corresponding seven-segment */
	Time_Digits_Splitter();

	for(digit = SEC0 ; digit <= HRS1 ; digit++)
	{
		switch(digit)
		{
			case SEC0:
			{
				/* Disable all 7-segments but the SEC0 7-segment (PA5) */
				PORTA_ENABLE_PIN(PA5);
				PORTC = DISPLAY(current_time[digit]);
				break;
			}

			case SEC1:
			{
				/* Disable all 7-segments but the SEC0 7-segment (PA4) */
				PORTA_ENABLE_PIN(PA4);
				PORTC = DISPLAY(current_time[digit]);
				break;
			}

			case MIN0:
			{
				/* Disable all 7-segments but the SEC0 7-segment (PA3) */
				PORTA_ENABLE_PIN(PA3);
				PORTC = DISPLAY(current_time[digit]);
				break;
			}

			case MIN1:
			{
				/* Disable all 7-segments but the SEC0 7-segment (PA2) */
				PORTA_ENABLE_PIN(PA2);
				PORTC = DISPLAY(current_time[digit]);
				break;
			}

			case HRS0:
			{
				/* Disable all 7-segments but the SEC0 7-segment (PA1) */
				PORTA_ENABLE_PIN(PA1);
				PORTC = DISPLAY(current_time[digit]);
				break;
			}

			case HRS1:
			{
				/* Disable all 7-segments but the SEC0 7-segment (PA0) */
				PORTA_ENABLE_PIN(PA0);
				PORTC = DISPLAY(current_time[digit]);
				//DELAY_2MS();
				break;
			}
		}
	}
}
