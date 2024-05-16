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
    cout.precision(4);  // �Ҽ��� �ڸ� ���� ������ �� �ִ�.
    cout << fixed << result;    // fixed : ���� �Ҽ��� 
    return 0;
}