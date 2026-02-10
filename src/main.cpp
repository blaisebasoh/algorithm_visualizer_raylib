#include "raylib.h"
int const SCREEN_WIDTH = 800;
int const SCREEN_HEIGHT = 600;

// Player entity properties
// typedef struct {
float p_posX = 100;
float p_posY = 100;
float p_width = 80;
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

  // if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
  //   _p.posY -= _p._speed * delta;
  // }
  // if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
  //   _p.posY += _p._speed * delta;
  // }
  // if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
  //   _p.posX -= _p._speed * delta;
  // }
  // if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
  //   _p.posX += _p._speed * delta;
  // }
}

// This function runs every frame (for drawing and physics)
void PhysicsUpdate(float delta) {
  DrawFPS(10, 10);

  Color colors[10] = {
      {0, 255, 255, 255},   {255, 255, 255, 255}, {255, 255, 255, 255},
      {255, 255, 255, 255}, {255, 255, 255, 255}, {255, 255, 255, 255},
      {255, 255, 255, 255}, {255, 255, 255, 255}, {255, 255, 255, 255},
      {255, 255, 255, 255},
  };

  for (int i = 0; i < 10; i++) {
    DrawRectangle(p_posX + (i * 100), p_posY, p_width, p_height, colors[i]);
  }
}
