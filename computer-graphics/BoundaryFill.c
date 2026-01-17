#include <graphics.h>
#include <stdio.h>

void boundaryFill(int x, int y, int boundaryColor, int fillColor) {
  int currentColor = getpixel(x, y);

  if (currentColor == boundaryColor || currentColor == fillColor)
    return;

  putpixel(x, y, fillColor);

  boundaryFill(x + 1, y, boundaryColor, fillColor);
  boundaryFill(x - 1, y, boundaryColor, fillColor);
  boundaryFill(x, y + 1, boundaryColor, fillColor);
  boundaryFill(x, y - 1, boundaryColor, fillColor);
}

int main() {
  int gd = DETECT, gm;

  initgraph(&gd, &gm, "");

  setbkcolor(WHITE);

  setcolor(BLACK);
  rectangle(200, 150, 600, 450);

  boundaryFill(300, 300, BLACK, BLUE);

  getchar();
  closegraph();

  return 0;
}
