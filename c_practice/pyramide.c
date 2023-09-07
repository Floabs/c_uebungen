/*
Programm zur Ausgabe eines Dreiecks.
Das Spielfeld ist 9 Zeichen breit

 012345678
0    *
1   ***
2  *****
3 *******
4*********
5
6
7
8

    *
   ***
  *****
 *******
*********


*/

#include <stdio.h>
#include <stdlib.h>

void zeilen_schreiber(int anzahl_auszugebender_leerzeichen_vorne, int anzahl_auszugebender_sterne)
{
    char leerzeichen = ' ';
    char stern = '*';

    for (int i = anzahl_auszugebender_leerzeichen_vorne; i > 0; i--)
    {
        printf("%c", leerzeichen);
    }

    for (int i = anzahl_auszugebender_sterne; i > 0; i--)
    {
        printf("%c", stern);
    }
    printf("\n");
}

void prepare_next_line(int *p_anzahl_auszugebender_leerzeichen, int *p_anzahl_auszugebender_sterne)
{
    *p_anzahl_auszugebender_leerzeichen = *p_anzahl_auszugebender_leerzeichen - 1;
    *p_anzahl_auszugebender_sterne = *p_anzahl_auszugebender_sterne + 2;
}

void main(void)
{
    int anzahl_auszugebender_leerzeichen_vorne = 4;
    int anzahl_auszugebender_sterne = 1;

    for (int zeile = 0; zeile < 5; zeile++)
    {
        zeilen_schreiber(anzahl_auszugebender_leerzeichen_vorne, anzahl_auszugebender_sterne);
        prepare_next_line(&anzahl_auszugebender_leerzeichen_vorne, &anzahl_auszugebender_sterne);
    }
}