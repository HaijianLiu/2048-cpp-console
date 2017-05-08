#pragma once
class UILayout
{
public:
	UILayout();
	~UILayout();

	// Get Screen Size
	void GetScreenSize(){
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int ret;
		ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		if (ret) {
			screenX = csbi.srWindow.Right - csbi.srWindow.Left + 1;
			screenY = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
		}
	}

	// Print X of spaces
	void PositionX(int x){
		for (int i = 0; i < x; i++) {
			printf(" ");
		}
	}

	// Print Y of \n
	void PositionY(int y){
		for (int i = 0; i < y; i++) {
			printf("\n");
		}
	}

	// Get screenX to int
	int GetScreenX(){
		return screenX;
	}

	void UIGameOver(){
		printf("GAME OVER\n");
	}

	void PrintScore(int x){
		// printf("+---------------------------+\n");
		// printf("|    SCORE          BEST    |\n");
		// printf("|                           |\n");
		// printf("+---------------------------+\n");
		PositionX(x);
		printf("JOIN THE NUMBERS AND GET TO 2048\n");
	}

private:
	// Variables for Screen Size X & Y
	int screenX;
	int screenY;
};
