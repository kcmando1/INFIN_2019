#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define cls "clear"



void main()
{
	
	
	printf("Posar en marxa o aturar = M\n");
	printf("Demanar mitjana aritmetica= U\n");
	printf("Demanar valor maxim = X\n");
	printf("Demanar valor minim = Y\n");
	printf("Reset del valor maxim i minim = R\n");
	printf("Demanar valor de mostres guardades = B\n");
	printf("\n");
	printf("Quina operació es vol realitzar?\n");


	int ref = -1;
	char misatgefinal[20];
	char misatge[20]="";
	int i = 0;int j = 0;
	char temps[5];
	char mostres [5];
	misatgefinal[i]='{'; // i = 0
	scanf("%c",misatge);
	i++;	// i = 1
	misatgefinal[i]=misatge[j]; //j = 0



	switch(misatge[j]){
		case 'M':;
		case 'm':
			system(cls);
			
			printf("Si vols aturar pulsar 0, si vols posar en marxa pulsar 1:\n");
			scanf("%s",misatge);
			i++;//i = 2
			misatgefinal[i]=misatge[j];	
			i++;j++; // i = 3	
			system(cls);
			
			
			printf("Introduir un temps de 1 a 20 segons:\n");
			scanf("%s",temps);
			
			misatgefinal[i]=temps[0];
			i++; // i = 4
			misatgefinal[i]=temps[1];
			i++; // i = 5
			
			system(cls);
			printf("Introduir numero de mostres (0 a 9):\n");
			scanf("%s",mostres);
			misatgefinal[i]=mostres[0];
			i++; // i = 6
			
			
			misatgefinal[i]='}';
			ref = 1;
			break;
			
		case 'U':;
		case 'u':
			system(cls);
			printf("Es vol rebre mitjana aritmètica\n");
			ref = 2;
			i++;
			misatgefinal[i]='}';

			break;
		
		case'X':;
		case'x':
			system(cls);
			printf("Es vol rebre el valor màxim\n");
			ref = 3;
			i++;
			misatgefinal[i]='}';
			break;			
		
		case 'Y':;
		case 'y':
			system(cls);
			printf("Es vol rebre el valor minim\n");
			ref = 4;
			i++;
			misatgefinal[i]='}';
			break;	
		
		case 'R':;
		case 'r':
			system(cls);
			printf("Es vol rebre el valor maxim i minim\n");
			i++;
			misatgefinal[i]='}';
			ref = 5;
			break;				
		
		case 'B':;
		case 'b':
			system(cls);
			printf("Es vol rebre el valor de mostres guardades\n");
			i++;
			misatgefinal[i]='}';
			ref = 6;
			break;					
	
} 


printf("Misatge=%s",misatgefinal);


	
	
	return 0;

	
	
	
	
	
}
