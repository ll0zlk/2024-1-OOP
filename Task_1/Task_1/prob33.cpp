#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 100
using namespace std;

/* ������ Puppy's Escape */
int main() {
    int N;
    cin >> N;

    srand(time(0));

    int T = 10000;  // ���� Ƚ��
    double success = 0.0;    // ���� Ƚ��

    for (int t = 0; t < T; t++) {   // ���� Ƚ����ŭ �ݺ�
        // ���� ��ġ ����
        int x = N / 2;
        int y = N / 2;

        // �湮�� ���� ǥ���ϴ� �迭 �ʱ�ȭ
        int visited[MAX][MAX] = { 0 };
        visited[x][y] = 1; // ���� ��ġ �湮 ǥ��

        // ������ ������ �ݺ�
        while (true) {
            int unvisited[4][2] = { 0 };    // �湮���� ���� �� (�����¿� ������ x, y��ǥ �迭)
            int num_unvisited = 0;  // �湮���� ���� ���� ����

            // �̵� �������� Ȯ���ϰ�, �湮���� ���� ���� unvisited ����
            if (y > 0 && visited[x][y - 1] == 0) { // ��
                unvisited[num_unvisited][0] = x;
                unvisited[num_unvisited][1] = y - 1;
                num_unvisited++;
            }
            if (y < N - 1 && visited[x][y + 1] == 0) { // ��
                unvisited[num_unvisited][0] = x;
                unvisited[num_unvisited][1] = y + 1;
                num_unvisited++;
            }
            if (x > 0 && visited[x - 1][y] == 0) { // ��
                unvisited[num_unvisited][0] = x - 1;
                unvisited[num_unvisited][1] = y;
                num_unvisited++;
            }
            if (x < N - 1 && visited[x + 1][y] == 0) { // ��
                unvisited[num_unvisited][0] = x + 1;
                unvisited[num_unvisited][1] = y;
                num_unvisited++;
            }

            // �湮���� ���� ���� ������ Ż�⿡ ����
            if (num_unvisited == 0)
                break;

            // �湮���� ���� �� �� �����ϰ� �̵�
            int idx = rand() % num_unvisited;
            x = unvisited[idx][0];
            y = unvisited[idx][1];

            // �ش� ��ġ �湮 ó��
            visited[x][y] = 1;

            // �����ڸ� ���� �� ����
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