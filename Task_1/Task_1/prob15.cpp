#include <iostream>
using namespace std;

/* ���� 0�� ���� */
int main(void) {
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int a = i;
		while (a > 0) {
			if (a % 10 == 0) {
				cnt++;
			}
			a /= 10;
		}
	}


	cout << cnt << endl;
	return 0;
}