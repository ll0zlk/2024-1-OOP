#include <iostream>
using namespace std;

/* ���׽� ��� */
int main(void) {
	int coef, expo_x, expo_y;
	cin >> coef >> expo_x >> expo_y;

	// ��� ���
	if ((coef != 0) && expo_x == 0 && expo_y == 0) {
		cout << coef;
	}
	else {
		if (coef != 1 && coef != -1) {
			cout << coef;
		}
		else if (coef == -1) {
			cout << "-";
		}
	}

	// x ���� ���
	if (expo_x != 0) {
		cout << "x";
		if (expo_x != 1) {
			cout << "^" << expo_x;
		}
	}

	// y ���� ���
	if (expo_y != 0) {
		cout << "y";
		if (expo_y != 1) {
			cout << "^" << expo_y;
		}
	}

	return 0;
}