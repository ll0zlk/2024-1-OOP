#include <iostream>
using namespace std;

/* Ȧ��...? */
int main() {
    int A[7];
    for (int i = 0; i < 7; i++) {
        cin >> A[i];
    }

    /* �������� ���� */
    for (int i = 0; i < 6; i++) {
        int minIndex = i;
        for (int j = i + 1; j < 7; j++) {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }

    /* �ߺ� ���� */
    int k = 0;
    for (int i = 1; i < 7; i++) {
        if (A[i] != A[i - 1])
            A[++k] = A[i];
    }

    /* ��Ʈ����Ʈ */
    bool is_straight = false;
    int straight = 1;
    for (int i = 0; i < 7; i++) {
        if (A[i] + 1 == A[i + 1]) {
            straight++;
            if (straight >= 5) {
                is_straight = true;
                break;
            }
        }
        else
            straight = 1;
    }

    if (is_straight) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}