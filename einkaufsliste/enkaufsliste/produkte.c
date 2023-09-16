#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structs.h"

Produkt private_produkt_befueller(const char* name, float brutto_stueckpreis, int packungsgroesse_1, int packungsgroesse_2) {
    Produkt produkt;
    produkt.bedarf = 0;
    produkt.name = name;
    produkt.brutto_stueck_preis = brutto_stueckpreis;
    produkt.packungsgroesse[0] = packungsgroesse_1;
    produkt.packungsgroesse[1] = packungsgroesse_2;
    return produkt;
    
}

//Produkt eier_befueller() {
  //  return private_produkt_befueller("Eier", 0.3, 6, 10);
// }

Produkt reis_befueller() {
    return private_produkt_befueller("Reis", 1.93, 1, 1);
}

Produkt hummus_befueller() {
    return private_produkt_befueller("Hummus", 4.98, 0.25, 0.25);
}

Produkt vollkorntortillia_befueller()
{
    return private_produkt_befueller("Vollkorntortillia", 6.41, 0.32, 0.32);
}

Produkt bierflaschen_befueller() {
    return private_produkt_befueller("Bierflasche", 0.94, 1, 1);
}

Produkt brutto_netto_gesamt(Produkt produkt) {
    produkt.netto_stueck_preis = produkt.brutto_stueck_preis * 1.2;
    produkt.brutto_gesamt_preis = produkt.bedarf * produkt.brutto_stueck_preis;
    produkt.netto_gesamt_preis = produkt.brutto_gesamt_preis * 1.2;
    return produkt;
}

void listen_befueller(Produkt gegenstands_liste[MAX_LENGTH])
{
    gegenstands_liste[0] = private_produkt_befueller("Eier", 0.3, 6, 10);
    gegenstands_liste[1] = reis_befueller();
    gegenstands_liste[2] = hummus_befueller();
    gegenstands_liste[3] = vollkorntortillia_befueller();
    gegenstands_liste[4] = bierflaschen_befueller();
}

float eingabewert(Produkt produkt) {
    float rest, kleinstes_vielfaches, bestellte_verpackungen = 0;
    char runder = '0';
    printf("Bitte gib die Anzahl/KG an %s ein, die du kaufen möchtest ein : ", produkt.name);
    scanf("%f", &bestellte_verpackungen);
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
