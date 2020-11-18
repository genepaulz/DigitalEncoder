#include <stdio.h>
#include <stdlib.h>
#include "codes.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	char input[]="";
	int nrzl=0,nrzi=0,bami=0,pseu=0,man=0,dman=0,flag=0,n=0;

	while(flag!=1)
		{
			intro();
			printf("Need help? Press 7\n");
			if(nrzl)
				{
					printf("Press 1 to disable Non Return-to-Zero Level Encoding\n");
				}
			else
				{
					printf("Press 1 to enable Non Return-to-Zero Level Encoding\n");
				}
			if(nrzi)
				{
					printf("Press 2 to disable Non Return-to-Zero Inverted Encoding\n");
				}
			else
				{
					printf("Press 2 to enable Non Return-to-Zero Inverted Encoding\n");
				}
			if(bami)
				{
					printf("Press 3 to disable Bipolar AMI(Alternate Mark Inversion) Encoding\n");
				}
			else
				{
					printf("Press 3 to enable Bipolar AMI(Alternate Mark Inversion) Encoding\n");
				}
			if(pseu)
				{
					printf("Press 4 to disable Pseudoternary Encoding\n");
				}
			else
				{
					printf("Press 4 to enable Pseudoternary Encoding\n");
				}
			if(man)
				{
					printf("Press 5 to disable Manchester Encoding\n");
				}
			else
				{
					printf("Press 5 to enable Manchester Encoding\n");
				}
			if(dman)
				{
					printf("Press 6 to disable Differential Manchester Encoding\n");
				}
			else
				{
					printf("Press 6 to enable Differential Manchester Encoding\n");
				}
			printf("Press 8 to start encoding\n");
			printf("Press 0 to Exit\n");
			scanf("%d",&n);
			switch(n)
				{
					case 1:
						nrzl=!nrzl;
						system("cls");
						break;
					case 2:
						nrzi=!nrzi;
						system("cls");
						break;
					case 3:
						bami=!bami;
						system("cls");
						break;
					case 4:
						pseu=!pseu;
						system("cls");
						break;
					case 5:
						man=!man;
						system("cls");
						break;
					case 6:
						dman=!dman;
						system("cls");
						break;
					case 7:
						printf("\n");
						help();
						break;
					case 8:
						printf("\nThe program will only read 1s and 0s.\n");
						printf("Please input a binary digital data: ");
						scanf("%s",input);
						printf("\n");
						run(nrzl,nrzi,bami,pseu,man,dman,input);
						break;
					case 0:
						flag=1;
						printf("Thank you for using my program!\n");
						break;
				}			
		}
	return 0;
}
