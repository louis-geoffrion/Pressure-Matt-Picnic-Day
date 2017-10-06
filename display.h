//////////////////////////////////////////
// Display.h EE-Emerge S16				////
// LED Display Driver 					////
//////////////////////////////////////////
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"  // For SSI0_BASE
#include "driverlib/ssi.h"
//////////////////////
//
//////////////////////

//////////////////////
// Pixel: individual /
// color , brightness
// must add 224 to br
//////////////////////
struct pixel
{
  unsigned int r,g,b,br :8 ;
};

//////////////////////
// Point: individual /
// x , y						//
//////////////////////

struct point
{
	int x, y;
};

//////////////////////
// Screen: 6x30 P		 /
// Pixel: Color,     /
//        Brightness /
//////////////////////

struct screen
{
  struct pixel pix[6][30];
};

struct param
{
	unsigned int strt_frame :8 ;
	unsigned int end_frame :8 ;
};



////////////////////////////////////////////
/// Display Functions					//
// 										//
////////////////////////////////////////////

void assign (struct screen *a, struct pixel *b, struct point x)
{
	a->pix[x.y][x.x].r = b->r ;
	a->pix[x.y][x.x].g = b->g ;
	a->pix[x.y][x.x].b = b->b ;
	a->pix[x.y][x.x].br = b->br;
}
//////////////////////
// Rectangle				 /
// screen << rect 	 /
// 					strt ,end/
//////////////////////


void rectangle(struct  pixel *in, struct  point * strt, struct  point*end,struct  screen* temp_screen)
{
	// Int declarations used to be here
	// also used to have brackets for both loops
	for (int *tempy=strt.y;; *tempy <=end.y; *tempy++)
		for (int tempx=strt.x; tempx<=end.x; tempx++)
			assign(temp_screen,in,strt);


}

void write_pixel ( struct pixel in)
{
	SSIDataPut(SSI0_BASE,in.br);
	SSIDataPut(SSI0_BASE,in.b);
	SSIDataPut(SSI0_BASE,in.g);
	SSIDataPut(SSI0_BASE,in.r);
}
void write(struct screen * output )
{
  struct param init_par ;
  init_par.end_frame = 255;
  init_par.strt_frame = 0;
  SSIDataPut(SSI0_BASE, init_par.end_frame);
  SSIDataPut(SSI0_BASE, init_par.end_frame);
  SSIDataPut(SSI0_BASE, init_par.end_frame);
  SSIDataPut(SSI0_BASE, init_par.end_frame);
  SSIDataPut(SSI0_BASE, init_par.strt_frame);
  SSIDataPut(SSI0_BASE, init_par.strt_frame);
  SSIDataPut(SSI0_BASE, init_par.strt_frame);
  SSIDataPut(SSI0_BASE, init_par.strt_frame);
  int y=0, x=0;
  for (; y<6;y++)
  {
	  for (; x<30; x++)
	  {
		  SSIDataPut(SSI0_BASE, output->pix[y][x].br);
		  SSIDataPut(SSI0_BASE, output->pix[y][x].b);
		  SSIDataPut(SSI0_BASE, output->pix[y][x].g);
		  SSIDataPut(SSI0_BASE, output->pix[y][x].r);
	  }

  }
}
