#include <iostream>
using namespace std;

/* 다항식 출력 */
int main(void) {
	int coef, expo_x, expo_y;
	cin >> coef >> expo_x >> expo_y;

	// 계수 출력
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

	// x 차수 출력
	if (expo_x != 0) {
		cout << "x";
		if (expo_x != 1) {
			cout << "^" << expo_x;
		}
	}

	// y 차수 출력
	if (expo_y != 0) {
		cout << "y";
		if (expo_y != 1) {
			cout << "^" << expo_y;
		}
	}

	return 0;
}