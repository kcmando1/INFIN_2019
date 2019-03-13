#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int serverStrInt (){
	
	char r[10];//rebuda
	int ref=-1;
	int i=0;
	int flag=0;
	char aux;
	int v=0,tm=1,nu=1;
	
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
				v=atoi(r[i]);
				i++;//p3
				tm=atoi(r[i])*10+atoi(r[i+1]);
				i++;//p4
				i++;//p5
				nu=atoi(r[i]);
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


