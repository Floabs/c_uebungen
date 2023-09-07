#pragma once
struct DrawingState
{
    int anzahl_auszugebender_leerzeichen_vorne;
    int anzahl_auszugebender_sterne;
};
typedef struct DrawingState DrawingState;
void zeilen_schreiber(DrawingState drawingstate);
DrawingState prepare_next_line(DrawingState drawingstate);
DrawingState create_drawingstate();
