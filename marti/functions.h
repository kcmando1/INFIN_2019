//insertion functions.h file
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <asm/socket.h>		//internes



void prova();
int clientStrRead(char *r, int *cr, float *n);
int serverStrRead (char *r, int *v, int *t, int *m);
int clientMenuStr(char* buffer);
int clientTcp(char* missatge, char* serverName);
#endif
