#include <string.h> 
void main(){
	int a=0,c;
	char b[100],d,r[100];
	sprintf(b,"%d",a);
	
	if(strlen(b)==4){
		r[0]=b[0];
		r[1]=b[1];
		r[2]=b[2];
		r[3]=b[3];
		
	}
	if(strlen(b)==3){
		r[0]='0';
		r[1]=b[0];
		r[2]=b[1];
		r[3]=b[2];
		
	}
	if(strlen(b)==2){
		r[0]='0';
		r[1]='0';
		r[2]=b[0];
		r[3]=b[1];
		
	}
	if(strlen(b)==1){
		r[0]='0';
		r[1]='0';
		r[2]='0';
		r[3]=b[0];
		
	}
	c=strlen(b);
	printf("strlen=%d",c);
	printf("stringa=%s",r);
}
