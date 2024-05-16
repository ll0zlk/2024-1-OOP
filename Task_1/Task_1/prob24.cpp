#include <iostream>
#define MAX 100
using namespace std;

/* 선택정렬 */
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;

    int data[MAX];

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = 0;
        int max = data[0];
        for (int j = 0; j < i; j++) {
            if (max < data[j]) {
                max = data[j];
                index = j;
            }
        }
        swap(data[i], data[index]);
    }

    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}