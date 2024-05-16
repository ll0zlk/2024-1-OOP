#include <iostream>
using namespace std;

/* 절대값 가장 작은 정수 */
int main() {
    int n, k;
    int A[100];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> k;

    int min = abs(k - A[0]);
    int num = A[0];

    for (int i = 1; i < n; i++) {
        int diff = abs(k - A[i]);
        if (diff < min) {
            min = diff;
            num = A[i];
        }
    }

    cout << num << endl;
    return 0;
}