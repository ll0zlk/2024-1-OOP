#include <iostream>
using namespace std;

/* �ִ밪�� �ּҰ��� ���� */
int main(void) {
	int N;
	cin >> N;
	
	int num;
	int min, max;

	cin >> num;
	min = max = num;
	cout << max - min << " ";

	for (int i = 1; i < N; i++) {
		cin >> num;
		if (min > num) {
			min = num;
		}
		if (max < num) {
			max = num;
		}

		cout << max - min << " ";
	}
	
	return 0;
}