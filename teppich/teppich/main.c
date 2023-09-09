

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "teppich.h"

#define TEPPICH_CHAR '*'


char findeZeichenAnPosition(Teppich* p_teppich, int zeile, int spalte) {
	char ch = '.';
	if (zeile < p_teppich -> anzahl_reihen_teppich_rand) {
		ch = TEPPICH_CHAR;
	}
	if (spalte < p_teppich -> dicke_teppich_muster)
	{
		ch = TEPPICH_CHAR;
	}
	if (spalte >= (p_teppich -> breite - p_teppich -> dicke_teppich_muster))
	{
		ch = TEPPICH_CHAR;
	}
	if (zeile >= p_teppich -> laenge - p_teppich -> anzahl_reihen_teppich_rand)
	{
		ch = TEPPICH_CHAR;
	}
	
	return ch;
}

void zeichne_teppich2(Teppich* p_teppich) {
	for(int zeile = 0; zeile < p_teppich -> laenge; zeile++) {
		for(int spalte = 0; spalte < p_teppich -> breite; spalte++) {
			char ch = findeZeichenAnPosition(p_teppich, zeile, spalte);
			printf("%c", ch);
		}
		printf("\n");
	}
}

int main() 
{

	//Teppich teppich = teppich_default();
	Teppich* p_teppich = new_teppich_default();
	zeichne_teppich2(p_teppich);
	free(p_teppich);
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