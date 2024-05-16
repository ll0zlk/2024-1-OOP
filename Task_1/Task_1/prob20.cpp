#include <iostream>
using namespace std;

/* circular right shift 원형 이동 */
int main() {
    int n, k;
    int A[100];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> k;

    for (int i = 0; i < n - 1; i++) {
        cout << A[(i - k + n) % n] << " ";
    }
    cout << A[(2 * n - 1 - k) % n] << endl;

    return 0;
}