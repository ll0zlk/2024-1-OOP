#include <iostream>
#define MAX 100
using namespace std;

int main(void) {
	int numbers[MAX];
	int size = 0;	// 현재 배열 크기

	/* 배열 입력 받기 */
	int num;
	while (cin >> num && num != -1 && size < MAX) {
		numbers[size] = num;
		size++;	// 배열 크기 증가
	}

	/* 극소값 카운트 */
	int cnt = 0;

	if (numbers[0] <= numbers[1]) cnt++;	// 첫 번째 정수

	for (int i = 1; i < size - 1; i++) {
		if (numbers[i] <= numbers[i - 1] && numbers[i] <= numbers[i + 1]) cnt++;
	}

	if (numbers[size - 1] <= numbers[size - 2]) cnt++;	// 마지막 정수

	cout << cnt << endl;
	return 0;
}