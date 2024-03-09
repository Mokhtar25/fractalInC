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

    const float zoomSpeed = 1.0001f;
    const float moveSpeed = 0.01f;

    // range of cord
    Rectangle mandelbrotRect = {-2.0f, -1.0f, 3.0f, 2.0f};

    float x = 0;
    float y = 0;
    float x0 = 0;
    float y0 = 0;
    float xtemp = 0;
    int iter = 0;
    const int escape = 4;

    while (!WindowShouldClose())
    {
        Vector2 mousep = GetMousePosition();

        // mouse zoom in and out
        mandelbrotRect.width *= !IsMouseButtonDown(MOUSE_BUTTON_RIGHT) ? zoomSpeed : 1.01f / zoomSpeed;
        mandelbrotRect.height *= !IsMouseButtonDown(MOUSE_BUTTON_RIGHT) ? zoomSpeed : 1.01f / zoomSpeed;

      

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
        if (mousep.y > HEIGHT/2 + 50)
        {
            mandelbrotRect.y -=  moveSpeed * mandelbrotRect.height;
        }
        else if (mousep.y < HEIGHT / 2 - 50){
            mandelbrotRect.y += moveSpeed * mandelbrotRect.height;
        }
        if (mousep.x > WIDTH / 2 + 50) 
            mandelbrotRect.x -=  (moveSpeed * mandelbrotRect.height) ; 
        else if ( mousep.x < WIDTH / 2 - 50)
            mandelbrotRect.x +=  moveSpeed * mandelbrotRect.height; 

        
        mandelbrotRect.width /= !IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? zoomSpeed : 1.01f * zoomSpeed;
        mandelbrotRect.height /= !IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? zoomSpeed : 1.01f * zoomSpeed; 

        }
        

        // draw
        BeginDrawing();
        ClearBackground(GRAY);

        for (int px = 0; px < WIDTH; px++)
        {
            for (int py = 0; py < HEIGHT; py++)
            {

                float x0 = mandelbrotRect.x + (float)px / WIDTH * mandelbrotRect.width;
                float y0 = mandelbrotRect.y + (float)py / HEIGHT * mandelbrotRect.height;

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
