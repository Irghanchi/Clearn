#include "raylib.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define FRAME_COUNT 300  // 10 seconds at 30 FPS
void test();

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Raylib FFmpeg Streaming");

    // Open FFmpeg process for writing raw frames
    FILE *ffmpeg = popen("ffmpeg -y -f rawvideo -pixel_format rgb24 -video_size 800x600 -framerate 30 -i - -c:v libx264 -pix_fmt yuv420p output.mp4", "w");
    if (!ffmpeg) {
        CloseWindow();
        return 1;
    }

    unsigned char *frameData = malloc(WIDTH * HEIGHT * 3);  // Allocate memory for RGB24 frame

    for (int i = 0; i < FRAME_COUNT; i++) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(WIDTH / 2 + (i % 200), HEIGHT / 2, 50, RED);
       // DrawText("Raylib Streaming to FFmpeg", 10, 10, 20, WHITE);

        EndDrawing();

        // Get pixel data and send to FFmpeg
        Image screenshot = LoadImageFromScreen();
        ImageFormat(&screenshot, PIXELFORMAT_UNCOMPRESSED_R8G8B8);
        memcpy(frameData, screenshot.data, WIDTH * HEIGHT * 3);
        fwrite(frameData, 1, WIDTH * HEIGHT * 3, ffmpeg);
        UnloadImage(screenshot);
    }

    free(frameData);
    pclose(ffmpeg);
    CloseWindow();

    return 0;
}
