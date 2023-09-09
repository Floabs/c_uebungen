#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "teppich.h"

#define DEFAULT_TEPPICH_LENGTH 18
#define DEFAULT_TEPPICH_BREITE 9;

Teppich* new_teppich_default()
{
	Teppich* p_teppich = calloc(1, sizeof(Teppich));
	p_teppich ->laenge = DEFAULT_TEPPICH_LENGTH;
	p_teppich ->breite = DEFAULT_TEPPICH_BREITE;
	p_teppich ->anzahl_reihen_teppich_rand = 2;
	p_teppich ->dicke_teppich_muster = 3;
	return p_teppich;
}
int anzahl_reihen_teppich_muster(Teppich teppich) {
	return teppich.laenge - 2 * teppich.anzahl_reihen_teppich_rand;
}
int leerzeichen_teppich(Teppich teppich) {
	return teppich.breite - 2 * teppich.dicke_teppich_muster;
}

void rand_funktion(Teppich teppich)
{
	for (int local_rand_counter = teppich.anzahl_reihen_teppich_rand; local_rand_counter > 0; local_rand_counter--)
	{
		for (int local_breite_counter = teppich.breite; local_breite_counter > 0; local_breite_counter--)
		{
			printf("*");
			if (local_breite_counter == 1)
			{
				printf("\n");
			}
		}
	}
}

void muster_befueller(Teppich teppich)
{
	for (int local_dicke_counter = teppich.dicke_teppich_muster; local_dicke_counter > 0; local_dicke_counter--)
	{
		printf("*");
	}
}

void leerzeichen_befueller(Teppich teppich)
{
	int start = leerzeichen_teppich(teppich);
	for (int local_leerzeichen_counter = start; local_leerzeichen_counter > 0; local_leerzeichen_counter--)
	{
		printf(" ");
	}
}

void zeichne_teppich(Teppich teppich)
{
	rand_funktion(teppich);
	for (int local_reihen_counter = anzahl_reihen_teppich_muster(teppich); local_reihen_counter > 0; local_reihen_counter = local_reihen_counter--)
	{
		muster_befueller(teppich);
		leerzeichen_befueller(teppich);
		muster_befueller(teppich);
		printf("\n");
	}
	rand_funktion(teppich);
}
	