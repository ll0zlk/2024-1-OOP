#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, num;
	cin >> n;

	vector<int> numbers;
	cin >> num;
	numbers.push_back(num);		// 첫 번째 수는 중복 아니므로 push

	for (int i = 1; i < n; i++) {
		cin >> num;

		if (find(numbers.begin(), numbers.end(), num) == numbers.end()) {	// 중복이 아니면
			numbers.push_back(num);
		}
	}

	sort(numbers.begin(), numbers.end());

	cout << numbers.size() << ": ";
	for (int n : numbers) {
		cout << n << " ";
	}
	cout << endl;

	return 0;
}