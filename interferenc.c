#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <raylib.h>
#include "utils.c"

#define WIDTH 600
#define HEIGHT 600
#define FPS 60

void 

int main(){
  InitWindow(WIDTH,HEIGHT,"IRFAN");
  SetTargetFPS(FPS);
  double radius = 50;
  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(WHITE);




    EndDrawing();
    radius += 2;
    if (radius > 400){
	    radius = 1;
    }
  }
  CloseWindow();
  return 0;
}



    
