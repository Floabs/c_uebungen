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

int leerzeichen_counter = 4;
int sterne_counter = 1;

void befueller() {
    char leerzeichen = ' ';
    char stern = '*';


    while (leerzeichen_counter > 0)
    {
        printf("%c", leerzeichen);
        leerzeichen_counter--;
    }

    while (sterne_counter > 0)
    {
        printf("%c", stern);
        sterne_counter--;
    }
    

}

void new_line() {
leerzeichen_counter--;
sterne_counter = sterne_counter + 2;
printf("\n");

}

void main (void) {

    for (int zeile = 0; zeile < 5; zeile++) {
        befueller();
        new_line();

    }
}