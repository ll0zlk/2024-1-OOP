#include <iostream>
#define MAX 100
using namespace std;

int main() {
    int N;
    cin >> N;

    int A[MAX];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int maxlen = 1; // ���� �� ����
    int len = 1;    // ���� ���� ����
    for (int i = 1; i < N; i++) {
        if (A[i - 1] <= A[i]) {
            len++;
        }
        else {
            if (len > maxlen)
                maxlen = len;
            len = 1;    // �ʱ�ȭ
        }
    }
    if (len > maxlen)
        maxlen = len;

    cout << maxlen << endl;

    return 0;
}