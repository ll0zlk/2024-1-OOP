#include <iostream>
using namespace std;

int power(int n, int m) {
    int r = 1;
    for (int i = 0; i < m; i++) {
            r *= n;
        }
    return r;
}

int main() {
    int n;
    cin >> n;
    double result = 1.0;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            result += (1.0 / power(2, i));
        }
        else {
            result -= (1.0 / power(2, i));
        }
    }
    cout.precision(4);  // 소수점 자리 수를 지정할 수 있다.
    cout << fixed << result;    // fixed : 고정 소수점 
    return 0;
}