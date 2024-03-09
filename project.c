#include <raylib.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATION 100

int main()
{

    InitWindow(WIDTH, HEIGHT, "Mandelbrot set");
    SetTargetFPS(30);

    Camera2D camera = {0};
    camera.offset = (Vector2){WIDTH / 2.0f, HEIGHT / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    const float zoomSpeed = 1.01f;

    float x = 0;
    float y = 0;
    float x0 = 0;
    float y0 = 0;
    float xtemp = 0;
    int iter = 0;
    const int escape = 4;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_A))
            camera.rotation--;
        else if (IsKeyDown(KEY_S))
            camera.rotation++;

        if (camera.rotation > 40)
            camera.rotation = 40;
        else if (camera.rotation < -40)
            camera.rotation = -40;

        camera.zoom *= IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? zoomSpeed : 1.0f / zoomSpeed;

        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }

        // draw
        BeginDrawing();
        ClearBackground(GRAY);

        for (int px = 0; px < WIDTH; px++)
        {
            for (int py = 0; py < HEIGHT; py++)
            {

                x0 = (float)px / WIDTH * 3.5 - 2.5;
                y0 = (float)py / HEIGHT * 2 - 1;

                x = 0;
                y = 0;
                iter = 0;

                while (x * x - y * y <= escape && iter < MAX_ITERATION)
                {
                    xtemp = x * x - y * y + x0;
                    y = 2 * x * y + y0;
                    x = xtemp;
                    iter++;
                }
                Color color;
                if (iter == MAX_ITERATION)
                {
                    color = BLACK;
                }

                else
                {
                    srand(time(NULL));
                    int r = rand();
                    float value = ((r * 13) * iter / MAX_ITERATION);
                    color = (Color){(255), 0, ((255 * iter / MAX_ITERATION)), 255};
                }

                DrawPixel(px, py, color);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
