// pyramide.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
#include "pyramide.h"

void main(void)
{
    DrawingState drawingstate = create_drawingstate();

    for (int zeile = 0; zeile < 5; zeile++)
    {
        zeilen_schreiber(drawingstate);
        drawingstate = prepare_next_line(drawingstate);
        // drawingstate  = f(drawingstate)
        //  f(drawingstate) = input_copy_verändert_zu_aktuell
    }
}