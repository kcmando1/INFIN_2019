/***************************************************************************
                          client_main.c  
                             -------------------
    begin                : mie mar  27 17:30:41
    copyright            : (C) 2019 by 349Kings
    email                : marti.soucheiron@hotmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "functions.h"

void main()
{
	char b[10],nan;
	int aux=-1,cr=0,rs=-2,cont=0;
	float fret;
	clda dare[3600];
	while(1){
		
		aux=clientMenuStr(b);
		clientTcp(b,"127.0.0.1");
		dare[cont]=clientStrRead(b,&cr,&fret,cont);
		if(b[1]=='x'||b[1]=='y'||b[1]=='u'||b[1]=='b'||b[1]=='X'||b[1]=='Y'||b[1]=='U'||b[1]=='B'){
			printf("\n dare\nmit %f\nmax %f\nmin %f\ncont %d\n",dare[cont].mit,dare[cont].max,dare[cont].min,dare[cont].counter);
		}
		cont++;
		//printf("\n flag=%d \n",aux);
		printf("\n buffer= %s",b);
	}
	
	

return 0;
}

