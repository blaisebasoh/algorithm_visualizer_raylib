#include "raylib.h"
#include <stdlib.h>
#include <time.h>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int BAR_COUNT = 60;

int values[BAR_COUNT];

float sortTimer = 0.0f;
float sortDelay = 0.01f; // controls how fast the sorting animation plays

int i_index = 0; // global i index for sorting
int j_index = 0; // global j index for sorting
int minIndex = 0;

bool isSorting = false;
bool isPaused = false;

// TODO: Implement these sorting algorithms
enum SortType { BUBBLE, SELECTION, INSERTION };
SortType currentSort = BUBBLE;

void InitArray();
void Draw();
void Update(float delta);

void BubbleSort();
void InsertionSort();
void SelectionSort();

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Algorithm Visualizer");
  SetTargetFPS(60);

  srand(time(NULL));
  InitArray();

  while (!WindowShouldClose()) {
    float delta = GetFrameTime();

    Update(delta);

    BeginDrawing();
    ClearBackground(BLACK);
    Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

void InitArray() {
  for (int i = 0; i < BAR_COUNT; i++) {
    values[i] = GetRandomValue(20, SCREEN_HEIGHT - 80);
  }

  i_index = 0;
  j_index = 0;
  minIndex = 0;
  isSorting = true;
}

// algorithms implementation for BubbleSort
void BubbleSort() {
  if (i_index < BAR_COUNT - 1) {
    if (j_index < BAR_COUNT - i_index - 1) {
      if (values[j_index] > values[j_index + 1]) {
        int temp = values[j_index];
        values[j_index] = values[j_index + 1];
        values[j_index + 1] = temp;
      }
      j_index++;
    } else {
      j_index = 0;
      i_index++;
    }
  } else {
    isSorting = false;
  }
}

// algorithms implementation for SelectionSort
void SelectionSort() {
  //
}

// algorithms implementation for InsertionSort
void InsertionSort() {
  //
}

void Update(float delta) {
  if (IsKeyPressed(KEY_ONE)) {
    currentSort = BUBBLE;
    InitArray();
  }
  if (IsKeyPressed(KEY_TWO)) {
    currentSort = SELECTION;
    InitArray();
  }
  if (IsKeyPressed(KEY_THREE)) {
    currentSort = INSERTION;
    InitArray();
  }
  if (IsKeyPressed(KEY_R)) {
    InitArray();
  }
  if (IsKeyPressed(KEY_SPACE))
    isPaused = !isPaused;

  if (!isSorting || isPaused)
    return;

  sortTimer += delta;

  if (sortTimer >= sortDelay) {
    sortTimer = 0.0f;

    switch (currentSort) {
    case BUBBLE:
      BubbleSort();
      break;
    case SELECTION:
      SelectionSort();
      break;
    case INSERTION:
      InsertionSort();
      break;
    }
  }
}

void Draw() {
  DrawFPS(10, 10);

  float baseLine = SCREEN_HEIGHT - 20; // floor for rectangles
  float spacing = (float)SCREEN_WIDTH / BAR_COUNT;
  float barWidth = spacing - 2;

  for (int i = 0; i < BAR_COUNT; i++) {
    float height = (float)values[i];
    float x = i * spacing;
    float y = baseLine - height;

    Color color = WHITE;

    if (i == j_index || i == j_index - 1)
      color = RED;

    if (!isSorting)
      color = GREEN;

    DrawRectangle(x, y, barWidth, height, color);
  }

  DrawText("1: Bubble  2: Selection  3: Insertion  R: Reset  SPACE: Pause", 10,
           30, 20, GRAY);
}
