#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <math.h>

#include "Controller.h"
#include "UILayout.h"
#include "Game2048.h"


int main(void) {
  char direction; // For Values get from controller.GetDirection()

  // Random Seed Initiate
  srand((unsigned)time(NULL));

  // Class Initiate
  Controller controller;
  Game2048 game2048;
  UILayout uiLayout;

  // Set Start Numbers the Print them
  game2048.StartNumber();
  game2048.PrintNumber();

  // Check if Game Over LOOP the Main Game
  while (!game2048.CheckGameOver()) {
    game2048.ResetIfMove();
    direction = controller.GetDirection();
    game2048.NumberCombine(direction);
    if (game2048.GetIfMove()) game2048.AddNumber(direction);
    system("cls");
    game2048.PrintNumber();
  }

  uiLayout.UIGameOver();

  rewind(stdin);
  _getch();

  return 0;
}
