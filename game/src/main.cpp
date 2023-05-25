//GAME 3001 - Week 2 Lab



//1. Build and run 3 Raylib example projects on your computer and explain what each
//does.
//2. Improve Kinematics simulation to work on a container of objects(e.g.std::vector)
//instead of specifically named individual objects
//a.Create a Rigidbody class which encapsulates position, velocity
//b.Create an Agent class which contains a Rigidbody and all the extra data it may
//need, like a sprite, maxSpeed, maxAcceleration
//c.Create an update function that calculates the next frame state of a Rigidbody
//object according to its current position, velocity, and deltaTime
//d.Simulate Agents using a container of these Rigidbody objects, iterating through
//the whole list to update them all according to position and velocity.
//3. Have Agents Seek toward the mouse only while holding down the mouse button.Make
//Seek into a function which outputs an acceleration given an Agent position, velocity,
//Target position, and max acceleration.
//4. Have Agents Flee from some other objects you place in the world.Make Flee into a
//function which outputs an acceleration given an Agent position, velocity, Target
//position, and max acceleration.


#include "rlImGui.h"
#include "Math.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

Vector2 WraparoundScreen(Vector2 position)
{
    Vector2 outPosition =
    {
        (int)(position.x + SCREEN_WIDTH) % SCREEN_WIDTH,
        (int)(position.y + SCREEN_HEIGHT) % SCREEN_HEIGHT
    };

    return outPosition;
}


class Rigidbody
{

    public:
        
        Vector2 position = { 0 , 0 };
        Vector2 velocity = { 0 , 0 }; 
    //a.Create a Rigidbody class which encapsulates position, velocity



};

class Agent
{
private:
    float maxSpeed = 850;
    

public:

    

    //b.Create an Agent class which contains a Rigidbody and all the extra data it may
//need, like a sprite, maxSpeed, maxAcceleration


};



int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sunshine");
    SetTargetFPS(200);

    rlImGuiSetup(true); // Sets up imgui

    Vector2 position = { 100, 100 };
    Vector2 urMom = { 100, 400 };
    Vector2 velocity = { 10, 0 };
    Vector2 acceleration = { 0, 50 };
    float maxSpeed = 1000;
    

    bool useGUI = false;
    while (!WindowShouldClose())
    {
        const float deltaTime = GetFrameTime();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (IsKeyDown(KEY_GRAVE)) useGUI = !useGUI;
        if (useGUI)
        {
            rlImGuiBegin();

            ImGui::SliderFloat2("Position", &(position.x), 0, SCREEN_WIDTH);
            ImGui::SliderFloat2("Velocity", &(velocity.x), -maxSpeed, maxSpeed);
            ImGui::SliderFloat2("Acceleration", &(acceleration.x), -maxSpeed, maxSpeed);

            rlImGuiEnd();
        }

        Vector2 displacement = velocity * deltaTime; // px/s * s = px
        position = position + displacement;

        Vector2 deltaV = acceleration * deltaTime;
        velocity = velocity + deltaV; // px/s/s/s * s = px/s

        position = position + displacement * acceleration * deltaTime * deltaTime * 0.5f;

        position = WraparoundScreen(position);

        //vector seeker to target


       

        DrawCircleV(position, 50, GREEN);
        DrawLineV(position, position + velocity, RED); 
        DrawLineV(position, position + acceleration, GREEN);

        DrawCircleGradient(GetMousePosition().x, GetMousePosition().y, 50, LIGHTGRAY, BLACK);


        DrawFPS(10, 100);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}