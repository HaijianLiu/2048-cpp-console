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

	void PositionMainNumber(){
		
	}

	void UIGameOver(){
		printf("GAME OVER\n");
	}

private:
	// Variables for Screen Size X & Y
	int screenX;
	int screenY;
};
