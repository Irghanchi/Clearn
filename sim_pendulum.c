
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#define WIDTH 600
#define HEIGHT 600 
#define FPS 60
#define K 1
int main()
{
	InitWindow(WIDTH,HEIGHT,"SimpPendulum");
	SetTargetFPS(FPS);
	double Length = 400;
	Vector2 v = {0,0};
	Vector2 g = {0,1};
	Vector2 Ball = {300+Length*cos(M_PI/3),Length*sin(M_PI/3)};
	Vector2 Anchor = {300,0};
	Vector2 pos = {0,0};
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		//Vector2 Anchor = {400,0};
		if (IsMouseButtonPressed(1)){
		Ball = GetMousePosition();
		v.x = 0;
		v.y = 0;
		}
		double x; 
		Vector2 force = Vector2Subtract(Ball,Anchor);

		x =Vector2Length(force) - Length;
		force = Vector2Normalize(force);
		pos = Vector2Scale(force, Length);
		pos = Vector2Add(pos, Anchor);

		force = Vector2Scale(force,-1*K*x);
		v =Vector2Add(force,v);
		v =  Vector2Add(v,g);
		Ball = Vector2Add(v,Ball);
		DrawCircleV(pos,50,BLUE);
		DrawLineV(Anchor,pos,BLACK);
		EndDrawing();
	
	}
	CloseWindow();
	return 0;
}



