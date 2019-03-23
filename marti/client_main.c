#include "functions.h"

void main()
{
	char b[10];
	int aux=-1;
	aux=clientMenuStr(b);
	clientTcp(b,"127.0.0.1");
	printf("\n flag=%d \n",aux);
	printf("\n buffer=%s",b);
	


}

