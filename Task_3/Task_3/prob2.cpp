#include <iostream>
#include <vector>
using namespace std;

/* 합집합 교집합 */
void compute_set(vector<int>& A, vector<int>& B) {
	vector<int> C;
	int i = 0, j = 0;

	while (i < A.size() && j < B.size()) {
		if (A[i] < B[j]) {
			C.push_back(A[i]);
			i++;
		}
		else if (A[i] > B[j]) {
			C.push_back(B[j]);
			j++;
		}
		else {
			i++;
			j++;
		}
	}
	while (i < A.size()) {
		C.push_back(A[i]);
		i++;
	}
	while (j < B.size()) {
		C.push_back(B[j]);
		j++;
	}
	A = C;
}

int main() {
	int m, n, k;
	vector<int> first, second;
	cin >> m;
	// m개의 정수가 오름차순으로 입력
	for (int i = 0; i < m; i++) {
		cin >> k;
		first.push_back(k);
	}
	cin >> n;
	// n개의 정수가 오름차순으로 입력
	for (int i = 0; i < n; i++) {
		cin >> k;
		second.push_back(k);
	}

	compute_set(first, second);

	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;
}