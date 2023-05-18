// Teigesser, Jonathan Student ID#101463552

#include "rlImGui.h"
#include <vector>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

//Checklist for the lab compleation 
//Add collision with the circles
//Add 10 more functions from the raylib cheat sheet. 
//Make notation on the functions explaining them
// Make the video also


class Player
{
public:
    float x, y;
    float pCircleRadius = 25;
    Color circleColor1;
    Color circleColor2;
    

    void Draw()
    {
        DrawCircleGradient(x,y , pCircleRadius, circleColor1, circleColor2);
    }

};
//Goal Circle
class Circle
{
public:
    float x, y;
    float circleRadius = 35;
    Color circleColor1;
    Color circleColor2;
    
    void Draw()
    {
        DrawCircleGradient(x, y, circleRadius, circleColor1, circleColor2);
    }
};

class Line
{
public:
    

    float lineThickness = 5.0; 
    Color lineColour; 

    void DrawMazeLine()
    {
        DrawLineEx({0,0}, {0,0}, lineThickness, lineColour);
    }



};


//void playerColission(Player& player, Circle& circle)
//{
//    bool collision = false;
//    
//    
//        if (CheckCollisionCircles(Vector2{ player.x, player.y }, player.circleRadius, Vector2{ circle.x, circle.y }, circle.circleRadius))
//        {
//
//            //CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
//            player.circleColor1 = BLACK;
//            player.circleColor2 = RED;
//           
//        }
//
//    
//}
Player player; 
Circle circle; 


bool collision = false; 

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sunshine");
    SetTargetFPS(60);
    Vector2 ballPosition = { 100, 100 };
    
    

    //Seeting the initial colours of the Player Circle and the Goal Ball
    player.circleColor1 = PINK;
    player.circleColor2 = SKYBLUE;
    circle.circleColor1 = DARKGREEN;
    circle.circleColor2 = YELLOW;
    


    
    
    while (!WindowShouldClose())
    {
        void ShowCursor(void);
        void HideCursor(void);

       

        collision = CheckCollisionCircles({ player.x,player.y }, player.pCircleRadius, { 666, 420 }, circle.circleRadius);
        
        ////////DRAW/////
        BeginDrawing();
        ClearBackground(GRAY);
        
       //Goal Ball  
        circle.x = 666; 
        circle.y = 420; 
        circle.Draw(); 
       

       //Player ball

       player.x = GetMouseX();
       player.y = GetMouseY() + (player.pCircleRadius / 2);
       player.Draw(); 
      
       if (CheckCollisionCircles(Vector2{ circle.x, circle.y }, circle.circleRadius, Vector2{ player.x , player.y }, player.pCircleRadius))
       {
       
           player.circleColor1 = BLACK;
           player.circleColor2 = BLUE;
           circle.circleColor1 = YELLOW;
           circle.circleColor2 = PINK;
           DrawText("Player has hit the orb!", GetScreenWidth() / 2 - MeasureText("COLLISION!", 20) / 2, GetScreenHeight() / 2 , 20, BLACK);

       }
       else
       {
           player.circleColor1 = PINK;
           player.circleColor2 = SKYBLUE;

           circle.circleColor1 = DARKGREEN;
           circle.circleColor2 = YELLOW;

       }
        
       

      
       

       //The puzzle walls, maybe make this into a class for the sake of detection?   

        DrawLineEx({ 60,0 }, { 60,200 }, 5.0, PINK); 
        DrawLineEx({ 60,200 }, { 85,300 }, 5.0, GREEN);
        DrawLineEx({ 85,300 }, { 125,100 }, 5.0, RED);
        DrawLineEx({ 35,0 }, { 35,100 }, 5.0, BLUE);
        
          
       
        

        
        DrawFPS(10, 10);//FPS Display

        EndDrawing(); 


    }

    CloseWindow();
    return 0;
}