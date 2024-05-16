#include <iostream>
#define MAX 100
using namespace std;

/* 겹치는 길이가 가장 긴 두 구간 */
int main() {
    int N;
    cin >> N;

    int interval[MAX][2];
    for (int i = 0; i < N; i++) {
        cin >> interval[i][0] >> interval[i][1];
    }

    int first_index = -1;   // 시작점
    int second_index = -1;  // 끝점
    int max_length = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int overlap_start = max(interval[i][0], interval[j][0]);
            int overlap_end = min(interval[i][1], interval[j][1]);
            int overlap_length = max(0, overlap_end - overlap_start);

            if (overlap_length > max_length) {
                max_length = overlap_length;
                first_index = i;
                second_index = j;
            }
        }
    }

    cout << "[" << interval[first_index][0] << ", " << interval[first_index][1] << "]" << endl;
    cout << "[" << interval[second_index][0] << ", " << interval[second_index][1] << "]" << endl;

    return 0;
}