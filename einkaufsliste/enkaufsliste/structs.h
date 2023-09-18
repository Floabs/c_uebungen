#pragma once
#define MAX_LENGTH 50


struct Produkt {
    char* name;
    float bedarf;
    float brutto_stueck_preis;
    float netto_stueck_preis;
    float brutto_gesamt_preis;
    float netto_gesamt_preis;
    float packungsgroesse[2];
};
typedef struct Produkt Produkt;

Produkt brutto_netto_gesamt(Produkt produkt);
int listen_befueller(Produkt gegenstands_liste[MAX_LENGTH]);
float eingabewert(Produkt produkt);
void delete_produkt(Produkt *produkt);
