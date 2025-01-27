
/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "timer/timer.h"
#include "led/led.h"
#include "button.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

//ASM FUNCTION
extern uint8_t prova();
extern uint8_t ciao();

//
int main(void)
{
	
	//Initialization
  SystemInit();  												/* System Initialization (i.e., PLL)  */
	LED_init();
	BUTTON_init();		//RICORDATI CHE SETTA LA PRIORITY
	joystick_init();
  LCD_Initialization();	//RICORDA DI TOGLIERE IN CASO DI USO DI LED
	LPC_SC -> PCONP |= (1 << 22);  // TURN ON TIMER 2
	LPC_SC -> PCONP |= (1 << 23);  // TURN ON TIMER 3	
	//init_timer(...
	//enable_timer(...
	//disable_timer(...
	//init_RIT(0x1234)
	//enable_RIT

	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
	
  while (1)	
  {
		__ASM("wfi");
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
