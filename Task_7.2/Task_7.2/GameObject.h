#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

class GameObject {
protected:
	int distance;
	int x, y;
public:
	GameObject(int startX, int startY, int distance) {
		this->x = startX;
		this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {};

	virtual void move() = 0;
	virtual char getShape() = 0;

	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject* p) {
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};

class Human : public GameObject {	// 휴먼 클래스 상속
public:
	Human(int x, int y, int dis) : GameObject(x, y, dis) {}
	void move();
	char getShape() { return 'H'; }
};

class Monster : public GameObject {	// 몬스터 클래스 상속
public:
	Monster(int x, int y, int dis) : GameObject(x, y, dis) { srand((unsigned)time(0)); }
	void move();
	char getShape() { return 'M'; }
};

class Food : public GameObject {	// 푸드 클래스 상속
public:
	Food(int x, int y, int dis) : GameObject(x, y, dis) { srand((unsigned)time(0)); }
	void move();
	char getShape() { return '@'; }
};