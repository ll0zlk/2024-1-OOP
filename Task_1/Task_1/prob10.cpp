#include <iostream>
using namespace std;

/* 2���� ������ ��ȯ */
int main(void) {
	int N;
	cin >> N;

	// N���� �۰ų� �����鼭 ���� ū 2�� �ŵ������� v ���ϱ�
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