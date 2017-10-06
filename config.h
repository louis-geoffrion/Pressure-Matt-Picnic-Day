
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
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

void interrupthandler() ;


void config() {
	    // Set the clocking to run directly from the external crystal/oscillator.
	    //
	    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
								SYSCTL_XTAL_16MHZ);

	    /////////////////////////////////////////////////////////////////////////////
	    //   Enable Peripherals
	    //   F, E, B , A , SSI, i2C
	    /////////////////////////////////////////////////////////////////////////////
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);

		GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_4);
	    GPIOPinTypeGPIOInput(GPIO_PORTE_BASE,GPIO_PIN_1);

	    //CONFIG BUTTON
	    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	    GPIOPadConfigSet(GPIO_PORTE_BASE,GPIO_PIN_1,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

	    //interrupt pin B1
	    GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_FALLING_EDGE );
	    GPIOIntRegister(GPIO_PORTB_BASE,interrupthandler);
	    GPIOIntEnable(GPIO_PORTB_BASE, GPIO_PIN_1);

	    //interrupt pin E1  currely not using it.
	    GPIOIntTypeSet(GPIO_PORTE_BASE,GPIO_PIN_1,GPIO_RISING_EDGE );

	    GPIOIntEnable(GPIO_PORTE_BASE, GPIO_PIN_1);

	    //interrupt pin F4   currely not using it.
	    GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_RISING_EDGE );

	    GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4);





	    // Configure the pin muxing for SSI0 functions on port A2, A3, A4, and A5.
	    //
	    GPIOPinConfigure(GPIO_PA2_SSI0CLK);
	    GPIOPinConfigure(GPIO_PA3_SSI0FSS);
	    GPIOPinConfigure(GPIO_PA4_SSI0RX);
	    GPIOPinConfigure(GPIO_PA5_SSI0TX);

	    //
	    // Configure the GPIO settings for the SSI pins.  This function also gives
	    // control of these pins to the SSI hardware.  Consult the data sheet to
	    // see which functions are allocated per pin.
	    // The pins are assigned as follows:
	    //      PA5 - SSI0Tx
	    //      PA4 - SSI0Rx
	    //      PA3 - SSI0Fss
	    //      PA2 - SSI0CLK
	    //
	    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5 | GPIO_PIN_4 | GPIO_PIN_3 |
	                   GPIO_PIN_2);

	    //
	    // Configure and enable the SSI port for SPI master mode.  Use SSI0,
	    // system clock supply, idle clock level low and active low clock in
	    // freescale SPI mode, master mode, 1MHz SSI frequency, and 8-bit data.
	    // For SPI mode, you can set the polarity of the SSI clock when the SSI
	    // unit is idle.  You can also configure what clock edge you want to
	    // capture data on.  Please reference the datasheet for more information on
	    // the different SPI modes.
	    //
	    SSIConfigSetExpClk(SSI0_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0,
	                       SSI_MODE_MASTER, 1000000, 8);

	    //
	    // Enable the SSI0 module.
	    //
	    SSIEnable(SSI0_BASE);


	    //config I2C

	    GPIOPinConfigure(GPIO_PB2_I2C0SCL);
	    GPIOPinConfigure(GPIO_PB3_I2C0SDA);
	    //I2C interrupt
	    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_1);
	    GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	    // config data and clk pin
	    GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
	    GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);
	    //enable master
	    I2CMasterEnable(I2C0_BASE);
	    I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), false);
}
