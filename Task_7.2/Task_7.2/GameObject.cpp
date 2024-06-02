#include "GameObject.h"
#include <iostream>
#include <string>
using namespace std;

void Human::move() {	// 1ĭ �̵�
	string key;
	while (1) {
		cout << "����(a), �Ʒ�(s), ��(d), ������(f) >> ";
		cin >> key;
		if (key == "a") {
			if (y != 0) {
				y -= distance;
				break;
			}
			else
				cout << "Cannot Move" << endl;
		}
		else if (key == "s") {
			if (x != 9) {
				x += distance;
				break;
			}
			else
				cout << "Cannot Move" << endl;
		}
		else if (key == "d") {
			if (x != 0) {
				x -= distance;
				break;
			}
			else
				cout << "Cannot Move" << endl;
		}
		else if (key == "f") {
			if (y != 19) {
				y += distance;
				break;
			}
			else
				cout << "Cannot Move" << endl;
		}
		else {
			cout << "Unvalid Key" << endl;
		}
	}
}

void Monster::move() {	// 2ĭ �̵�
	while (1) {
		int n = rand() % 4;
		if (n == 0) {	// left
			if (y > 1) {
				y -= distance;
				break;
			}
		}
		else if (n == 1) {	// down
			if (x < 8) {
				x += distance;
				break;
			}

		}
		else if (n == 2) {	// up
			if (x > 1) {
				x -= distance;
				break;
			}
		}
		else {	// right
			if (y < 18) {
				y += distance;
				break;
			}
		}
	}
}

void Food::move() {	// 1ĭ �̵�
	while(1) {
		int n = rand() % 4;
		if (n == 0) {	// left
			if (y != 0) {
				y -= distance;
				break;
			}
		}
		else if (n == 1) {	// down
			if (x != 9) {
				x += distance;
				break;
			}

		}
		else if (n == 2) {	// up
			if (x != 0) {
				x -= distance;
				break;
			}
		}
		else {	// right
			if (y != 19) {
				y += distance;
				break;
			}
		}
	}
}