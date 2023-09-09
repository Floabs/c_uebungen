#pragma once
struct Teppich {
	int laenge;
	int breite;
	int anzahl_reihen_teppich_rand;
	int dicke_teppich_muster;
};
typedef struct Teppich Teppich;
void zeichne_teppich(Teppich teppich);
Teppich* new_teppich_default();
