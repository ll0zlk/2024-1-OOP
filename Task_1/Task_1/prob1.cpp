#include <iostream>
using namespace std;

/* �Ǻ���ġ ���� */
int main() {
    int n;
    cin >> n;
    int f1 = 0;
    int f2 = 1;
    int f3;

    for (int i = 0; i < n; i++) {
        f3 = f2 + f1;      // 2 <= n <= 30 �̶�, 0�� 1�� ��� ��� X
        f1 = f2;
        f2 = f3;
    }

    cout << f3;
    return 0;
}