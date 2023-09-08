#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "teppich.h"

char findeZeichenAnPosition(Teppich teppich, int zeile, int spalte) {
	char ch = '*';
	if (spalte >= teppich.anzahl_reihen_teppich_rand) {
		if (zeile > teppich.dicke_teppich_muster) {
			ch = '.';
		}
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
