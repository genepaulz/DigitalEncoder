#ifndef CODES_H
#define CODES_H
//low line						wprintf(L"\x005f");
//overline						wprintf(L"\x203e");
//combining overline			wprintf(L"\x0305");
//vertical line 				wprintf(L"\x2502");

//horizontal bar/center line 	wprintf(L"\x2500");
//center up						wprintf(L"\x2518");
//center down 					wprintf(L"\x2510");

//down center 					wprintf(L"\x250c");
//up center						wprintf(L"\x2514");


//up down						wprintf(L"\x02e5");
//down up						wprintf(L"\x02e9");

void intro();
void help();
void nrzl(char e[]); //Non Return-to-Zero Level
void nrzi(char e[]); //Non Return-to-Zero Inverted
void bami(char e[]); //Bipolar AMI(Alternate Mark Inversion)
void pseu(char e[]); //Pseudoternary
void man(char e[]); //Manchester
void dman(char e[]); //Differential Manchester
void run(int nrzlf, int nrzif, int bamif, int pseuf, int manf, int dmanf, char e[]);
int check(char e[]);

#endif
