#include "window.h"

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

    state->font = createText("res/dina.ttf", 15, 0, 0, 255);

    //SDL_FillRect(state->buffer_surface,NULL,WHITE);
    //drawRuler(state->buffer_surface,RED,GAP);

}

void updateState(State* state)
{
    bool quit = false;
    SDL_Event event;
    int arr[ARR_SIZE];
    //Text num = createText("res/dina.ttf", 15, 0, 0, 255);

    
    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT: quit = true; break;
            }
        }
    
        for(int i = 0;i < ARR_SIZE;i++)
        {   
            arr[i] = getRandom(18,1);
        }

        SDL_FillRect(state->buffer_surface,NULL,WHITE);

        drawRuler(&state->font,state->buffer_surface,RED,GAP);

        drawBars(state->buffer_surface,arr,ARR_SIZE,0);


        updateStateSurface(state); 

        SDL_Delay(100);

        quicksort(arr,ARR_SIZE,state);

    }
}

void closeState(State* state)
{
    SDL_FreeSurface(state->current_surface);
    SDL_FreeSurface(state->buffer_surface);

    SDL_DestroyWindow(state->window);

    SDL_Quit();
}

static void qos(int arr[],int l,int r,State* state)
{
    if(r > l)
    {
        int pivot = arr[r];
        int i = l - 1;
        int j = r;
        int temp;

        while(1)
        {
            while(arr[++i] < pivot);
            while(arr[--j] > pivot);

            if(i >= j) break;

            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
        
        temp = arr[i]; arr[i] = arr[r]; arr[r] = temp;

        SDL_FillRect(state->buffer_surface,NULL,WHITE);
        drawRuler(&state->font,state->buffer_surface,RED,GAP);
        drawBars(state->buffer_surface,arr,ARR_SIZE,i);

        updateStateSurface(state);
        SDL_Delay(100);

        qos(arr,i+1,r,state);
        qos(arr,l,i-1,state);
    }
}

void quicksort(int arr[],int len,State* state)
{
    qos(arr,0,len-1,state);
}
