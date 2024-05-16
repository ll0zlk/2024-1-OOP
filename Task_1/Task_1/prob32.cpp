#include <iostream>
#define MAX 100
using namespace std;

/* 연속된 1의 개수 */
int main() {
    int N;
    cin >> N;

    int A[MAX];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int max = 0, cnt = 0;

    /* 원래 수열 */
    for (int i = 0; i < N; i++) {
        if (A[i] == 1) {
            cnt++;
        }
        else {
            if (max < cnt)
                max = cnt;
            cnt = 0;
        }
    }
    if (max < cnt)
        max = cnt;

    /* 하나 바꾼 수열 */
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            A[i] = 1;
            for (int j = 0; j < N; j++) {
                if (A[j] == 1) {
                    cnt++;
                }
                else {
                    if (max < cnt)
                        max = cnt;
                    cnt = 0;
                }
            }
            A[i] = 0;   // 원래대로 복구
        }
    }
    if (max < cnt)
        max = cnt;


    cout << max << endl;
    return 0;
}