#include <iostream>
#include <vector>
using namespace std;

void move(int d, int s, int& x, int& y, vector<vector<int>>& grid) {
    bool available = true;
    switch (d) {
    case 0:     // +y
        for (int i = y + 1; i <= y + s; i++) { // 현재 위치 다음부터 확인
            if (grid[i + 100][x + 100] == 1) {       // 방문했던 곳이면
                cout << "invalid move" << endl;
                available = false;
                break;
            }
        }
        if (available) {    // 궤적 중복 없이 이동 가능하면
            for (int i = y + 1; i <= y + s; i++) {
                grid[i + 100][x + 100] = 1; // 방문 표시하고
            }
            y += s;     // 현재 위치를 이동한다.
            cout << x << " " << y << endl;
        }
        break;

    case 1:     // +x
        for (int i = x + 1; i <= x + s; i++) {
            if (grid[y + 100][i + 100] == 1) {       // 방문했던 곳이면
                cout << "invalid move" << endl;
                available = false;
                break;
            }
        }
        if (available) {    // 궤적 중복 없이 이동 가능하면
            for (int i = x + 1; i <= x + s; i++) {
                grid[y + 100][i + 100] = 1; // 방문 표시하고
            }
            x += s;     // 현재 위치를 이동한다.
            cout << x << " " << y << endl;
        }
        break;

    case 2:     // -y
        for (int i = y - 1; i >= y - s; i--) {
            if (grid[i + 100][x + 100] == 1) {       // 방문했던 곳이면
                cout << "invalid move" << endl;
                available = false;
                break;
            }
        }
        if (available) {    // 궤적 중복 없이 이동 가능하면
            for (int i = y - 1; i >= y - s; i--) {
                grid[i + 100][x + 100] = 1; // 방문 표시하고
            }
            y -= s;     // 현재 위치를 이동한다.
            cout << x << " " << y << endl;
        }
        break;

    case 3:     // -x
        for (int i = x - 1; i >= x - s; i--) {
            if (grid[y + 100][i + 100] == 1) {       // 방문했던 곳이면
                cout << "invalid move" << endl;
                available = false;
                break;
            }
        }
        if (available) {    // 궤적 중복 없이 이동 가능하면
            for (int i = x - 1; i >= x - s; i--) {
                grid[y + 100][i + 100] = 1; // 방문 표시하고
            }
            x -= s;     // 현재 위치를 이동한다.
            cout << x << " " << y << endl;
        }
        break;
    }
}

int main() {
    vector<vector<int>> grid(201, vector<int>(201));
    int d, s;   // direction, scale
    int x = 0, y = 0;   // 현재 위치 좌표 초기화

    while (true) {
        cin >> d >> s;

        // 사용자가 -1 -1을 입력하면 프로그램 종료
        if (d == -1 && s == -1)
            break;

        move(d, s, x, y, grid);
    }

    return 0;
}
