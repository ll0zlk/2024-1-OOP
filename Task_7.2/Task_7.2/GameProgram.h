#pragma once
#include <string>
#include "GameObject.h"
using namespace std;

class Game {
	string board[10][20];
	Human* h = new Human(0, 0, 1);
	Monster* m = new Monster(5, 7, 2);
	Food* f = new Food(8, 10, 1);
public:
	Game() {
		srand((unsigned)time(0));
		cout << "** Human의 Food 먹기 게임을 시작합니다. **" << endl << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++)
				board[i][j] = "-";
		}
	}
	~Game() { delete h; delete m; delete f; }
	void game();
	void clr1();
	void clr2();
	void setXY();
	void show();
};