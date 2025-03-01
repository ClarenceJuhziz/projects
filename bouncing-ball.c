#include <stdio.h>
#include <raylib.h>


int main(){
    int centerY = 100;
    int centerX = 100;

    float velocity = 0.1;
    float acceleration = 0.3;
    float speedloss = 0.8;

    bool falling = 1;
    bool stop = 0;

    InitWindow(500, 500, "bouncing");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(centerY, centerX, 20, BLACK);
        
        if(falling){
        
        centerX += velocity;
        velocity += acceleration;
        
        
            if(centerX > 480){
                
                velocity *= speedloss;
                falling = 0;

            }
            else if(speedloss < 0){
                centerX = 480;
                stop = 1;
            }
        }
    else if(!falling && !stop){
        
        centerX -= velocity;
        velocity -= acceleration;
        
        if(velocity <= 0){
            
            velocity = 0.1;
            falling = 1;
            speedloss -= 0.15;
        }
    }
    EndDrawing();
    }
    
    return 0;
}
