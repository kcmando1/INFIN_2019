/* strtof example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtof */

int main ()
{
  char szOrbits[] = "686.97";
  float  f2;
 
  f2 = strtof (szOrbits, NULL);
  printf ("One martian year takes%f",f2);
  return 0;
}
