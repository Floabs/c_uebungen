#include <stdio.h>
#include "pyramide.h"

void zeilen_schreiber(DrawingState drawingstate)
{
    char leerzeichen = ' ';
    char stern = '*';

    for (int i = drawingstate.anzahl_auszugebender_leerzeichen_vorne; i > 0; i--)
    {
        printf("%c", leerzeichen);
    }

    for (int i = drawingstate.anzahl_auszugebender_sterne; i > 0; i--)
    {
        printf("%c", stern);
    }
    printf("\n");
}

/*
void prepare_next_line(DrawingState* p_drawingstate)
{
    (*p_drawingstate).anzahl_auszugebender_leerzeichen_vorne = (*p_drawingstate).anzahl_auszugebender_leerzeichen_vorne - 1;
    p_drawingstate->anzahl_auszugebender_sterne = p_drawingstate->anzahl_auszugebender_sterne + 2;
}
*/

DrawingState prepare_next_line(DrawingState drawingstate)
{
    drawingstate.anzahl_auszugebender_leerzeichen_vorne = drawingstate.anzahl_auszugebender_leerzeichen_vorne - 1;
    drawingstate.anzahl_auszugebender_sterne = drawingstate.anzahl_auszugebender_sterne + 2;
    return drawingstate;
}

DrawingState create_drawingstate()
{
    DrawingState drawingstate;
    drawingstate.anzahl_auszugebender_leerzeichen_vorne = 4;
    drawingstate.anzahl_auszugebender_sterne = 1;
    return drawingstate;
}