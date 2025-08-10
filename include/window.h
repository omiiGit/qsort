#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include "grid.h"
#include "Constant.h"
#include "stdbool.h"

typedef struct 
{
    int width;
    int height;
    int arr[8];

    const char* title;
    Text font;
    SDL_Window* window;
    SDL_Surface* current_surface;
    SDL_Surface* buffer_surface;
}State;

State createState(const char* title,int width,int height);
void initState(State* state);
void updateState(State* state);
void closeState(State* state);

void updateStateSurface(State* state);

static void qos(int arr[],int l,int r,State* state);
void quicksort(int arr[],int len,State* state);
#endif 
