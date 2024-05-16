#include <iostream>
#define MAX 100
using namespace std;

/* 초과하지 않으면서 가장 긴 구간 */
int main() {
    int N, K, A[MAX];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> K;

    int maxlen = 0;
    for (int i = 0; i < N; i++) {
        int len = 0;
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];
            if (sum <= K) {
                len++;
            }
            else
                break;
        }
        if (maxlen < len)
            maxlen = len;
    }

    cout << maxlen << endl;

    return 0;
}