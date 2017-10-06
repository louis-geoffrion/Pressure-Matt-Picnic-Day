

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"  // For SSI0_BASE
#include "driverlib/ssi.h" // for SSIDataPut


void fullblue()
{


	SSIDataPut(SSI0_BASE, 0xff); //11111111  255
	SSIDataPut(SSI0_BASE, 0xff);
	SSIDataPut(SSI0_BASE, 0x00);	//00000000
	SSIDataPut(SSI0_BASE, 0x00);

}

void fullgreen()
{
	SSIDataPut(SSI0_BASE, 0xff);
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0xff);
	SSIDataPut(SSI0_BASE, 0x00);

}
void fullred()
{
	SSIDataPut(SSI0_BASE, 0xff);
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0xff);

}
void dimred()
{
	SSIDataPut(SSI0_BASE, 0xe8); //11101000   11111111
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0xff);

}
void allzero()
{
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0x00);
}


void off()
{

	SSIDataPut(SSI0_BASE, 0xff);
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0x00);
	SSIDataPut(SSI0_BASE, 0x00);

}
void allone()
{
	SSIDataPut(SSI0_BASE, 0xff);
	SSIDataPut(SSI0_BASE, 0xff);
	SSIDataPut(SSI0_BASE, 0xff);
	SSIDataPut(SSI0_BASE, 0xff);
}
