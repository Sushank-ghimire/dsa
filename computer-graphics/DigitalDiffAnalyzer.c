#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void drawDDA(int x1, int y1, int x2, int y2) {
  int dx = x2 - x1;
  int dy = y2 - y1;

  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  float xInc = dx / (float)steps;
  float yInc = dy / (float)steps;

  float x = x1;
  float y = y1;

  for (int i = 0; i <= steps; i++) {
    putpixel((int)round(x), (int)round(y), WHITE);
    x += xInc;
    y += yInc;
  }
}

int main() {
  int gd = DETECT, gm;
  int x1, y1, x2, y2;

  printf("Enter first point (x1 y1): ");
  scanf("%d %d", &x1, &y1);

  printf("Enter second point (x2 y2): ");
  scanf("%d %d", &x2, &y2);

  initgraph(&gd, &gm, "");

  drawDDA(x1, y1, x2, y2);

  getchar();
  closegraph();
  return 0;
}
