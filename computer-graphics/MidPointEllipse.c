#include <graphics.h>
#include <stdio.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
  int x = 0;
  int y = ry;

  long rxSq = rx * rx;
  long rySq = ry * ry;

  long dx = 2 * rySq * x;
  long dy = 2 * rxSq * y;

  // Region 1
  long d1 = rySq - (rxSq * ry) + (rxSq / 4);
  while (dx < dy) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    if (d1 < 0) {
      x++;
      dx += 2 * rySq;
      d1 += dx + rySq;
    } else {
      x++;
      y--;
      dx += 2 * rySq;
      dy -= 2 * rxSq;
      d1 += dx - dy + rySq;
    }
  }

  // Region 2
  long d2 = (rySq) * ((x + 0.5) * (x + 0.5)) + (rxSq) * ((y - 1) * (y - 1)) - (rxSq * rySq);
  while (y >= 0) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    if (d2 > 0) {
      y--;
      dy -= 2 * rxSq;
      d2 += rxSq - dy;
    } else {
      y--;
      x++;
      dx += 2 * rySq;
      dy -= 2 * rxSq;
      d2 += dx - dy + rxSq;
    }
  }
}

int main() {
  int gd = DETECT, gm;
  int xc, yc, rx, ry;

  printf("Enter ellipse center (xc yc): ");
  scanf("%d %d", &xc, &yc);

  printf("Enter ellipse radii (rx ry): ");
  scanf("%d %d", &rx, &ry);

  initgraph(&gd, &gm, "");

  drawEllipse(xc, yc, rx, ry);

  getchar();
  closegraph();

  return 0;
}
