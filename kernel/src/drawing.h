#ifndef DRAWING_H_INCLUDED
#define DRAWING_H_INCLUDED





#include "superheader.h"






void KiDrawRect(int x, int y, int height, int width, uint8_t color[3]);
void KiDrawCharacter(int x, int y, int size, char c, uint8_t color[3]);
void KiDrawText(int x, int y, char* s, int size, uint8_t color[3]);

#endif