#include <stdio.h>
#include <stdlib.h>
#include "codes.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	char input[]="";
	char *tok;
	const char del=" ";
	int nrzl=0,nrzi=0,bami=0,pseu=0,man=0,dman=0,n=0,len=0;
	intro();
	for(;;)
		{
			scanf("%s",input);
			if(!strcmp(input,"help"))
				{
					help();
				}
			else if(!strcmp(input,"enable"))
				{
				}
			else if(!strcmp(input,"cls"))
				{
					system("cls");
				}
			else if(!strcmp(input,"exit"))
				{
					break;
				}
		}
	return 0;
}
