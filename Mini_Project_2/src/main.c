/*
 * Mini-Project 2	:	Stop Watch System
 * Facebook Name	:	Youssef Ahmed
 * Diploma Number	:	85
 */

/*
 * Note 1:	MISRA rules were applied to some extent in this project!
 * Note 2:	The project consists of four .c files and six .h files
 * Note 3:	Don't forget to assign "inc" folder as the include path to use <main.h> (see I-VII steps)
 */

/*
 * I.	Project Properties
 * II.	C/C++ Build
 * III.	Settings
 * IV.	Tool Settings
 * V.	AVR Compiler
 * VI.	Directories
 * VII.	Include Paths (-|): should be "${workspace_loc:/${ProjName}/inc}"
 */
#include <main.h>

int main (void)
{
	/* Initiations */
	Timer1_CTC_Init();
	INT0_Init();
	INT1_Init();
	INT2_Init();
	Seven_Segment_Init();

	/* Enable Status Register - SREG */
	/* Global Interrupt Enable - I */
	SET_BIT(SREG,I);
	while(TRUE)
	{
		/* The displaying will always be ON, even ISRs are activated or not! */
		Display_Digit();

		/* Check Timer1 ticks! If ticked, increase the timer once then re-FLASE the flag! */
		if(timer1_flag == TRUE)
		{
			Time_Increment();
			timer1_flag = FALSE;
		}
	}

}
