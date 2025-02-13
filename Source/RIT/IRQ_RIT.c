
#include "LPC17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "../GLCD/GLCD.h"
#include "../timer/timer.h"
#include "../music/music.h"

#include <stdio.h>

#define UPTICKS 1

volatile int down_0 = 0;
volatile int down_1 = 0;
volatile int down_2 = 0;
 
static int isplaying=1;


extern NOTE song[];
NOTE *actual=song;
void PlayMusic()
{
	if(isplaying){
		static int currentNote;
		static int ticks = 0;
		if(!isNotePlaying())
		{
			++ticks;
			if(ticks == UPTICKS)
			{
				ticks = 0;
				playNote(actual[currentNote++]);
			}
		}

		if(actual[currentNote].freq==end)
		{
			isplaying=0;
		}

	}
}

void RIT_IRQHandler (void)
{			

	PlayMusic();
	
	
/*************************INT0***************************/
if(down_0 !=0){
	down_0++;
	if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){
		switch(down_0){
			case 2:
				
				break;
			default:
				break;
		}
	}
	else {	/* button released */
		down_0=0;			
		NVIC_EnableIRQ(EINT0_IRQn);							 /* disable Button interrupts			*/
		LPC_PINCON->PINSEL4    |= (1 << 20);     /* External interrupt 0 pin selection */
	}
} // end INT0

/*************************KEY1***************************/
if(down_1 !=0){
	down_1++;
	if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){
		switch(down_1){
			case 2:
				
				break;
			default:
				break;
		}
	}
	else {	/* button released */
		down_1=0;			
		NVIC_EnableIRQ(EINT1_IRQn);							 /* disable Button interrupts			*/
		LPC_PINCON->PINSEL4    |= (1 << 22);     /* External interrupt 0 pin selection */
	}
} // end KEY1

/*************************KEY2***************************/
if(down_2 !=0){
	down_2++;
	if((LPC_GPIO2->FIOPIN & (1<<12)) == 0){
		switch(down_2){
			case 2:
			
				break;
			default:
				break;
		}
	}
	else {	/* button released */
		down_2=0;		
		NVIC_EnableIRQ(EINT2_IRQn);							 /* disable Button interrupts			*/
		LPC_PINCON->PINSEL4    |= (1 << 24);     /* External interrupt 0 pin selection */
	}
} // end KEY2
	//*************************JOYSTICK
	static int up=0;
	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){				//SOTTO
		up++;
		switch(up){
			case 1:
			
			
				break;
			case 60:	//3sec = 3000ms/50ms = 60

				break;
			default:
				break;
		}
	}
	else{
			up=0;
	}
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){				//SINISTRA
		up++;
		switch(up){
			case 1:
				
			
				break;
			case 60:	//3sec = 3000ms/50ms = 60

				break;
			default:
				break;
		}
	}
	else{
			up=0;
	}
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){				//DESTRA
		up++;
		switch(up){
			case 1:
				
			
				break;
			case 60:	//3sec = 3000ms/50ms = 60

				break;
			default:
				break;
		}
	}
	else{
			up=0;
	}
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){			//SOPRA
		up++;
		switch(up){
			case 1:
				
			
				break;
			case 60:	//3sec = 3000ms/50ms = 60

				break;
			default:
				break;
		}
	}
	else{
			up=0;
	}


	//****************	ATTENZIONE: QUI NON SO SE VA RESETTATO O NO
	//reset_rit()
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
