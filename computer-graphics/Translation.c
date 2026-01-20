#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);
}

int main() {
  int x1, y1, x2, y2, x3, y3;
  int tx, ty;

  printf("Enter coordinates of triangle:\n");
  printf("Point 1 (x1 y1): ");
  scanf("%d %d", &x1, &y1);

  printf("Point 2 (x2 y2): ");
  scanf("%d %d", &x2, &y2);

  printf("Point 3 (x3 y3): ");
  scanf("%d %d", &x3, &y3);

  printf("Enter translation factors (tx ty): ");
  scanf("%d %d", &tx, &ty);

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  /* Clear screen (BLACK) */
  setbkcolor(BLACK);

  /* Draw original triangle (WHITE) */
  setcolor(WHITE);
  drawTriangle(x1, y1, x2, y2, x3, y3);

  /* Translated coordinates */
  int x1t = x1 + tx;
  int y1t = y1 + ty;
  int x2t = x2 + tx;
  int y2t = y2 + ty;
  int x3t = x3 + tx;
  int y3t = y3 + ty;

  /* Draw translated triangle (RED) */
  setcolor(RED);
  drawTriangle(x1t, y1t, x2t, y2t, x3t, y3t);

  getch();
  closegraph();

  return 0;
}
