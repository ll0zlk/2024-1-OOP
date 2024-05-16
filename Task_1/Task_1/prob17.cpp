#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n;
    const int MAX = 100;
    int A[MAX];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    double mean, sd;
    double sum = 0.0, dev = 0.0;

    /* 평균 */
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    mean = sum / n;

    /* 표준편차 */
    for (int i = 0; i < n; i++) {
        dev += (A[i] - mean) * (A[i] - mean);
    }
    sd = sqrt(dev / n);

    cout.precision(5);
    cout << mean << " " << sd << endl;
    return 0;
}