#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main (void){
    int c, nwhite, nletter, nother, ndigit;
    nwhite = c = nletter = nother = ndigit = 0;
    while ((c = getchar()) != '!')
    {
        if (isdigit(c))
        ndigit++;
        else if (isalpha(c))
        nletter++;
        else if (isspace(c))
        nwhite++;
        else
        nother++;
    }
    printf("Statistik für den eingegebenen Text: \n");
    printf("%d Ziffern\n", ndigit);
    printf("%d Buchstaben\n", nletter);
    printf("%d Zwischenräume\n", nwhite);
    printf("%d andere Zeichen\n", nother);
    return EXIT_SUCCESS;
}