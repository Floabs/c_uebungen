#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "structs.h"

static Produkt private_produkt_befueller(const char* name, float brutto_stueckpreis, float packungsgroesse_1, float packungsgroesse_2) {
    Produkt produkt;
    produkt.bedarf = 0;
    produkt.name = malloc(strlen(name) + 1);
    strcpy(produkt.name, name);
    produkt.brutto_stueck_preis = brutto_stueckpreis;
    produkt.packungsgroesse[0] = packungsgroesse_1;
    produkt.packungsgroesse[1] = packungsgroesse_2;
    return produkt;
    
}

void delete_produkt(Produkt* produkt) {
    free(produkt->name); produkt->name = NULL;
}

static Produkt brutto_netto_gesamt(Produkt produkt) {
    produkt.netto_stueck_preis = produkt.brutto_stueck_preis * 1.2f;
    produkt.brutto_gesamt_preis = produkt.bedarf * produkt.brutto_stueck_preis;
    produkt.netto_gesamt_preis = produkt.brutto_gesamt_preis * 1.2f;
    return produkt;
}

int listen_befueller(Produkt gegenstands_liste[MAX_LENGTH])
{
    //char* name = malloc(100);
    char name[100];
    strcpy(name, "Eier");
    int produkt_counter = 0; 
    gegenstands_liste[produkt_counter++] = private_produkt_befueller(name, 0.3f, 6, 10);
    gegenstands_liste[produkt_counter++] = private_produkt_befueller("Reis", 1.93f, 1, 1);
    gegenstands_liste[produkt_counter++] = private_produkt_befueller("Hummus", 4.98f, 0.25f, 0.25f);
    gegenstands_liste[produkt_counter++] = private_produkt_befueller("Vollkorntortillia", 6.41f, 0.32f, 0.32f);
    gegenstands_liste[produkt_counter++] = private_produkt_befueller("Bierflasche", 0.94f, 1, 1);
    return produkt_counter;
}

float eingabewert(Produkt produkt) {
    float rest, kleinstes_vielfaches, bestellte_verpackungen = 0;
    char runder = '0';
    printf("Bitte gib die Anzahl/KG an %s ein, die du kaufen m�chtest ein : ", produkt.name);
    int eingelesene_werte = scanf("%f", &bestellte_verpackungen);
    rest = fmodf(bestellte_verpackungen, produkt.packungsgroesse[0]);
    kleinstes_vielfaches = rest;
    if (rest != 0.0) {
        for (int j = 0; j < 100 && rest != 0.0; j++) {
            for (int i = 0; i < 100 && rest != 0.0; i++) {
                rest = produkt.packungsgroesse[0] * i + produkt.packungsgroesse[1] * j;
                rest = fmodf(bestellte_verpackungen, rest);
                if (rest < kleinstes_vielfaches) {
                    kleinstes_vielfaches = rest;
                }
            }
        }
        if (rest != 0.0) {
            printf("Die Packungsgroessen betragen nur %0.3f oder %0.3f fuer dieses Produkt: soll ich aufrunden oder abrunden?: (+/-)\n", produkt.packungsgroesse[0], produkt.packungsgroesse[1]);
            while (runder != '+' && runder != '-') {
                runder = getchar();
            }
            if (runder == '+') {
                bestellte_verpackungen = bestellte_verpackungen - kleinstes_vielfaches + produkt.packungsgroesse[0];
            }
            if (runder == '-') {
                bestellte_verpackungen = bestellte_verpackungen - kleinstes_vielfaches;
            }
        }
    }
    return bestellte_verpackungen;
}
