#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *canvas = NULL;

Uint32 getPixel(int x, int y) {
  Uint32 *pixels = (Uint32 *)canvas->pixels;
  return pixels[y * WIDTH + x];
}

void setPixel(int x, int y, Uint32 color) {
  Uint32 *pixels = (Uint32 *)canvas->pixels;
  pixels[y * WIDTH + x] = color;
}

void boundaryFill(int x, int y, Uint32 boundaryColor, Uint32 fillColor)
{
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    return;

  Uint32 currentColor = getPixel(x, y);

  if (currentColor == boundaryColor || currentColor == fillColor)
    return;

  setPixel(x, y, fillColor);

  boundaryFill(x + 1, y, boundaryColor, fillColor);
  boundaryFill(x - 1, y, boundaryColor, fillColor);
  boundaryFill(x, y + 1, boundaryColor, fillColor);
  boundaryFill(x, y - 1, boundaryColor, fillColor);
}

int main()
{
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Boundary Fill - Sushank Ghimire", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

  renderer = SDL_CreateRenderer(window, -1, 0);

  canvas = SDL_CreateRGBSurfaceWithFormat(0, WIDTH, HEIGHT, 32, SDL_PIXELFORMAT_RGBA8888);

  /* White background */
  Uint32 white = SDL_MapRGB(canvas->format, 255, 255, 255);
  SDL_FillRect(canvas, NULL, white);

  /* Black boundary rectangle */
  Uint32 black = SDL_MapRGB(canvas->format, 0, 0, 0);

  SDL_Rect top    = {200, 150, 400, 2};
  SDL_Rect bottom = {200, 448, 400, 2};
  SDL_Rect left   = {200, 150, 2, 300};
  SDL_Rect right  = {598, 150, 2, 300};

  SDL_FillRect(canvas, &top, black);
  SDL_FillRect(canvas, &bottom, black);
  SDL_FillRect(canvas, &left, black);
  SDL_FillRect(canvas, &right, black);

  /* Boundary fill inside rectangle */
  Uint32 blue = SDL_MapRGB(canvas->format, 0, 0, 255);
  boundaryFill(300, 300, black, blue);

  /* Render to screen */
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, canvas);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  getchar();

  /* Screen Cleanup */
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(canvas);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
