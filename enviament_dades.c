#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define cls "clear"



void main()
{
	int ref = -1;
	char misatgefinal[20];
	char misatge[20]="";
	int i = 0;int j = 0;
	char temps[2];
	char tempsinf[2];
	char mostres [5];
	int T, T1, M;
	int aux, aux1, aux2;
	
	printf("Posar en marxa o aturar = M\n");
	printf("Demanar mitjana aritmetica= U\n");
	printf("Demanar valor maxim = X\n");
	printf("Demanar valor minim = Y\n");
	printf("Reset del valor maxim i minim = R\n");
	printf("Demanar valor de mostres guardades = B\n");
	printf("\n");
	printf("Quina operació es vol realitzar?\n");


	
	misatgefinal[i]='{'; // i = 0
	scanf("%c",misatge);
	i++;	// i = 1
	misatgefinal[i]=toupper(misatge[j]); //j = 0



	switch(misatge[j]){
		case 'M':;
		case 'm':
			system(cls);
			printf("Si vols aturar pulsar 0, si vols posar en marxa pulsar 1:\n");
			scanf("%s",misatge);
			//printf("\n valor m0 %c",misatge[0]);
			aux=(int) misatge[0]; //->nyapa de pasar de ascii a valor del caracter de la taula ascii en int
			//printf("\n valor m1 %c",aux);
			if(aux==48||aux==49){//48 ->0 49 ->
					//printf("\n caca \n");
				
				
				i++;//i = 2
				misatgefinal[i]=misatge[j];	
				i++;j++; // i = 3	
				system(cls);
				printf("Introduir un temps de 1 a 20 segons:\n");
				scanf("%s",temps);
				printf("/n stringa %s /n",temps);
				aux=(int) temps[0];
				aux1=(int) temps[1];
				
				printf("/n int1=%d /n",aux);
				printf("/n int2=%d /n",aux1);
				switch(aux){
					case 48:
						if (aux1>48 &&aux1<=57){
							//go
							printf("\n caca1 \n");
						}else{
							//error
							printf("\n culo 1 \n");
						};
					break;
					
					case 49:
						if (aux1>=48 && aux1<=57){
							//go
							printf("\n caca2 \n");
						}else{
							//error
							printf("\n culo 2 \n");
						};
					break;
					
					case 50:
						if (aux1==48){
							//go
							printf("\n caca 3 \n");
						}else{
							//error
							printf("\n culo 3 \n");
						};
					break;
					default:
						//error
					
				}
					
				
				T = atoi(temps[0]);
				printf("/n T %d/n",T);
				if(T<=9){
					if(T<0){
						printf("error");
						ref = -1;
						break;
					}
					if(T==00){
						printf("error");
						ref = -1;
						break;
					}else{
						tempsinf[0]='0';
						tempsinf[1]=temps[0];
						temps[0]='\0';
						strcpy(temps,tempsinf);
						misatgefinal[i]=temps[0];
						i++; // i = 4
						misatgefinal[i]=temps[1];
						i++; // i = 5
						system(cls);
						printf("Introduir numero de mostres (0 a 9):\n");
						scanf("%s",mostres);
						T1 = atoi(mostres);
						if(0<T1 && T1<10){
						misatgefinal[i]=mostres[0];
						i++; // i = 6
						}else{
							printf("error");
							break;
						}
						misatgefinal[i]='}';
						ref = 1;
					}
				}else{
					if(T<0){
						printf("error");
						ref = -1;
						break;
					}
					if(T>20){
						printf("error");
						ref = -1;
						break;
					}else{
						misatgefinal[i]=temps[0];
						i++; // i = 4
						misatgefinal[i]=temps[1];
						i++; // i = 5
						system(cls);
						printf("Introduir numero de mostres (0 a 9):\n");
						scanf("%s",mostres);
						T1 = atoi(mostres);
						if(0<=T1 && T1<10){
							misatgefinal[i]=mostres[0];
							i++; // i = 6
							misatgefinal[i]='}';
							ref = 1;
						}else{
							printf("error");
						break;
						}		
					}							
				}
			printf("Misatge=%s",misatgefinal);
			}else{
				printf("error");
				break;
			}
			
			break;
			
		case 'U':;
		case 'u':
			system(cls);
			printf("Es vol rebre mitjana aritmètica\n");
			ref = 2;
			i++;
			misatgefinal[i]='}';

			printf("Misatge=%s",misatgefinal);
			break;
		
		case'X':;
		case'x':
			system(cls);
			printf("Es vol rebre el valor màxim\n");
			ref = 3;
			i++;
			misatgefinal[i]='}';
			
			printf("Misatge=%s",misatgefinal);
			break;			
		
		case 'Y':;
		case 'y':
			system(cls);
			printf("Es vol rebre el valor minim\n");
			ref = 4;
			i++;
			misatgefinal[i]='}';
			
			printf("Misatge=%s",misatgefinal);
			break;	
		
		case 'R':;
		case 'r':
			system(cls);
			printf("Es vol rebre el valor maxim i minim\n");
			i++;
			misatgefinal[i]='}';
			ref = 5;
			
			printf("Misatge=%s",misatgefinal);
			break;				
		
		case 'B':;
		case 'b':
			system(cls);
			printf("Es vol rebre el valor de mostres guardades\n");
			i++;
			misatgefinal[i]='}';
			ref = 6;
			
			printf("Misatge=%s",misatgefinal);
			break;					
	
} 
return 0;
}

