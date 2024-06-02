#include "GameProgram.h"

void Game::game() {
	int count = 0, gamecount = 0;
	while (1) {
		setXY();
		show();
		clr1();
		h->move();
		m->move();
		int n = rand();
		cout << endl;
		if (n % 2 == 0 && count < 2 && gamecount <= 3) {
			clr2();
			f->move();
			count++;
		}
		if (gamecount > 3 && count < 2) {
			clr2();
			f->move();
			count++;
		}
		if (f->collide(h)) {	// ÈÞ¸ÕÀÌ Çªµå¸¦ ¸ÔÀ¸¸é
			setXY();
			board[f->getX()][f->getY()] = "H";
			show();
			cout << "Human is Winner!!" << endl;
			break;
		}
		else if (h->collide(m)) {	// ¸ó½ºÅÍ°¡ ÈÞ¸ÕÀ» ¸ÔÀ¸¸é
			setXY();
			board[f->getX()][f->getY()] = "M";
			show();
			cout << "Monster is Winner!!" << endl;
			break;
		}
		else if (f->collide(m)) {	// ¸ó½ºÅÍ°¡ Çªµå¸¦ ¸ÔÀ¸¸é
			setXY();
			board[f->getX()][f->getY()] = "M";
			show();
			cout << "Monster is Winner!!" << endl;
		}
		gamecount++;
		if ((gamecount % 5) == 0) {
			count = 0;
			gamecount = 0;
		}
	}
}

void Game::clr1() {
	board[h->getX()][h->getY()] = "-";
	board[m->getX()][m->getY()] = "-";
}

void Game::clr2() {
	board[f->getX()][f->getY()] = "-";
}

void Game::setXY() {
	board[h->getX()][h->getY()] = h->getShape();
	board[m->getX()][m->getY()] = m->getShape();
	board[f->getX()][f->getY()] = f->getShape();
}

void Game::show() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++)
			cout << board[i][j];
		cout << endl;
	}
}