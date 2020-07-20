#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "aritherr.h"
#include "function.h"

 //The path of BGI directory. Escape sequences are used.
#define pathOfBGI "c:\\TurboC3\\BGI"

int gdriver = DETECT, gmode, errorcode;
int xmax, ymax,x=0,y=0;

int ginitialize(void) //called at start of program execution to allocate memory and start graphics platform
{
	initgraph(&gdriver, &gmode, pathOfBGI );
	errorcode = graphresult();
	
   if (errorcode != grOk) /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);

   }
	xmax = getmaxx();
	ymax = getmaxy();
	y=ymax/2;
	x=xmax/2;

   return 0;
}

inline void gclose(void)	//called at end of program execution to deallocate memory and close graphics platform
{
	getch();
	closegraph();
}

inline void createaxis()
{
	setcolor(getmaxcolor()); // getmaxcolor() returns 15. 15 -> white
	line(0, y, xmax, y);
	line(x, 0, x, ymax);
}
int plot()
{       int ct=0;
	int *xy= new int[2*xmax];
	int *pts= new int[2*xmax];
	int npts=0;
	double h=0,k=0;
	int i=0;
	setcolor(4); // 4 -> red
	for(i=-x+1;i<x;i++)
	{
		h=i/c;
		k=f(h);
	       
		{
		pts[npts]=x+int(c*h);
		pts[npts+1]=y-int(c*k);
		npts=npts+2;
		}
	}
      
      pts[++npts]=-1;
      for(i=0;i<npts;i=i+2)
	{
		if(pts[i]>=0&&pts[i]<xmax&&pts[i+1]>=0&&pts[i+1]<=ymax)
		{
			xy[ct]=pts[i];
			xy[ct+1]=pts[i+1];
			ct=ct+2;
			continue;
		}
		else
		{
			drawpoly(ct/2,xy);
			ct=0;
			continue;
		}

	 }



	return 0;
}

int main(void)
{
	clrscr();
	ginitialize();
	createaxis();
	plot();
	gclose();
	return 0;
}
