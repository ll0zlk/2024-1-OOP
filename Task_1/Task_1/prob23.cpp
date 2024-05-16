#include <iostream>
#define MAX 100
using namespace std;

/* 오름차순 중복 */
int main() {
    int n, size = 0;
    int data[MAX];

    while (1) {
        cin >> n;
        if (n == -1)
            break;

        bool duplicate = false;
        for (int i = 0; i < size; i++) {
            if (n == data[i]) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) {
            cout << "duplicate\n";
            continue;
        }

        int index = size - 1;   // n 이전의 수 정렬할 때 쓸 인덱스
        while (index >= 0 && data[index] > n) {   // 두 번째 이상 정수이면서 앞 정수보다 작음
            data[index + 1] = data[index];  // 앞 자리 만들어주기
            index--;    // 한 칸 앞 정수 검사 반복
        }
        data[index + 1] = n;
        size++;

        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    return 0;
}