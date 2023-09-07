#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

struct Teppich {
	int laenge;
	int breite;
	int anzahl_reihen_teppich_rand;
	int anzahl_reihen_teppich_muster;
	int dicke_teppich_muster;
	int leerzeichen_teppich;
};

typedef struct Teppich Teppich;

Teppich teppich_groessen_ausleser()
{
	Teppich teppich;
	printf("Hallo, lass uns gemeinsam einen Teppich designen\n. Bitte gib die Länge deines Teppichs ein: \n");
	scanf("%d", &teppich.laenge);
	while (isdigit(teppich.laenge) == 0)
	{
		printf("Die Eingabe war inkorrekt. \n Ich brauche bitte eine ganze Zahl fuer die Laenge des Teppichs. \n Versuche es erneut. Eine ganze Zahl bitte: ");
		scanf("%d", &teppich.laenge);
	}
	printf("Wow ein %d langer Teppich, eine vorzügliche Wahl und weiter geht es mit dem Spass. \n Also sag mir bitte die Breite:  ", &teppich.laenge);
	scanf("%d", &teppich.breite);
	while (isdigit(teppich.breite) == 0)
	{
		printf("Die Eingabe war inkorrekt. \n Ich brauche bitte eine ganze Zahl fuer die Breite des Teppichs ein. \n Versuche es erneut: %d", &teppich.laenge);
		scanf("%d", &teppich.breite);
	}
	printf("Super! %d x %d, eine hervorragende Groesse  \n. Dann machen wir uns mal an das Muster  \n Wie dick haettest du denn deinen Rand gerne pro Seite?:  \n", &teppich.laenge, &teppich.breite);
	scanf("%d", &teppich.anzahl_reihen_teppich_rand);
	while ((isdigit(teppich.anzahl_reihen_teppich_rand) == 0) || (teppich.laenge > (teppich.anzahl_reihen_teppich_rand * 2)))
	{
		printf("Die Eingabe war inkorrekt.\n Bitte beachte nur ganze Zahlen zu verwenden ausserdem kann der Rand nicht ueber die Gesamtlaenge des Teppichs hinaus gehen. \n Bitte um eine erneute Eingabe der gewuenschten breite pro Seite: \n");
		scanf("%d", &teppich.anzahl_reihen_teppich_rand);
	}
	printf("Sehr schoen, ein %d breiter Rand oben und unten ist eine hervorragende Wahl. \n Und wie dick soll dein Muster pro Seite sein?: \n ", &teppich.anzahl_reihen_teppich_rand);
	scanf("%d", &teppich.dicke_teppich_muster);
	te


	return teppich;
}





int main() {

	Teppich teppich;

	printf("Bitte gib die Länge und Breite deines Teppichs in ganzen Zahlen in dem Format: Länge Breite ein: \n");
	scanf("%d %d", &teppich.teppich_laenge, &teppich_breite);
	printf("Und wie dick hättest du den Rand gerne?: \n");
	scanf("%d", &anzahl_reihen_teppich_rand);
	anzahl_reihen_teppich_muster = teppich_laenge - (2 * anzahl_reihen_teppich_rand);
	printf("Und wie dick hättest du dein Muster gerne pro Seite?: \n");
	scanf("%d", &dicke_teppich_muster);
	leerzeichen_teppich = teppich_breite - (2 * dicke_teppich_muster);
	if (leerzeichen_teppich < 0) {
		printf("Bitte gib die Breite des Musters pro seite erneut ein, denn sie Überschreitet die Gesamtbreite %d deines Teppichs: \n", teppich_breite);
		scanf("%d", &dicke_teppich_muster);
		leerzeichen_teppich = teppich_breite - (2 * dicke_teppich_muster);
	}

	void rand_funktion()
	{
		for (int local_rand_counter = anzahl_reihen_teppich_rand; local_rand_counter > 0; local_rand_counter--)
		{
			for (int local_breite_counter = teppich_breite; local_breite_counter > 0; local_breite_counter--)
			{
				printf("*");
				if (local_breite_counter == 1)
				{
					printf("\n");
				}
			}
		}
	}

	void muster_befueller()
	{
		for (int local_dicke_counter = dicke_teppich_muster; local_dicke_counter > 0; local_dicke_counter--)
		{
			printf("*");
		}
	}

	void leerzeichen_befueller()
	{
		for (int local_leerzeichen_counter = leerzeichen_teppich; local_leerzeichen_counter > 0; local_leerzeichen_counter--)
		{
			printf(" ");
		}
	}

	rand_funktion();
	for (int local_reihen_counter = 3 * anzahl_reihen_teppich_muster; local_reihen_counter > 0; local_reihen_counter = local_reihen_counter - 3)
	{
		muster_befueller();
		leerzeichen_befueller();
		muster_befueller();
		printf("\n");
	}
	rand_funktion();
	return 0;
}