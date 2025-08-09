#include "grid.h"
#include "font.h"
#include "utils.h"
#include <ctype.h>

void drawRuler(SDL_Surface *surface, Uint32 color, int gap) {

  SDL_Rect lineY = {26, 0, 2, HEIGHT};
  SDL_FillRect(surface, &lineY, color);

  SDL_Rect lineX = {0, HEIGHT - 20, WIDTH, 2};
  SDL_FillRect(surface, &lineX, color);


  int l = (HEIGHT - 20) / gap;
  Text num = createText("res/dina.ttf", 15, 0, 0, 255);
  int x = 18;
  int y = gap;

  for (int i = 0; i < l - 1; i++) 
  {
    SDL_Rect subLine = {x, y, 8, 2};
    SDL_FillRect(surface, &subLine, color);

    char number[3];
    i_toa((l-1)-i, number);

    initText(&num,surface,number,1,y-3);

    y += gap;
  }

    int lx = 46;
    int ly = 20;

    for(int i = 0;i < (WIDTH-26)/GAP;i++)
    {
        SDL_Rect line;

        if(i % 2 == 0)
            line = (SDL_Rect){.x=lx,.y=0,.w=1,.h=HEIGHT-20};
        else
            line = (SDL_Rect){.x=lx,.y=0,.w=2,.h=HEIGHT-20};

        SDL_FillRect(surface,&line,GREY);

        lx += GAP;
    }

    for(int i = 0;i < (HEIGHT-20)/GAP;i++)
    {
        SDL_Rect line;

        if(i % 2 == 0)
            line = (SDL_Rect){.x=28,.y=ly,.w=WIDTH-26,.h=1};
        else
            line = (SDL_Rect){.x=28,.y=ly,.w=WIDTH-26,.h=2};

        SDL_FillRect(surface,&line,GREY);

        ly += GAP;
    }



}
