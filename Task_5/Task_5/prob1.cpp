#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderedVecInt {
private:
	int capacity = 0, size = 0;	// capacity: ���� �迭�� ����, size: ����� ���� ����
	int* arr = nullptr;	// ���� �迭�� ���� �ּ�. ó������ ���̰� 0�� �迭
	// ù ��° ���Ұ� ���Ե� �� ���̸� 1�� �����,
	// �� �������ʹ� �ʿ� �� ���̸� 2��� �ø���.
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
		vec.insert(k);	// ���� k ����. �������� ���ĵǾ� ����Ǿ�� �Ѵ�.
	}
	for (int i = 0; i < vec.size_of_vec(); i++)
		cout << vec[i] << " ";	// indexing ������ []�� �����Ѵ�.
	cout << endl;

	if (vec.remove_by_val(vec[2]))	// �Ű������� �־��� ������ ã�� �����Ѵ�.
		cout << "Remove done" << endl;	// �׷� ���� �����ϸ� true,
	else
		cout << "Remove failed" << endl;	// �ƴϸ� false�� ��ȯ�Ѵ�.

	if (vec.remove_by_index(4))	// �Ű������� �־��� �ε��� ��ġ�� ������ �����Ѵ�.
		cout << "RemoveIndex done" << endl;	// ��ȿ�� �ε����̸� true,
	else
		cout << "RemoveIndex failed" << endl;	// �ƴϸ� false�� ��ȯ�Ѵ�.

	for (int i = 0; i < vec.size_of_vec(); i++)	// size_of_vec()�� ����� ������ ������ ��ȯ�Ѵ�.
		vec[i] -= 10;	// ����� ������ ������ �� �ִ�. �� ��� ������ ��Ʈ���� �� �ִ�.

	for (int i = 0; i < vec.size_of_vec(); i++)
		cout << vec[i] << " ";
	cout << endl;

	return 0;

}