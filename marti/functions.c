//inclu l'arxiu de capçaleres
#include "functions.h"

#define cls "clear"//definicio per SO linux/windows per el barrido de pantalla(clientMenuStr)
//definicions de clientTcp
#define REQUEST_MSG_SIZE	1024
#define REPLY_MSG_SIZE		500
#define SERVER_PORT_NUM		5001

void prova(){
	printf("\n in \n");
	printf("asdf");

}
int clientTcp(char* missatge, char* serverName){
	
	struct sockaddr_in	serverAddr;
	//char	    serverName[] = "127.0.0.1"; //Adreça IP on est� el servidor
	int			sockAddrSize;
	int			sFd;
	int 		result;
	char		buffer[256];
	//char		missatge[] = "{X}";

	/*Crear el socket*/
	sFd=socket(AF_INET,SOCK_STREAM,0);

	/*Construir l'adreça*/
	sockAddrSize = sizeof(struct sockaddr_in);
	bzero ((char *)&serverAddr, sockAddrSize); //Posar l'estructura a zero
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons (SERVER_PORT_NUM);
	serverAddr.sin_addr.s_addr = inet_addr(serverName);

	/*Conexió*/
	result = connect (sFd, (struct sockaddr *) &serverAddr, sockAddrSize);
	if (result < 0)
	{
		printf("Error en establir la connexió\n");
		exit(-1);
	}
	printf("\nConnexió establerta amb el servidor: adreça %s, port %d\n",	inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port));

	/*Enviar*/
	strcpy(buffer,missatge); //Copiar missatge a buffer
	result = write(sFd, buffer, strlen(buffer));
	printf("Missatge enviat a servidor(bytes %d): %s\n",	result, missatge);

	/*Rebre*/
	result = read(sFd, buffer, 256);
	printf("Missatge rebut del servidor(bytes %d): %s\n",	result, buffer);

	/*Tancar el socket*/
	close(sFd);

	return 0;
	}

int clientMenuStr(char* buffer)
{
	
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
							flag=1;
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
			default: 
				flag=1;
//----------------------------------------------------------------------				
	} 
	return flag;
}


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
	
	int ref=-2;
	int i=0;
	int flag=0;
	char aux;
	
	if (r[i]!="{"){
		ref=-1;
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


