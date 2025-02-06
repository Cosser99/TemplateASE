
/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "timer/timer.h"
#include "led/led.h"
#include "button.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "TouchPanel.h"
#include "Image/image.h"

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

//ASM FUNCTION
extern uint8_t prova();

extern pt imageInit[3100];

//

void DrawInit(uint8_t dx,uint8_t dy,uint16_t col)
{
	int i,j;
	for(i=0;i<3100;i++)
		{
			LCD_SetPoint(imageInit[i].x+dx,imageInit[i].y+dy,col);
		}

}

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
	//Turn ON DAC
	
	
	//TP_Init();
	//TouchPanel_Calibrate();
	//
	LCD_Clear(Cyan);
	DrawInit(50,60,Black);
	init_RIT(0x0000FFFF);
	enable_RIT();
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
	
	LPC_PINCON->PINSEL1 |= (1<<21);
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	LPC_GPIO0->FIODIR |= (1<<26);
	
  while (1)	
  {
		__ASM("wfi");
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
