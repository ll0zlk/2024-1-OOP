#include <iostream>
#define MAX 100
using namespace std;

int main(void) {
	int numbers[MAX];
	int size = 0;	// ���� �迭 ũ��

	/* �迭 �Է� �ޱ� */
	int num;
	while (cin >> num && num != -1 && size < MAX) {
		numbers[size] = num;
		size++;	// �迭 ũ�� ����
	}

	/* �ؼҰ� ī��Ʈ */
	int cnt = 0;

	if (numbers[0] <= numbers[1]) cnt++;	// ù ��° ����

	for (int i = 1; i < size - 1; i++) {
		if (numbers[i] <= numbers[i - 1] && numbers[i] <= numbers[i + 1]) cnt++;
	}

	if (numbers[size - 1] <= numbers[size - 2]) cnt++;	// ������ ����

	cout << cnt << endl;
	return 0;
}