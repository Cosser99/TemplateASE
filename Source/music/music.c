#include "music.h"

#include "../timer/timer.h"

#define UPTICKS 1
NOTE song[] = 
{
	//1
	 {C3,time_semicroma},
	 {D3,time_semicroma},
	 {E3,time_semicroma}, 
	 {F4,time_semicroma},
	 {C4,time_semicroma},
	 {E4,time_semicroma},
	 {F3,time_semicroma},
	 {D3,time_semicroma},
	 {D4,time_semicroma},
	 {D3,time_semicroma},
	 {E3,time_semicroma},
	 {end,time_semicroma}
};


void playNote(NOTE note)
{
	
	if(note.freq != pause)
	{
		reset_timer(3);
		//reset_timer(2);
		init_timer(3,0,0,3,note.freq);
		//init_timer(2,note.freq);
		enable_timer(3);
		//enable_timer(2);
	}
	reset_timer(2);
	init_timer(2,0,0,3,note.duration);
	enable_timer(2);
	
}

BOOL isNotePlaying(void)
{
	return ((LPC_TIM3->TCR != 0) || (LPC_TIM1->TCR != 0));
}
