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

    int maxlen = 1; // 가장 긴 구간
    int len = 1;    // 현재 구간 길이
    for (int i = 1; i < N; i++) {
        if (A[i - 1] <= A[i]) {
            len++;
        }
        else {
            if (len > maxlen)
                maxlen = len;
            len = 1;    // 초기화
        }
    }
    if (len > maxlen)
        maxlen = len;

    cout << maxlen << endl;

    return 0;
}