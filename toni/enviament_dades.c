#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define cls "clear"


//void clientMenuStr(char* str)
int main(/*char* buffer*/)
{
	char buffer[7];
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
						tmp[1]=temps[0];
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
//------------------------------------------------------------------------				
						system(cls);
						printf("Introduir numero de mostres (1 a 9):\n");
						scanf("%s",mostres);
						aux2 =(int) mostres[0];
						if (aux2>48 && aux2<=57){
							tmp1=mostres[0];
							printf("mostres=%c",tmp1);
						}else{
							printf("error");
							break;
						}
//----------------------------------------------------------------------									
						if(flag==0){
							
							buffer[0]='{';
							buffer[1]='M';
							
						
							buffer[2]=sta;
							buffer[3]=tmp[0];
							buffer[4]=tmp[1];
							buffer[5]=tmp1;
							buffer[6]='}';
							buffer[7]='\0';
							printf("\n buffer=%s",buffer);
							
						}		
			break;
//----------------------------------------------------------------------			
		case 'U':;
		case 'u':
			system(cls);
			printf("Es vol rebre mitjana aritmètica\n");
			buffer[0]='{';
			buffer[1]='U';
			buffer[2]='}';
			buffer[3]='\0';

			printf("Misatge=%s",buffer);
			break;
//----------------------------------------------------------------------					
		case'X':;
		case'x':
			system(cls);
			printf("Es vol rebre el valor màxim\n");
			buffer[0]='{';
			buffer[1]='X';
			buffer[2]='}';
			buffer[3]='\0';
			
					
			printf("Misatge=%s",buffer);
			break;			
//----------------------------------------------------------------------					
		case 'Y':;
		case 'y':
			system(cls);
			printf("Es vol rebre el valor minim\n");
			buffer[0]='{';
			buffer[1]='Y';
			buffer[2]='}';
			buffer[3]='\0';
			
					
			printf("Misatge=%s",buffer);
			break;	
//----------------------------------------------------------------------					
		case 'R':;
		case 'r':
			system(cls);
			printf("Es vol rebre el valor maxim i minim\n");
			buffer[0]='{';
			buffer[1]='R';
			buffer[2]='}';
			buffer[3]='\0';
			
						
			printf("Misatge=%s",buffer);
			break;				
//----------------------------------------------------------------------				
		case 'B':;
		case 'b':
			system(cls);
			printf("Es vol rebre el valor de mostres guardades\n");
			buffer[0]='{';
			buffer[1]='B';
			buffer[2]='}';
			buffer[3]='\0';
			
					
			printf("Misatge=%s",buffer);
			break;					
//----------------------------------------------------------------------				
	} 
	return flag;
}

