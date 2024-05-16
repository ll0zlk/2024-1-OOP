#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderedVecInt {
private:
	int capacity = 0, size = 0;	// capacity: 동적 배열의 길이, size: 저장된 정수 개수
	int* arr = nullptr;	// 동적 배열의 시작 주소. 처음에는 길이가 0인 배열
	// 첫 번째 원소가 삽입될 때 길이를 1로 만들고,
	// 그 다음부터는 필요 시 길이를 2배로 늘린다.
public:
	OrderedVecInt() {
		arr = new int[capacity];
	}

	~OrderedVecInt() {
		delete[] arr;
	}

	void insert(int x) {
		int index = size;
		for (int i = 0; i < size; i++) {
			if (arr[i] > x) {
				index = i;
				break;
			}
		}
		for (int i = size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = x;
		size++;
	}

	int& operator[](int index) {
		return arr[index];
	}

	int size_of_vec() const {
		return size;
	}

	bool remove_by_val(int val) {
		int index = -1;
		for (int i = 0; i < size; i++) {
			if (arr[i] == val) {
				index = i;
				break;
			}
		}
		if (index == -1)
			return false;
		for (int i = index; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
		return true;
	}

	bool remove_by_index(int idx) {
		if (idx >= size || idx < 0)
			return false;
		for (int i = idx; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
		return true;
	}
};

int main() {
	srand((unsigned int)time(NULL));
	int n, k;
	OrderedVecInt vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k = rand() % 1000;
		vec.insert(k);	// 정수 k 삽입. 정수들은 정렬되어 저장되어야 한다.
	}
	for (int i = 0; i < vec.size_of_vec(); i++)
		cout << vec[i] << " ";	// indexing 연산자 []를 제공한다.
	cout << endl;

	if (vec.remove_by_val(vec[2]))	// 매개변수로 주어진 정수를 찾아 삭제한다.
		cout << "Remove done" << endl;	// 그런 값이 존재하면 true,
	else
		cout << "Remove failed" << endl;	// 아니면 false를 반환한다.

	if (vec.remove_by_index(4))	// 매개변수로 주어진 인덱스 위치의 정수를 삭제한다.
		cout << "RemoveIndex done" << endl;	// 유효한 인덱스이면 true,
	else
		cout << "RemoveIndex failed" << endl;	// 아니면 false를 반환한다.

	for (int i = 0; i < vec.size_of_vec(); i++)	// size_of_vec()는 저장된 정수의 개수를 반환한다.
		vec[i] -= 10;	// 저장된 정수를 수정할 수 있다. 이 경우 정렬이 흐트러질 수 있다.

	for (int i = 0; i < vec.size_of_vec(); i++)
		cout << vec[i] << " ";
	cout << endl;

	return 0;

}