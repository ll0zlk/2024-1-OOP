#include <iostream>
using namespace std;

/* ��и� ���� ���� �� ���� */
int main(void) {
	int cnt = 0;
	for (int x = 0; x <= 100; x++) {
		for (int y = 0; y <= 100; y++) {
			if (y <= (2.0 / 3) * x && y >= (1.0 / 3) * x && (x * x + y * y <= 100 * 100))
				cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}