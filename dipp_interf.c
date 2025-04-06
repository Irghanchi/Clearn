#include "raylib.h"
#include <math.h>

#define MAX_CIRCLES 8
#define GROWTH_SPEED 0.8f

typedef struct {
    Vector2 position;
    float radius;
    bool growing;
} Circle;

int main(void) {
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Growing Circles Pattern");

    Circle circles[MAX_CIRCLES] = {
        {{50, 200}, 5.0f, true},  // Top initial circle
        {{50, 400}, 5.0f, true}    // Bottom initial circle
    };
    int circleCount = 2;
    bool phase2 = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update circle radii
        for (int i = 0; i < circleCount; i++) {
            if (circles[i].growing) {
                circles[i].radius += GROWTH_SPEED;
                if (circles[i].radius >= 100) {
                    circles[i].radius = 100;
                    circles[i].growing = false;
                }
            }
        }

        // Spawn new circles when initial ones reach full size
        if (!phase2 && circles[0].radius >= 100 && circles[1].radius >= 100) {
            phase2 = true;
            const float angles[] = {45.0f, 0.0f, -45.0f};

            for (int i = 0; i < 2; i++) {  // For each original circle
                Vector2 basePos = circles[i].position;
                for (int j = 0; j < 3; j++) {  // Create 3 new circles
                    float radian = angles[j] * DEG2RAD;
                    Vector2 newPos = {
                        basePos.x + cosf(radian) * 100,
                        basePos.y + sinf(radian) * 100
                    };
                    if (circleCount < MAX_CIRCLES) {
                        circles[circleCount++] = (Circle){newPos, 5.0f, true};
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw all circle outlines
        for (int i = 0; i < circleCount; i++) {
            DrawCircleLinesV(circles[i].position, circles[i].radius, BLACK);
        }

        // Calculate and draw intersection points
        for (int i = 0; i < circleCount; i++) {
            for (int j = i + 1; j < circleCount; j++) {
                Vector2 c1 = circles[i].position;
                Vector2 c2 = circles[j].position;
                float r1 = circles[i].radius;
                float r2 = circles[j].radius;

                float dx = c2.x - c1.x;
                float dy = c2.y - c1.y;
                float d = sqrtf(dx*dx + dy*dy);

                if (d > 0 && d <= (r1 + r2) && d >= fabsf(r1 - r2)) {
                    // Intersection calculation
                    float a = (r1*r1 - r2*r2 + d*d) / (2*d);
                    float h = sqrtf(r1*r1 - a*a);

                    Vector2 p2 = {
                        c1.x + (dx * a)/d,
                        c1.y + (dy * a)/d
                    };

                    // Calculate intersection points
                    Vector2 intersections[2] = {
                        { p2.x - (dy * h)/d, p2.y + (dx * h)/d },
                        { p2.x + (dy * h)/d, p2.y - (dx * h)/d }
                    };

                    // Draw both intersection points
                    DrawPixelV(intersections[0], RED);
                    DrawPixelV(intersections[1], RED);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
