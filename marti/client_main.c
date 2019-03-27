#include "functions.h"

void main()
{
	char b[10];
	int aux=-1,cr=0,rs=-2;
	float fret;
	aux=clientMenuStr(b);
	clientTcp(b,"127.0.0.1");
	rs=clientStrRead(b,&cr,&fret);
	
	
	
	printf("\n flag=%d \n",aux);
	printf("\n buffer= %s",b);
	printf("\n cr= %d",cr);
	printf("\n float= %f",fret);
	


}

