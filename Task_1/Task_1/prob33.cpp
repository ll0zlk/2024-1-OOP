#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 100
using namespace std;

/* 강아지 Puppy's Escape */
int main() {
    int N;
    cin >> N;

    srand(time(0));

    int T = 10000;  // 실험 횟수
    double success = 0.0;    // 성공 횟수

    for (int t = 0; t < T; t++) {   // 실험 횟수만큼 반복
        // 시작 위치 설정
        int x = N / 2;
        int y = N / 2;

        // 방문한 곳을 표시하는 배열 초기화
        int visited[MAX][MAX] = { 0 };
        visited[x][y] = 1; // 시작 위치 방문 표시

        // 실패할 때까지 반복
        while (true) {
            int unvisited[4][2] = { 0 };    // 방문하지 않은 곳 (상하좌우 각각의 x, y좌표 배열)
            int num_unvisited = 0;  // 방문하지 않은 곳의 개수

            // 이동 가능한지 확인하고, 방문하지 않은 곳만 unvisited 저장
            if (y > 0 && visited[x][y - 1] == 0) { // 상
                unvisited[num_unvisited][0] = x;
                unvisited[num_unvisited][1] = y - 1;
                num_unvisited++;
            }
            if (y < N - 1 && visited[x][y + 1] == 0) { // 하
                unvisited[num_unvisited][0] = x;
                unvisited[num_unvisited][1] = y + 1;
                num_unvisited++;
            }
            if (x > 0 && visited[x - 1][y] == 0) { // 좌
                unvisited[num_unvisited][0] = x - 1;
                unvisited[num_unvisited][1] = y;
                num_unvisited++;
            }
            if (x < N - 1 && visited[x + 1][y] == 0) { // 우
                unvisited[num_unvisited][0] = x + 1;
                unvisited[num_unvisited][1] = y;
                num_unvisited++;
            }

            // 방문하지 않은 곳이 없으면 탈출에 실패
            if (num_unvisited == 0)
                break;

            // 방문하지 않은 곳 중 랜덤하게 이동
            int idx = rand() % num_unvisited;
            x = unvisited[idx][0];
            y = unvisited[idx][1];

            // 해당 위치 방문 처리
            visited[x][y] = 1;

            // 가장자리 도달 시 성공
            if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
                success++;
                break;
            }
        }
    }

    double result = success / T;
    cout.precision(3);
    cout << fixed << result << endl;

    return 0;
}