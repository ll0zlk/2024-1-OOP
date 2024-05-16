#include <iostream>
using namespace std;

/* 피보나치 수열 */
int main() {
    int n;
    cin >> n;
    int f1 = 0;
    int f2 = 1;
    int f3;

    for (int i = 0; i < n; i++) {
        f3 = f2 + f1;      // 2 <= n <= 30 이라, 0과 1인 경우 고려 X
        f1 = f2;
        f2 = f3;
    }

    cout << f3;
    return 0;
}