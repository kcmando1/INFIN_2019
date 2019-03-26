//inclu l'arxiu de capçaleres
#include "functions.h"

#define cls "clear"//definicio per SO linux/windows per el barrido de pantalla(clientMenuStr)
//definicions de clientTcp
#define REQUEST_MSG_SIZE	1024
#define REPLY_MSG_SIZE		500
#define SERVER_PORT_NUM		5001
//funcio per saber si el functions.c funciona i el referencies be.
void prova(){
	printf("\n in \n");
	printf("asdf");

}
//funcio per convertir un sol caracter a numeric.
int ctoi( char c ){
    return c=='0'?0:c=='1'?1:c=='2'?2:c=='3'?3:c=='4'?4:
           c=='5'?5:c=='6'?6:c=='7'?7:c=='8'?8:c=='9'?9:-1;
}
//funcio que crida al client tcp. Li has de passar el array i la direcció IP.
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
//funcio que fa de menu per escollir les trames a enviar desde el client
int clientMenuStr(char* buffer){
	
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
//funcio que llegeix el que ha rebut del servidor i ho converteix a dades a guardar
int clientStrRead(char *r, int *cr, float *n){
	
	int ref=-1;
	int i=0;
	int flag=0;
	char aux,auxc[5],m[5],o[5];
	int adqs=0,ms=0;
	float un=0,xn=0,yn=0;
	
	if (!(r[i]=='{')){
		flag=1;
		printf("caca");
	}else{
		printf("culo");
		i++;//p1	
		aux=r[i];
		i++;//p2
		printf("case %c",aux);
		switch(aux){
			case 'M':;
			case 'm':
				ref=1;
				cr=ctoi(r[i]);
				
				break;
				
			case 'U':;
			case 'u':
				ref=2;
				cr=ctoi(r[i]);
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
				auxc[5] = '\0';
				printf("atoff %f",atof(auxc));
				*n=atof(auxc);
				break;
				
			case 'X':;
			case 'x':
				ref=3;
				cr=ctoi(r[i]);
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
				auxc[5] = '\0';
				printf("atoff %f",atof(auxc));
				*n=atof(auxc);
				break;
				
			case 'Y':;
			case 'y':
				ref=4;
				cr=ctoi(r[i]);
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
				auxc[5] = '\0';
				printf("atoff %f",atof(auxc));
				*n=atof(auxc);
				break;
				break;
				
				break;
				
			case 'R':;
			case 'r':
				ref=5;
				cr=ctoi(r[i]);
				break;
			
			case 'B':;
			case 'b':
				ref=6;
				cr=ctoi(r[i]);
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
				//auxc[5] = '\0';
				printf("\n auxc = %s\n",auxc);
				printf("atoff %f",strtof(auxc,NULL));
				*n=atof(auxc);
				printf("\n atof = %f\n",*n);
				break;
				
			
		}
	}
	return ref;	
}
//funcio que agafa la trama rebuda del client i la identifica.
int serverStrRead (char *r, int *v, int *t, int *m){
	float mit=1.234,max=0.123,min=0.987;
	int cont=55;
	int rs=-2;
	int i=0;
	int flag=0;
	char aux,b[10];
	int vi, ti, mi;
	char cr='0';
	if (r[i]!='{'){
		rs=-1;
		printf("\n in1\n");
	}else{
		printf("\n in2\n");
		i++;//p1	
		aux=r[i];
		i++;//p2
		switch(aux){
			case 'M':;
			case 'm':
				printf("\n in1\n");
				rs=1;
				aux=r[i];
				vi=ctoi(aux);
				printf("\n in3\n");
				i++;//p3
				ti=ctoi(r[i])*10+ctoi(r[i+1]);
				i++;//p4
				i++;//p5
				mi=ctoi(r[i]);
				if (!(vi==0||vi==1)){
					cr='2';
				}
				if (ti>20||ti<1){
					cr='2';
				}
				if (mi>9||mi<1){
					cr='2';
				}
				
				r[0]='{';
				r[1]='M';
				r[2]=cr;
				r[3]='}';
				r[4]='\0';
				break;
			case 'U':;
			case 'u':
				rs=2;
				b[0]='\0';
				sprintf(b,"%.3f",mit);
				r[0]='{';
				r[1]='U';
				r[2]=cr;
				r[3]=b[0];
				r[4]=b[1];
				r[5]=b[2];
				r[6]=b[3];
				r[7]=b[4];
				r[8]='}';
				r[9]='\0';
				
				
				break;
				
			case 'X':;
			case 'x':
				rs=2;
				
				sprintf(b,"%.3f",max);
				r[0]='{';
				r[1]='X';
				r[2]=cr;
				r[3]=b[0];
				r[4]=b[1];
				r[5]=b[2];
				r[6]=b[3];
				r[7]=b[4];
				r[8]='}';
				r[9]='\0';
				break;
				
			case 'Y':;
			case 'y':
				rs=3;
				sprintf(b,"%.3f",min);
				printf("\n cont s %c %c %c %c %c \n",b[0],b[1],b[2],b[3],b[4]);
				r[0]='{';
				r[1]='Y';
				r[2]=cr;
				r[3]=b[0];
				r[4]=b[1];
				r[5]=b[2];
				r[6]=b[3];
				r[7]=b[4];
				r[8]='}';
				r[9]='\0';
				break;
				
			case 'R':;
			case 'r':
				rs=4;
				r[0]='{';
				r[1]='R';
				r[2]=cr;
				r[3]='}';
				r[4]='\0';
				
				break;
			
			case 'B':;
			case 'b':
			
				rs=5;
				b[0]='\0';
				sprintf(b,"%d",cont);
				//printf("\n cont s %c %c %c %c \n",b[0],b[1],b[2],b[3]);    
				//printf("\n cont=%s \n",b);
				r[0]='{';
				r[1]='B';
				r[2]=cr;
				//r[3]=r[4]=r[5]=r[6]='0';
				if(strlen(b)>=4){
					r[3]=b[0];
					r[4]=b[1];
					r[5]=b[2];
					r[6]=b[3];	
				}
				if(strlen(b)==3){
					r[3]='0';
					r[4]=b[0];
					r[5]=b[1];
					r[6]=b[2];	
				}
				if(strlen(b)==2){
					r[3]='0';
					r[4]='0';
					r[5]=b[0];
					r[6]=b[1];
				}
				if(strlen(b)==1){
					r[3]='0';
					r[4]='0';
					r[5]='0';
					r[6]=b[0];
				}
				r[7]='}';
				r[8]='\0';
				break;
			default:
				r[0]='{';
				r[1]='0';
				r[2]='1';
				r[3]='}';
				r[4]='\0';
				break;
				
		}
	}
	printf("\n ref interna=%d\n",rs);
	*v=vi;
	*t=ti;
	*m=mi;
	return rs;	
}


