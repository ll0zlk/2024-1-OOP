#include <iostream>
#define MAX 100
using namespace std;

/* �������� �ߺ� */
int main() {
    int n, size = 0;
    int data[MAX];

    while (1) {
        cin >> n;
        if (n == -1)
            break;

        bool duplicate = false;
        for (int i = 0; i < size; i++) {
            if (n == data[i]) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) {
            cout << "duplicate\n";
            continue;
        }

        int index = size - 1;   // n ������ �� ������ �� �� �ε���
        while (index >= 0 && data[index] > n) {   // �� ��° �̻� �����̸鼭 �� �������� ����
            data[index + 1] = data[index];  // �� �ڸ� ������ֱ�
            index--;    // �� ĭ �� ���� �˻� �ݺ�
        }
        data[index + 1] = n;
        size++;

        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    return 0;
}