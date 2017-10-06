#include <stdlib.h>
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

static uint8_t getdata=0;
static uint8_t SLAVE_ADDRESS=0x20;

static int sw1count=0;  //ini condition for button1count
static int sw2count=14; //ini condition for button2count
static int lednum=30;	//total number of leds
static int numofbutton1=0;  //num of times button 1 is pressed
static int numofbutton2=0;  //num of times button 2 is pressed
static int button1count[15]={0}; //red led
static int button2count[15]={0}; //blue led
static int flag=0;			//button pushed

void interrupthandler(){
	GPIOIntClear(GPIO_PORTB_BASE,GPIO_PIN_1);


	I2CMasterSlaveAddrSet(I2C0_BASE, SLAVE_ADDRESS, true); //set slave address, set read mode
	I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);  //read from io expander
	while(I2CMasterBusy(I2C0_BASE)); //let it read
	getdata = I2CMasterDataGet(I2C0_BASE);  // get the data. getdata is a decimal number. 239 is 11101111. it is inverted so P5 is on.
   // UARTprintf("Received: '%i'\n", getdata);


    //223 is P4 239 is P5. If P4 is on set the array to 1 one by one. same as P5. P4 goes from front to back. P5 goes from back to front.
    if(getdata==223)
	{
	button1count[sw1count]=1;
	sw1count=sw1count+1;
	numofbutton1=numofbutton1+1;
	}
	else if(getdata==239)
	{
	button2count[sw2count]=1;
	sw2count=sw2count-1;
	numofbutton2+=1;
	} else if(getdata==)	// // p6   11011111
	flag=1; // get flag for button pushed.
	//UARTprintf("'%i'",numofbutton1); ///// comment out if no UART
	//UARTprintf("'%i'",numofbutton2); ///// comment out if no UART
	SysCtlDelay(5000);


}
