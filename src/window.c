#include "window.h"
#include "grid.h"

State createState(const char* title,int width,int height)
{
    return(State)
    {
        .title = title,
        .width = width,
        .height = height,
        .window = NULL,
        .current_surface = NULL,
        .buffer_surface = NULL,
    };
}

void updateStateSurface(State* state)
{
  SDL_Surface* opt = SDL_ConvertSurface(state->buffer_surface,state->current_surface->format,0);

  SDL_BlitSurface(opt,NULL,state->current_surface,NULL);

  SDL_UpdateWindowSurface(state->window);

  SDL_FreeSurface(opt);
}

void initState(State* state)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    state->window = SDL_CreateWindow(
            state->title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            state->width,
            state->height,
            SDL_WINDOW_SHOWN
            );

    state->current_surface = SDL_GetWindowSurface(state->window);

    state->buffer_surface = SDL_CreateRGBSurface(0,WIDTH,HEIGHT,32,0,0,0,0);

    SDL_FillRect(state->buffer_surface,NULL,WHITE);
    drawRuler(state->buffer_surface,RED,GAP);

    updateStateSurface(state); 

}

void updateState(State* state)
{
    bool quit = false;
    SDL_Event event;

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT: quit = true; break;
            }
        }
    }
}

void closeState(State* state)
{
    SDL_FreeSurface(state->current_surface);
    SDL_FreeSurface(state->buffer_surface);

    SDL_DestroyWindow(state->window);

    SDL_Quit();
}


