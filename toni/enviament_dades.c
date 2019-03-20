#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define cls "clear"


//void clientMenuStr(char* str)
int main(/*char* buffer*/)
{
	char* buffer;
	char misatge[20]="";
	char temps[2];
	char mostres [5];
	int flag=0;
	char sta,tmp[2],tmp1;
	int aux, aux1, aux2=-1;
	
	printf("Posar en marxa o aturar = M\n");
	printf("Demanar mitjana aritmetica= U\n");
	printf("Demanar valor maxim = X\n");
	printf("Demanar valor minim = Y\n");
	printf("Reset del valor maxim i minim = R\n");
	printf("Demanar valor de mostres guardades = B\n");
	printf("\n");
	printf("Quina operació es vol realitzar?\n");


	
	
	scanf("%c",misatge);
	
	



	switch(misatge[0]){
		case 'M':;
		case 'm':
			system(cls);
			printf("Si vols aturar pulsar 0, si vols posar en marxa pulsar 1:\n");
			scanf("%s",misatge);
			//printf("\n valor m0 %c",misatge[0]);
			aux=(int) misatge[0]; //->nyapa de pasar de ascii a valor del caracter de la taula ascii en int
			//printf("\n valor m1 %c",aux);
			if(aux==48||aux==49){//48 ->0 49 ->
				sta=misatge[0];
			}else{
				printf("error");
				flag=1;
			}		
//------------------------------------------------------------------------				
				system(cls);
				printf("Introduir un temps de 1 a 20 segons:\n");
				scanf("%s",temps);
				//printf("/n stringa %s /n",temps);
				aux=(int) temps[0];
				aux1=(int) temps[1];
				
			
				
				if (aux1=='\0'){
					aux2=atoi(temps);
					if((aux2 != 0)&&(0<aux2 && aux2<10)){
						tmp[0]='0';
						tmp[1]=temps;
					}else{
						//error
						printf("error");
						flag=1;
					}
				}else{
					switch(aux){
						case 48:
							if (aux1>48 &&aux1<=57){
								//go
								tmp[0]=aux;
								tmp[1]=aux1;
								
								
							}else{
								//error
								printf("error");
								flag=1;
								printf("\n entrada de dades incorrecta \n");
								break;
							};
							break;
						
						case 49:
							if (aux1>=48 && aux1<=57){
								//go
								tmp[0]=aux;
								tmp[1]=aux1;
								
								
							}else{
								//error
								printf("error");
								flag=1;
								printf("\n entrada de dades incorrecta  2 \n");
							};
							break;
						
						case 50:
							if (aux1==48){
								//go
								tmp[0]=aux;
								tmp[1]=aux1;
								
							}else{
								//error
								printf("error");
								flag=1;
								printf("\n entrada de dades incorrecta  3 \n");
							};
							break;				
						}
				}	
				printf("/n resultat t %s/n");	
//------------------------------------------------------------------------				
						system(cls);
						printf("Introduir numero de mostres (0 a 9):\n");
						scanf("%s",mostres);
						aux2 = atoi(mostres);
						if(0<aux2 && aux2<10){
							tmp1=aux2;
						}else{
							printf("error");
							break;
						}
//----------------------------------------------------------------------									
						if(flag==0){
							buffer[0]='{';
							buffer[1]='M';
							strcat(buffer,sta);
							strcat(buffer,tmp);
							strcat(buffer,tmp1);
							buffer[5]='}';
							buffer[6]='\0';
						}		
			break;
//----------------------------------------------------------------------			
		case 'U':;
		case 'u':
			system(cls);
			printf("Es vol rebre mitjana aritmètica\n");
			
			

			printf("Misatge=%s",buffer);
			break;
//----------------------------------------------------------------------					
		case'X':;
		case'x':
			system(cls);
			printf("Es vol rebre el valor màxim\n");
			
					
			printf("Misatge=%s",buffer);
			break;			
//----------------------------------------------------------------------					
		case 'Y':;
		case 'y':
			system(cls);
			printf("Es vol rebre el valor minim\n");
			
			buffer=			
			printf("Misatge=%s",buffer);
			break;	
//----------------------------------------------------------------------					
		case 'R':;
		case 'r':
			system(cls);
			printf("Es vol rebre el valor maxim i minim\n");
			
						
			printf("Misatge=%s",buffer);
			break;				
//----------------------------------------------------------------------				
		case 'B':;
		case 'b':
			system(cls);
			printf("Es vol rebre el valor de mostres guardades\n");
			
					
			printf("Misatge=%s",buffer);
			break;					
//----------------------------------------------------------------------				
	} 
	return flag;
}

