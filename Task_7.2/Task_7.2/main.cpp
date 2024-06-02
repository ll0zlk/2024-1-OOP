#include <iostream>
#include "GameObject.h"
#include "GameProgram.h"

int main() {
	Game* g = new Game;
	g->game();
	delete g;
}