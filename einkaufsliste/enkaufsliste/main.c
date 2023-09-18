#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structs.h"
#include "functions.h"

int main()
{
    float summe_gesamt_mwst = 0;
    float gesamtpreis_brutto = 0;
    float gesamtpreis_netto = 0;
    Produkt gegenstands_liste[MAX_LENGTH];
    int produkt_counter = listen_befueller(gegenstands_liste);
    for (int i = 0; i < produkt_counter; i++) {
        gegenstands_liste[i].bedarf = eingabewert(gegenstands_liste[i]);
        gegenstands_liste[i] = brutto_netto_gesamt(gegenstands_liste[i]);
    }
    /* 
    for (int i = 0;  i < 5 ; i++) {
        printf("%s \t\t\t %.02f Stueck \t %.02f Euro \t %.02f Euro \t %.02f Euro \t %.02f Euro\t  %.02f oder %.02f \n", gegenstands_liste[i].name, gegenstands_liste[i].bedarf, gegenstands_liste[i].brutto_stueck_preis, gegenstands_liste[i].netto_stueck_preis, gegenstands_liste[i].brutto_gesamt_preis, gegenstands_liste[i].netto_gesamt_preis, gegenstands_liste[i].packungsgroesse[0], gegenstands_liste[i].packungsgroesse[1]);
    }
    */
    for (int i = 0; i < produkt_counter; i++) {
        if (gegenstands_liste[i].bedarf != 0.0) {
            printf("%s \t\t\t %.02f Stueck \t %.02f Euro\t %.02f Euro \n", gegenstands_liste[i].name, gegenstands_liste[i].bedarf, gegenstands_liste[i].brutto_gesamt_preis, gegenstands_liste[i].netto_gesamt_preis);
            gesamtpreis_brutto = gesamtpreis_brutto + gegenstands_liste[i].brutto_gesamt_preis;
            gesamtpreis_netto = gesamtpreis_netto + gegenstands_liste[i].netto_gesamt_preis;
        }
    }
    summe_gesamt_mwst = gesamtpreis_netto - gesamtpreis_brutto;
    printf("Summe Gesamt (Netto): \t %.02f \nSumme Gesamt Mehrwertsteuer: \t %.02f \nSumme Gesamt (brutto):\t %.02f", gesamtpreis_netto, summe_gesamt_mwst, gesamtpreis_brutto );
    
   
    for (int i = 0; i < produkt_counter; i++) {
        delete_produkt(&gegenstands_liste[i]);
    }


    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();

    return 0;

}

