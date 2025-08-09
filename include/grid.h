#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include "Constant.h"
#include "font.h"

void drawRuler(SDL_Surface* surface,Uint32 color,int gap);
void drawBar(SDL_Surface* surface,Uint32 color,int width);

#endif 
