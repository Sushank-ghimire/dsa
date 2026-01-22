#include <graphics.h>
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);
}

int main() {
  int x1, y1, x2, y2, x3, y3;
  float angle;

  printf("Enter coordinates of triangle:\n");
  printf("Point 1 (x1 y1): ");
  scanf("%d %d", &x1, &y1);

  printf("Point 2 (x2 y2): ");
  scanf("%d %d", &x2, &y2);

  printf("Point 3 (x3 y3): ");
  scanf("%d %d", &x3, &y3);

  printf("Enter rotation angle (in degrees): ");
  scanf("%f", &angle);

  /* Convert angle to radians */
  float rad = angle * PI / 180.0;

  /* Rotate points about origin */
  int x1r = (int)(x1 * cos(rad) - y1 * sin(rad));
  int y1r = (int)(x1 * sin(rad) + y1 * cos(rad));

  int x2r = (int)(x2 * cos(rad) - y2 * sin(rad));
  int y2r = (int)(x2 * sin(rad) + y2 * cos(rad));

  int x3r = (int)(x3 * cos(rad) - y3 * sin(rad));
  int y3r = (int)(x3 * sin(rad) + y3 * cos(rad));

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  setbkcolor(BLACK);

  /* Draw original triangle (WHITE) */
  setcolor(WHITE);
  drawTriangle(x1, y1, x2, y2, x3, y3);

  /* Draw rotated triangle (GREEN) */
  setcolor(GREEN);
  drawTriangle(x1r, y1r, x2r, y2r, x3r, y3r);

  getchar();
  closegraph();

  return 0;
}
