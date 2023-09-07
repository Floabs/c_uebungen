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

int main() {


typedef struct Teppich Teppich;

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



return 0;
    }
