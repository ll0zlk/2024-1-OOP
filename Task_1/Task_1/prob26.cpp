#include <iostream>
#define MAX 100
using namespace std;

/* 구간 시작점 끝점 */
int main() {
    int n;
    cin >> n;

    int start[MAX], end[MAX];

    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (start[j] < start[i] || (start[j] == start[i] && end[j] < end[i])) {
                swap(start[i], start[j]);
                swap(end[i], end[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << start[i] << " " << end[i] << endl;
    }

    return 0;
}