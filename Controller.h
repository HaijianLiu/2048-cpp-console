#pragma once
class Controller
{
public:
	Controller();
	~Controller();

	// Get Direction
	char GetDirection(){
		switch(_getch()){
			case 'w': dirction = 'u'; break;
			case 'a': dirction = 'l'; break;
			case 's': dirction = 'd'; break;
			case 'd': dirction = 'r'; break;
			case 'W': dirction = 'u'; break;
			case 'A': dirction = 'l'; break;
			case 'S': dirction = 'd'; break;
			case 'D': dirction = 'r'; break;
			// case 72: dirction = 'u'; break;
			// case 75: dirction = 'l'; break;
			// case 80: dirction = 'd'; break;
			// case 77: dirction = 'r'; break;
			default : dirction = '0'; break;
		}
		return dirction;
	}

private:
	char dirction;
};
