#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 100;

/* 최고 자리 수 */
int leftDigit(int a) {
    while (a >= 10) {
        a /= 10;
    }
    return a;
}

/* 사전식 배열 */
int lexicographicSort(int a, int b) {
    int temp_a = a;
    int temp_b = b;

    while (temp_a != 0 && temp_b != 0) {
        int digit_a = leftDigit(temp_a);
        int digit_b = leftDigit(temp_b);

        if (digit_a < digit_b)
            return -1;
        else if (digit_a > digit_b)
            return 1;

        // 다음 자릿수로 이동
        temp_a %= (int)(pow(10, log10(temp_a)));
        temp_b %= (int)(pow(10, log10(temp_b)));
    }

    // 자릿수가 다른 경우, 더 짧은 숫자를 앞으로 보냄
    if (temp_a == 0 && temp_b != 0)
        return -1;
    else if (temp_a != 0 && temp_b == 0)
        return 1;

    // 두 수의 자릿수가 같음
    return 0;
}

int main() {
    int n;
    cin >> n;

    int num[MAX];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lexicographicSort(num[i], num[j]) == 1)
                swap(num[i], num[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}
