#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <raylib.h>
#include "utils.c"

#define WIDTH  600
#define HEIGHT  600

int main(){
	InitWindow(WIDTH,HEIGHT,"Hello");
	SetTargetFPS(60);
  
  FILE *ffmpeg = popen("ffmpeg -y -f rawvideo -pixel_format rgb24 -video_size 600x600  -framerate 60 -i - -c:v libx264 -pix_fmt yuv420p output.mp4", "w");
  if (!ffmpeg) {
     CloseWindow();
      return 1;
   }
  unsigned char *frameData = malloc(WIDTH * HEIGHT * 3);
  double xf,yf;
  xf = 200;
  yf =200;
	while(!WindowShouldClose()){
		BeginDrawing();
		double length;
		length = 600.0;
		Vector2 cirpose= GetMousePosition();
		Vector2 fixcirpose = {xf,yf};
    xf += (double)rand()/RAND_MAX*10-5;//rand()%(uper - low +1)+low
    yf += (double)rand()/RAND_MAX*10-5;
		ClearBackground(BLACK);
		DrawCircleV(cirpose,50,BLUE);
		DrawCircleV(fixcirpose,50,RED);
		for (double i =0.02;i < 2*M_PI;i+= 0.02){
			Vector2 endpose = {cirpose.x+ length*cos(i),cirpose.y+ length*sin(i)};
			double mm =m(endpose,cirpose);
      char theta[9];
      sprintf(theta,"%f",i);
      intern  cd = intersec(fixcirpose,50.0,mm , c(cirpose,mm));
      if (cd.cond){
        Vector2 end = mind(cirpose,cd.a,cd.b);
        if ((dis(endpose,end) > length) ||  (dis(cirpose,end) > length)){
          DrawLineV(cirpose,endpose,YELLOW);
        }else{
          DrawLineV(cirpose,end,YELLOW);
        }
      }else{
        DrawLineV(cirpose,endpose,YELLOW);
      }
		}
		EndDrawing();
    Image screenshot = LoadImageFromScreen();
    ImageFormat(&screenshot, PIXELFORMAT_UNCOMPRESSED_R8G8B8);    
    memcpy(frameData, screenshot.data, WIDTH *HEIGHT * 3);                            
    fwrite(frameData, 1, WIDTH * HEIGHT * 3, ffmpeg);                                    
    UnloadImage(screenshot);  
  }
  free(frameData);                           
  pclose(ffmpeg);
	CloseWindow();
	return 0;
}


	
