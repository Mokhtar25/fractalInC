#include <raylib.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATION 80

int main()
{

    InitWindow(WIDTH, HEIGHT, "Mandelbrot set");
    SetTargetFPS(40);


    const float zoomSpeed = 1.0001f;
    const float moveSpeed = 0.014f;
    const float zoom_speed_moving = 1.01f;

    // range of cord
    Rectangle mandelbrotRect = {-2.0f, -1.0f, 3.0f, 2.0f};

    float x = 0;
    float y = 0;
    float x0 = 0;
    float y0 = 0;
    float xtemp = 0;
    int iter = 0;
    const int escape = 4;
    const int buffer = 50;

    while (!WindowShouldClose())
    {
        Vector2 mousep = GetMousePosition();

        // mouse zoom in 
        mandelbrotRect.width *= !IsMouseButtonDown(MOUSE_BUTTON_RIGHT) ? zoomSpeed : zoom_speed_moving / zoomSpeed;
        mandelbrotRect.height *= !IsMouseButtonDown(MOUSE_BUTTON_RIGHT) ? zoomSpeed : zoom_speed_moving / zoomSpeed;

      
        //mouse zoom out and movement 
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            // adding buffer as a puffer to middle of the screen
        if (mousep.y > HEIGHT/2 + buffer)
        {
            mandelbrotRect.y -=  moveSpeed * mandelbrotRect.height;
        }
        else if (mousep.y < HEIGHT/2 - buffer ){
            mandelbrotRect.y += moveSpeed * mandelbrotRect.height;
        }
        if (mousep.x > WIDTH / 2 + buffer)
            mandelbrotRect.x -=  (moveSpeed * mandelbrotRect.height) ; 
        else if ( mousep.x < WIDTH/2 - buffer)
            mandelbrotRect.x +=  moveSpeed * mandelbrotRect.height; 

        // mouse zoom out
        mandelbrotRect.width /= !IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? zoomSpeed :zoom_speed_moving * zoomSpeed;
        mandelbrotRect.height /= !IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? zoomSpeed : zoom_speed_moving* zoomSpeed; 

        }
        

        
        BeginDrawing();
        ClearBackground(GRAY);

        //getting every pixel in the screen
        for (int px = 0; px < WIDTH; px++)
        {
            for (int py = 0; py < HEIGHT; py++)
            {
                // mandelbrot set
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
                    // color changing
                    srand(time(NULL));
                    int rs = rand();
                    int r = 150;
                    int g = (100 * iter / MAX_ITERATION);
                    int b = 50 * iter / MAX_ITERATION;
                    color = (Color){r, g, b, 255};
                }

                DrawPixel(px, py, color);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
