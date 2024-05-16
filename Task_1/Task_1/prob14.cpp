#include <iostream>
using namespace std;

/* ¼­·Î¼Ò */
int disjoint(int a, int b) {	// a < b
	for (int i = 2; i <= a; i++) {
		if (a % i == 0 && b % i == 0)
			return 0;
	}
	return 1;
}

int main(void) {
	int cnt = 0;

	for (int i = 2; i < 101; i++) {
		for (int j = i + 1; j < 101; j++) {
			for (int k = j + 1; k < 101; k++) {
				if (disjoint(i, j) != 0 && disjoint(j, k) != 0 && disjoint(i, k) != 0)
					cnt++;
			}
		}
	}

	cout << cnt << endl;
	return 0;
}