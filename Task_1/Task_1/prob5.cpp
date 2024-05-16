#include <iostream>
using namespace std;

/* 최소값 찾기 */
int main(void) {
	int N;
	cin >> N;

	int list[100];
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	int min = -1;
	for (int i = 0; i < N; i++) {
		if (list[i] >= 0) {
			if (min < 0) {
				min = list[i];
			}
			if (list[i] < min) {
				min = list[i];
			}
		}
	}

	cout << min;
	
	return 0;
}