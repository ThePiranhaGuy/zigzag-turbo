#include <math.h>
#include <string.h>
#include <stdio.h>
#define infinity 10.0e7
int matherr (struct exception *a)
{
  if (a->type == DOMAIN)
  {  if (!strcmp(a->name,"sqrt")) {
      a->retval = infinity ;
    return 1;
    }
    if(!strcmp(a->name,"log")) {
     a->retval = infinity;
    return 1;
    }
    else
    { a->retval=0 ;
      return 1;
    }

  }
    if (a->type == SING)
    {
	a->retval= 0;
	return 1;
    }

  return 0;
}

