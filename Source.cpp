#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <math.h>

#include "Controller.h"
#include "UILayout.h"
#include "Game2048.h"

// Class Initiate
Controller controller;
Game2048 game2048;
UILayout uiLayout;

void PrintScreen(){
  uiLayout.PositionY(4);
  uiLayout.PrintScore((uiLayout.GetScreenX() - 32 - 2)/2);
  uiLayout.PositionY(2);
  game2048.PrintNumber((uiLayout.GetScreenX() - 29 - 2)/2);
}

int main(void) {
  char direction; // For Values get from controller.GetDirection()
  int x; // For Align Center Values

  // Random Seed Initiate
  srand((unsigned)time(NULL));

  // Set Start Numbers the Print them
  game2048.StartNumber();

  PrintScreen();

  // Check if Game Over LOOP the Main Game
  while (!game2048.CheckGameOver()) {
    game2048.ResetIfMove();
    direction = controller.GetDirection();
    game2048.NumberCombine(direction);
    if (game2048.GetIfMove()) {
      game2048.AddNumber(direction);
      system("cls");
      PrintScreen();
    }
  }

  uiLayout.UIGameOver();

  rewind(stdin);
  _getch();

  return 0;
}
