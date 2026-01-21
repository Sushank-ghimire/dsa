#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);
}

int main() {
  int x1, y1, x2, y2, x3, y3;

  printf("Enter coordinates of triangle:\n");
  printf("Point 1 (x1 y1): ");
  scanf("%d %d", &x1, &y1);

  printf("Point 2 (x2 y2): ");
  scanf("%d %d", &x2, &y2);

  printf("Point 3 (x3 y3): ");
  scanf("%d %d", &x3, &y3);

  /* Reflection about X-axis */
  int x1r = x1;
  int y1r = -y1;

  int x2r = x2;
  int y2r = -y2;

  int x3r = x3;
  int y3r = -y3;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  /* Original triangle (WHITE) */
  setcolor(WHITE);
  drawTriangle(x1, y1, x2, y2, x3, y3);

  /* Reflected triangle (GREEN) */
  setcolor(GREEN);
  drawTriangle(x1r, y1r, x2r, y2r, x3r, y3r);

  getchar();
  closegraph();

  return 0;
}
