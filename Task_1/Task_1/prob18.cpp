#include <iostream>
using namespace std;

/* 등장하는 숫자 개수 */
int main(void) {
    int N;
    cin >> N;

    int digitCount[10] = { 0,0,0,0,0,0,0,0,0,0 };

    while (N > 0) {
        digitCount[N % 10]++;
        N /= 10;
    }

    for (int i = 0; i < 9; i++) {
        cout << digitCount[i] << ", ";
    }
    cout << digitCount[9] << endl;
    return 0;
}