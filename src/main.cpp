#include "raylib.h"
#include <fstream>
#include <iostream>

// Player entity properties
typedef struct {
  float posX = 400;
  float posY = 400;
  float width = 100;
  float height = 40;
  float _speed = 0.01;
} Player;

void Update();

Player _p;

int main(void) {
  InitWindow(800, 450, "raylib [core] example - basic window");

  std::ofstream file;
  file.open("config.txt");
  while (!WindowShouldClose()) {
    Update();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats!", 190, 200, 20, LIGHTGRAY);
    DrawRectangle(_p.posX, _p.posY, _p.width, _p.height, RED);
    EndDrawing();
  }

  file << "PosY = " << _p.posY << "\n";
  file << "PosX = " << _p.posX << "\n";
  file.close();

  CloseWindow();

  return 0;
}

// This function runs every frame
void Update() {

  if (IsKeyDown(KEY_W)) {
    _p.posY -= _p._speed;
  }
  if (IsKeyDown(KEY_S)) {
    _p.posY += _p._speed;
  }
  if (IsKeyDown(KEY_A)) {
    _p.posX -= _p._speed;
  }
  if (IsKeyDown(KEY_D)) {
    _p.posX += _p._speed;
  }
}