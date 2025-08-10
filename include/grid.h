#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include "Constant.h"
#include "utils.h"
#include "font.h"

typedef struct 
{
    int x;
    int y;
}Vec2;

void drawRuler(Text* num,SDL_Surface* surface,Uint32 color,int gap);
void drawBar(SDL_Surface* surface,Uint32 color,int height,int column);
void drawBars(SDL_Surface* surface,int arr[],int size,int j);

#endif 
