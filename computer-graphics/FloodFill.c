#include <graphics.h>
#include <stdio.h>

void floodFill(int x, int y, int oldColor, int newColor) {
  int currentColor = getpixel(x, y);

  if (currentColor != oldColor)
    return;

  putpixel(x, y, newColor);

  floodFill(x + 1, y, oldColor, newColor);
  floodFill(x - 1, y, oldColor, newColor);
  floodFill(x, y + 1, oldColor, newColor);
  floodFill(x, y - 1, oldColor, newColor);
}

int main() {
  int gd = DETECT, gm;

  initgraph(&gd, &gm, "");

  setbkcolor(WHITE);
  cleardevice();

  setcolor(BLACK);
  rectangle(200, 150, 600, 450);

  floodFill(300, 300, WHITE, RED);

  getch();
  closegraph();

  return 0;
}
