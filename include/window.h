#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include "Constant.h"
#include "stdbool.h"

typedef struct 
{
    int width;
    int height;

    const char* title;
    SDL_Window* window;
    SDL_Surface* current_surface;
    SDL_Surface* buffer_surface;
}State;

State createState(const char* title,int width,int height);
void initState(State* state);
void updateState(State* state);
void closeState(State* state);

void updateStateSurface(State* state);

#endif 
