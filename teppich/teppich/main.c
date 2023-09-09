#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "teppich.h"
#define TEPPICH_CHAR '*'


char findeZeichenAnPosition(Teppich teppich, int zeile, int spalte) {
	char ch = '.';
	if (zeile < teppich.anzahl_reihen_teppich_rand) {
		ch = TEPPICH_CHAR;
	}
	if (spalte < teppich.dicke_teppich_muster)
	{
		ch = TEPPICH_CHAR;
	}
	if (spalte >= (teppich.breite - teppich.dicke_teppich_muster))
	{
		ch = TEPPICH_CHAR;
	}
	if (zeile >= teppich.laenge - teppich.anzahl_reihen_teppich_rand)
	{
		ch = TEPPICH_CHAR;
	}
	
	return ch;
}

void zeichne_teppich2(Teppich teppich) {
	for(int zeile = 0; zeile < teppich.laenge; zeile++) {
		for(int spalte = 0; spalte < teppich.breite; spalte++) {
			char ch = findeZeichenAnPosition(teppich, zeile, spalte);
			printf("%c", ch);
		}
		printf("\n");
	}
}

int main() 
{

	Teppich teppich = teppich_default();
	zeichne_teppich2(teppich);

	return 0;
}


/*
  0123456		Spalte/breite
 0*******
 1*******
 2**   4**
 3*******
 4*******

 Zl
 ea
 ie
 la
 en

 struct Teppich {
	int laenge;
	int breite;
	int anzahl_reihen_teppich_rand;
	int dicke_teppich_muster;
};
typedef struct Teppich Teppich;
void zeichne_teppich(Teppich teppich);
Teppich teppich_default();



*/