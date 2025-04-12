#include "ll.c"
#include <raylib.h>
#include <stdio.h>

#define WIDTH 600
#define HEIGHT 600

int main() {
  InitWindow(WIDTH, HEIGHT, "GUN");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    Vector2 pos = {0, 250};
    Vector2 size = {50, 50};
    DrawRectangleV(pos, size, YELLOW);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
