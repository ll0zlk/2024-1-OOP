#include <iostream>
#define MAX 100
using namespace std;

/* 중복 제거 */
int duplicate(int n, int A[], int size) {
    for (int i = 0; i < size; i++) {
        if (A[i] == n)  // 중복이면
            return 1;
    }
    return 0;   // 아니면
}

int main() {
    int n;
    cin >> n;

    int data[MAX];
    int notDup[MAX];
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    /* 선택정렬 */
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[minIndex])
                minIndex = j;
        }
        int temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }

    for (int i = 0; i < n; i++) {
        if (duplicate(data[i], notDup, cnt) == 0) {
            notDup[cnt] = data[i];
            cnt++;
        }
    }

    cout << cnt << ": ";
    for (int i = 0; i < cnt; i++) {
        cout << notDup[i] << " ";
    }
    cout << endl;
    return 0;
}