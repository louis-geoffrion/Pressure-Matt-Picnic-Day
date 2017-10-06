
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

////////////////////////////////////////////
// External variables
// pix_off, pix_red, cond
////////////////////////////////////////////
extern struct pixel pix_off = {0,0,0,224};
//pix_red = {1111,0,0,255};
//static struct screen temporary;
extern struct param cond = {0,255};
extern struct point left_corner = {0,0} ;
//right_corner= { 29, 5};
////////////////////////////////////////////
//  Led will run from start to finish
// uses pix_off, pix_red
///////////////////////////////////////////

void led_run()
{
		struct point start ={0,0}, end= {30,6};
		allzero();
		int count = 0;
		for (;count <200; count++)
		{
			write_pixel(pix_off);
		}
		int leading = 1, lagging = 0;
		while (1)
		{
			int counter = 0;
			for (;counter < leading ; counter ++)
			{
				write_pixel(pix_off);
			}
			write_pixel(pix_red);
			for (;count < 200; count++)
			{
				write_pixel(pix_off);
			}
			SysCtlDelay (200000);
			for (counter =0; counter <200; counter++)
			{
				write_pixel(pix_off);
			}
			allone();
			SysCtlDelay (20000);
			allzero();
			leading += 1;
			if (leading == 200)
				leading =0;
		}
		}
}



void rectangle_test(struct point start, struct point end)
{
			struct screen * tscreen_ptr= &temporary;
			struct pixel* off_pix_ptr= &pix_off, *red_pix_ptr=&pix_red;

			rectangle(off_pix_ptr,left_corner,right_corner,tscreen_ptr);
			write ( tscreen_ptr);
			rectangle(red_pix_ptr,start,end,tscreen_ptr);
			write ( tscreen_ptr);

}

