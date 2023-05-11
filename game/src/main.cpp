#include "rlImGui.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720



int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sunshine");
    SetTargetFPS(60);
    Vector2 ballPosition = { 100, 100 };

     
    
    while (!WindowShouldClose())
    {

        ballPosition = GetMousePosition();

        CheckCollisionCircles({ ballPosition }, 25.00, { 666,420 }, 35.00);
        

        ////////DRAW/////
        BeginDrawing();
        ClearBackground(GRAY);
        
       
       DrawCircleV(ballPosition, 25, PINK);


        DrawRectangleGradientH(150, 150, 80, 100, PINK, SKYBLUE);
        DrawRectangleGradientH(450, 450, 80, 100, PINK, SKYBLUE);
        DrawRectangleGradientH(150, 250, 80, 100, PINK, SKYBLUE);
        DrawRectangleGradientH(250, 350, 100, 115, PINK, SKYBLUE);

       
        DrawCircleGradient(666, 420, 35.00, BLACK, PINK);

        

        EndDrawing();


    }

    CloseWindow();
    return 0;
}