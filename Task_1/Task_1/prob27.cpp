#include <iostream>
#define MAX 100
using namespace std;

/* ¿ªÀüµÈ ½Ö */
int main() {
    int N, A[MAX];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i; j < N; j++) {
            if (A[i] > A[j])
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}