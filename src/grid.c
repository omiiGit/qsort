#include "grid.h"

void drawRuler(Text* num,SDL_Surface *surface, Uint32 color, int gap) {

  SDL_Rect lineY = {26, 0, 2, HEIGHT};
  SDL_FillRect(surface, &lineY, color);

  SDL_Rect lineX = {0, HEIGHT - 20, WIDTH, 2};
  SDL_FillRect(surface, &lineX, color);


  int l = (HEIGHT - 20) / gap;
  //Text num = createText("res/dina.ttf", 15, 0, 0, 255);
  int x = 18;
  int y = gap;

  for (int i = 0; i < l - 1; i++) 
  {
    SDL_Rect subLine = {x, y, 8, 2};
    SDL_FillRect(surface, &subLine, color);

    char number[3];
    i_toa((l-1)-i, number);

    initText(num,surface,number,1,y-3);

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

void drawBar(SDL_Surface* surface,Uint32 color,int height,int column)
{
    SDL_Rect bar = {column*GAP+26,(18 - height)*GAP+20,BAR_WIDTH+2,height*GAP};

    SDL_FillRect(surface,&bar,color);
}

void drawBars(SDL_Surface* surface,int arr[],int size,int j)
{
    for(int i = 0,col = 1;i < size;i++,col += 2)
    {
        //drawBar(surface,SDL_MapRGB(surface->format,getRandom(0,255),getRandom(0,255),getRandom(0,255)),arr[i],col);
        if(i == j)
            drawBar(surface,SDL_MapRGB(surface->format,0,255,0),arr[i],col);
        else
          drawBar(surface,SDL_MapRGB(surface->format,255,0,0),arr[i],col);
    }
}
