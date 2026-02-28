#include "raylib.h"

int const SCREEN_WIDTH = 1000;
int const SCREEN_HEIGHT = 600;

float p_posX = 100;
float p_posY = 100;
float p_width = 60;
float p_height = 400;
// float _speed = 100;

void Update(float delta);
void PhysicsUpdate(float delta);

// Player _p;

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,
             "raylib [core] example - basic window");
  // SetTargetFPS(600);

  while (!WindowShouldClose()) {
    float delta = GetFrameTime();

    Update(delta);
    BeginDrawing();
    ClearBackground(BLACK);
    PhysicsUpdate(delta);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

// This function runs every frame (for input actions)
void Update(float delta) {
  // code here
}

// This function runs every frame (for drawing and physics)
void PhysicsUpdate(float delta) {
  DrawFPS(10, 10);

  // array of colors to use in drawing rects
  Color colors[10] = {
      {000, 255, 255, 255}, {255, 000, 200, 255}, {255, 255, 000, 255},
      {235, 255, 255, 255}, {155, 255, 155, 255}, {200, 255, 025, 255},
      {000, 100, 255, 255}, {010, 255, 100, 255}, {255, 250, 055, 255},
      {000, 255, 100, 255},
  };

  for (int i = 0; i < 10; i++) {

    // DrawRectangle(p_posX + (i * 90), p_posY + (i * 50), p_width,
    //               p_height + (i * 50), colors[i]);
    DrawRectangle(p_posX + (i * 100), p_posY, p_width, p_height, colors[i]);
  }
}
