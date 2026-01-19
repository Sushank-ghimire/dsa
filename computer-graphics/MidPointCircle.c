#include <graphics.h>
#include <stdio.h>

void drawCircle(int xc, int yc, int r) {
  int x = 0;
  int y = r;
  int d = 1 - r;

  while (x <= y) {
    // Draw 8 symmetric points
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);

    if (d < 0) {
      d += 2 * x + 3;
    } else {
      d += 2 * (x - y) + 5;
      y--;
    }
    x++;
  }
}

int main() {
  int gd = DETECT, gm;
  int xc, yc, r;

  printf("Enter circle center (xc yc): ");
  scanf("%d %d", &xc, &yc);

  printf("Enter radius r: ");
  scanf("%d", &r);

  initgraph(&gd, &gm, "");

  drawCircle(xc, yc, r);

  getch();
  closegraph();

  return 0;
}
