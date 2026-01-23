#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);
}

int main() {
  int x1, y1, x2, y2, x3, y3;
  float shx, shy;

  printf("Enter coordinates of triangle:\n");
  printf("Point 1 (x1 y1): ");
  scanf("%d %d", &x1, &y1);

  printf("Point 2 (x2 y2): ");
  scanf("%d %d", &x2, &y2);

  printf("Point 3 (x3 y3): ");
  scanf("%d %d", &x3, &y3);

  printf("Enter shearing factors (shx shy): ");
  scanf("%f %f", &shx, &shy);

  /* Sheared coordinates */
  int x1s = (int)(x1 + shx * y1);
  int y1s = (int)(y1 + shy * x1);

  int x2s = (int)(x2 + shx * y2);
  int y2s = (int)(y2 + shy * x2);

  int x3s = (int)(x3 + shx * y3);
  int y3s = (int)(y3 + shy * x3);

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  /* Clear screen (BLACK) */
  setbkcolor(BLACK);

  /* Original triangle (WHITE) */
  setcolor(WHITE);
  drawTriangle(x1, y1, x2, y2, x3, y3);

  /* Sheared triangle (YELLOW) */
  setcolor(YELLOW);
  drawTriangle(x1s, y1s, x2s, y2s, x3s, y3s);

  getch();
  closegraph();

  return 0;
}
