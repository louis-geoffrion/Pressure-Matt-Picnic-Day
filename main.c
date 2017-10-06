 #include "display.h"
#include "colors.h"
#include "config.h"
#include "InterruptHandler.h"

//#include "animations.h"
//#include "InitConsole.h"

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "driverlib/rom.h"
#include "inc/hw_i2c.h"
#include "driverlib/i2c.h"
#include "inc/hw_types.h"
#include "hotP.h"

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif



int main(void)
{
		///////////////////////////////////////////////////////////////////////////////////////////////////
		//void rectangle(struct  pixel *in, struct  point strt, struct  point end,struct  screen* temp)
		////////////////////////////////////////////////////////////////////////////////////////////////////

		config();
		hotP();


}
