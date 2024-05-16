#include <iostream>
using namespace std;

/* 2진수 이진수 변환 */
int main(void) {
	int N;
	cin >> N;

	// N보다 작거나 같으면서 가장 큰 2의 거듭제곱수 v 구하기
	int v = 1;
	while (v <= N) {
		v *= 2;
	}
	v /= 2;

	while (v > 0) {
		if (N >= v) {
			N -= v;
			cout << 1;
		}
		else {
			cout << 0;
		}
		v /= 2;
	}

	cout << endl;
	return 0;
}