#include<stdio.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include "codes.h"


void intro()
{
	_setmode(_fileno(stdout), _O_TEXT);
	printf("This program will encode binary into digital signals\n");
	printf("coded by Gene Paul M. Zafra BSCS-3\n");
	printf("submitted to Maam Arellano\n\n");
	printf("\nEnter 'help' for help\n\n");
}
void help()
{
	_setmode(_fileno(stdout), _O_TEXT);
	printf("\nThis program can encode binary into several digital signal encoding such as:\n");
	printf("ENCODING TYPE						CODE\n");
	printf("Non Return-to-Zero Level(NRZ-L)				1\n");
	printf("Non Return-to-Zero Inverted(NRZ-I)			2\n");
	printf("Bipolar AMI(Alternate Mark Inversion)			3\n");
	printf("Pseudoternary						4\n");
	printf("Machester						5\n");
	printf("Differential Manchester					6\n\n");
	printf("COMMANDS\n");
	printf("cls		-empties the console\n");
	printf("help		-outputs help\n");
	printf("exit		-exits the application\n\n");
}

void nrzl(char e[])
{
	int i,j;
	int len = strlen(e);
	_setmode(_fileno(stdout), _O_TEXT);
	printf("Non Return-to-Zero Level Encoding\n");
	printf("%s\n",e);
	_setmode(_fileno(stdout), _O_U16TEXT);
	for(i=0; i<len; i++)
		{
			j=i+1;
			if(e[i]=='0')
				{
					wprintf(L"\x005f");
				}
			else if(e[i]=='1')
				{
					wprintf(L"\x203e");
				}
			if(j==len)
				break;
			wprintf(L"\x2502");
		}
	_setmode(_fileno(stdout), _O_TEXT);
	printf("\n\n");
}

void nrzi(char e[])
{
	int i,j;
	int len = strlen(e);
	int up=0;
	_setmode(_fileno(stdout), _O_TEXT);
	printf("Non Return-to-Zero Inverted Encoding\n");
	printf("%s\n",e);
	_setmode(_fileno(stdout), _O_U16TEXT);
	for(i=0; i<len; i++)
		{
			j=i+1;
			if(e[i]=='0' && !up)
				{
					wprintf(L"\x005f");
				}
			else if(e[i]=='0' && up)
				{
					wprintf(L"\x203e");
				}
			else if(e[i]=='1' && !up)
				{
					wprintf(L"\x203e");
					up=1;
				}
			else
				{
					wprintf(L"\x005f");
					up=0;
				}
			if(e[j]=='\0')
				break;
			wprintf(L"\x2502");
		}
	_setmode(_fileno(stdout), _O_TEXT);
	printf("\n\n");
}

void bami(char e[])
{
	int i,j;
	int len = strlen(e);
	_setmode(_fileno(stdout), _O_TEXT);
	printf("Bipolar AMI(Alternate Mark Inversion) Encoding\n");
	printf("%s\n",e);
	_setmode(_fileno(stdout), _O_U16TEXT);
	int up = 1;
	for(i=0; i<len; i++)
		{
			j=i+1;
			if(e[i]=='0')
				{
					if(e[j]=='0' || e[j]=='\0')
						{
							wprintf(L"\x2500");
						}
					else if(e[j]=='1' && up)
						{
							wprintf(L"\x2500");
							wprintf(L"\x2518");
						}
					else
						{
							wprintf(L"\x2500");
							wprintf(L"\x2510");
						}
				}
			else
				{
					if(up && e[j]=='0')
						{
							wprintf(L"\x203e");
							wprintf(L"\x2514");
							up=0;
						}
					else if(e[j]=='0')
						{
							wprintf(L"\x005f");
							wprintf(L"\x250c");
							up=1;
						}
					else if(up && e[j]=='1')
						{
							wprintf(L"\x203e");
							wprintf(L"\x2502");
							up=0;
						}
					else if(e[j]=='1')
						{
							wprintf(L"\x005f");
							wprintf(L"\x2502");
							up=1;
						}
					else if(up && e[j]=='\0')
						{
							wprintf(L"\x203e");
						}
					else
						{
							wprintf(L"\x005f");
						}
				}
		}
	_setmode(_fileno(stdout), _O_TEXT);
	printf("\n\n");
}

void pseu(char e[])
{
	int i,j;
	int len = strlen(e);
	_setmode(_fileno(stdout), _O_TEXT);
	printf("Pseudoternary Encoding\n");
	printf("%s\n",e);
	_setmode(_fileno(stdout), _O_U16TEXT);
	int up = 1;
	for(i=0; i<len; i++)
		{
			j=i+1;
			if(e[i]=='1')
				{
					if(e[j]=='1' || e[j]=='\0')
						{
							wprintf(L"\x2500");
						}
					else if(e[j]=='0' && up)
						{
							wprintf(L"\x2500");
							wprintf(L"\x2518");
						}
					else
						{
							wprintf(L"\x2500");
							wprintf(L"\x2510");
						}
				}
			else
				{
					if(up && e[j]=='1')
						{
							wprintf(L"\x203e");
							wprintf(L"\x2514");
							up=0;
						}
					else if(e[j]=='1')
						{
							wprintf(L"\x005f");
							wprintf(L"\x250c");
							up=1;
						}
					else if(up && e[j]=='0')
						{
							wprintf(L"\x203e");
							wprintf(L"\x2502");
							up=0;
						}
					else if(e[j]=='0')
						{
							wprintf(L"\x005f");
							wprintf(L"\x2502");
							up=1;
						}
					else if(up && e[j]=='\0')
						{
							wprintf(L"\x203e");
						}
					else
						{
							wprintf(L"\x005f");
						}
				}
		}
	_setmode(_fileno(stdout), _O_TEXT);
	printf("\n\n");
}

void man(char e[])
{
	int i,j;
	int len = strlen(e);
	_setmode(_fileno(stdout), _O_TEXT);
	printf("Manchester Encoding\n");
	printf("%s\n",e);
	_setmode(_fileno(stdout), _O_U16TEXT);
	for(i=0; i<len; i++)
		{
			j=i+1;
			if(e[i]=='0')
				{
					wprintf(L"\x203e");
					wprintf(L"\x2502");
					wprintf(L"\x005f");
				}
			else
				{
					wprintf(L"\x005f");
					wprintf(L"\x2502");
					wprintf(L"\x203e");
				}
			if(e[j]==e[i])
				{
					wprintf(L"\x2502");
				}
		}
	_setmode(_fileno(stdout), _O_TEXT);
	printf("\n\n");
}

void dman(char e[])
{
	int i,j;
	int len = strlen(e);
	_setmode(_fileno(stdout), _O_TEXT);
	printf("Differential Manchester Encoding\n");
	printf("%s\n",e);
	_setmode(_fileno(stdout), _O_U16TEXT);
	int trans=e[0]=='1'?0:1;
	int high=e[0]=='0'?1:0;
	for(i=0; i<len; i++)
		{
			j=i+1;
			if(e[i]=='0' && high)
				{
					wprintf(L"\x2502");
					wprintf(L"\x005f");
					wprintf(L"\x2502");
					wprintf(L"\x203e");
				}
			else if(e[i]=='0' && !high)
				{
					wprintf(L"\x2502");
					wprintf(L"\x203e");
					wprintf(L"\x2502");
					wprintf(L"\x005f");
				}
			else if(e[i]=='1' && high)
				{
					wprintf(L"\x203e");
					wprintf(L"\x2502");
					wprintf(L"\x005f");
					high=0;
				}
			else
				{
					wprintf(L"\x005f");
					wprintf(L"\x2502");
					wprintf(L"\x203e");
					high=1;
				}
		}
	_setmode(_fileno(stdout), _O_TEXT);
	printf("\n\n");
}

void run(int nrzlf, int nrzif, int bamif, int pseuf, int manf, int dmanf, char e[])
{
	printf("START OF Encoding %s\n\n",e);
	if(nrzlf)
		{
			nrzl(e);
		}
	if(nrzif)
		{
			nrzi(e);
		}
	if(bamif)
		{
			bami(e);
		}
	if(pseuf)
		{
			pseu(e);
		}
	if(manf)
		{
			man(e);
		}
	if(dmanf)
		{
			dman(e);
		}
	printf("END OF Encoding %s\n\n\n",e);
}

int check(char e[])
{
	int len = strlen(e);
	int i;
	int flag = 1;
	for(i=0; i<len; i++)
		{
			if(e[i]!=1 && e[i]!=0)
				{
					printf("\nPlease input digital data (binary)\n\n");
					flag = 0;
					break;
				}
		}
	return flag;
}
