#include <iostream>
using namespace std;

int main() {    // ����: ���� ����
    int n;
    cin >> n;

    int A[100], L[100];     // �Է� ���� �迭, ���� �迭
    int cnt = 1, max;
    int index = 1;

    cin >> A[0];
    L[0] = max = A[0];

    for (int i = 1; i < n; i++) {
        cin >> A[i];

        if (A[i] >= max) {
            L[index] = A[i];
            max = A[i];
            cnt++;
            index++;
        }
    }

    cout << cnt << ": ";
    for (int i = 0; i < cnt; i++) {
        cout << L[i] << " ";
    }
    return 0;
}