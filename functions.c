#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "functions.h"
int clientStrRead(char *r, int *cr, float *n){
	
	int ref=-1;
	int i=0;
	int flag=0;
	char aux,auxc[5],m[5],o[5];
	int adqs=0,ms=0;
	float un=0,xn=0,yn=0;
	
	if (r[i]!="{"){
		flag=1;
	}else{
		i++;//p1	
		aux=r[i];
		i++;//p2
		switch(aux){
			case 'M':;
			case 'm':
				ref=1;
				cr=atoi(r[i]);
				
				break;
				
			case 'U':;
			case 'u':
				ref=2;
				cr=atoi(r[i]);
				i++;
				auxc[0] = r[i];
				i++;
				auxc[1] = r[i];
				i++;
				auxc[2] = r[i];
				i++;
				auxc[3] = r[i];
				i++;
				auxc[4] = r[i];
				*n=atof(auxc);
				break;
				
			case 'X':;
			case 'x':
				ref=3;
				cr=atoi(r[i]);
				i++;
				auxc[0] = r[i];
				i++;
				auxc[1] = r[i];
				i++;
				auxc[2] = r[i];
				i++;
				auxc[3] = r[i];
				i++;
				auxc[4] = r[i];
				*n=atof(auxc);
				break;
				
			case 'Y':;
			case 'y':
				ref=4;
				cr=atoi(r[i]);
				i++;
				auxc[0] = r[i];
				i++;
				auxc[1] = r[i];
				i++;
				auxc[2] = r[i];
				i++;
				auxc[3] = r[i];
				i++;
				auxc[4] = r[i];
				*n=atof(auxc);
				break;
				break;
				
				break;
				
			case 'R':;
			case 'r':
				ref=5;
				cr=atoi(r[i]);
				break;
			
			case 'B':;
			case 'b':
				ref=6;
				cr=atoi(r[i]);
				break;
				
		return ref;		
		}
	}
}


int serverStrRead (char *r, int *v, int *t, int *m){
	printf("/n in/n");
	
	int ref=-1;
	int i=0;
	int flag=0;
	char aux;
	
	if (r[i]!="{"){
		flag=1;
	}else{
		i++;//p1	
		aux=r[i];
		i++;//p2
		switch(aux){
			case 'M':;
			case 'm':
				ref=1;
				*v=atoi(r[i]);
				i++;//p3
				*t=atoi(r[i])*10+atoi(r[i+1]);
				i++;//p4
				i++;//p5
				*m=atoi(r[i]);
				break;
			case 'U':;
			case 'u':
				ref=2;
				break;
				
			case 'X':;
			case 'x':
				ref=2;
				break;
				
			case 'Y':;
			case 'y':
				ref=3;
				break;
				
			case 'R':;
			case 'r':
				ref=4;
				break;
			
			case 'B':;
			case 'b':
				ref=5;
				break;
				
		return ref;		
		}
	}
}


