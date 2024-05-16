#include <iostream>
#include <vector>
using namespace std;

void move(int d, int s, int& x, int& y, vector<vector<int>>& grid) {
    bool available = true;
    switch (d) {
    case 0:     // +y
        for (int i = y + 1; i <= y + s; i++) { // ���� ��ġ �������� Ȯ��
            if (grid[i + 100][x + 100] == 1) {       // �湮�ߴ� ���̸�
                cout << "invalid move" << endl;
                available = false;
                break;
            }
        }
        if (available) {    // ���� �ߺ� ���� �̵� �����ϸ�
            for (int i = y + 1; i <= y + s; i++) {
                grid[i + 100][x + 100] = 1; // �湮 ǥ���ϰ�
            }
            y += s;     // ���� ��ġ�� �̵��Ѵ�.
            cout << x << " " << y << endl;
        }
        break;

    case 1:     // +x
        for (int i = x + 1; i <= x + s; i++) {
            if (grid[y + 100][i + 100] == 1) {       // �湮�ߴ� ���̸�
                cout << "invalid move" << endl;
                available = false;
                break;
            }
        }
        if (available) {    // ���� �ߺ� ���� �̵� �����ϸ�
            for (int i = x + 1; i <= x + s; i++) {
                grid[y + 100][i + 100] = 1; // �湮 ǥ���ϰ�
            }
            x += s;     // ���� ��ġ�� �̵��Ѵ�.
            cout << x << " " << y << endl;
        }
        break;

    case 2:     // -y
        for (int i = y - 1; i >= y - s; i--) {
            if (grid[i + 100][x + 100] == 1) {       // �湮�ߴ� ���̸�
                cout << "invalid move" << endl;
                available = false;
                break;
            }
        }
        if (available) {    // ���� �ߺ� ���� �̵� �����ϸ�
            for (int i = y - 1; i >= y - s; i--) {
                grid[i + 100][x + 100] = 1; // �湮 ǥ���ϰ�
            }
            y -= s;     // ���� ��ġ�� �̵��Ѵ�.
            cout << x << " " << y << endl;
        }
        break;

    case 3:     // -x
        for (int i = x - 1; i >= x - s; i--) {
            if (grid[y + 100][i + 100] == 1) {       // �湮�ߴ� ���̸�
                cout << "invalid move" << endl;
                available = false;
                break;
            }
        }
        if (available) {    // ���� �ߺ� ���� �̵� �����ϸ�
            for (int i = x - 1; i >= x - s; i--) {
                grid[y + 100][i + 100] = 1; // �湮 ǥ���ϰ�
            }
            x -= s;     // ���� ��ġ�� �̵��Ѵ�.
            cout << x << " " << y << endl;
        }
        break;
    }
}

int main() {
    vector<vector<int>> grid(201, vector<int>(201));
    int d, s;   // direction, scale
    int x = 0, y = 0;   // ���� ��ġ ��ǥ �ʱ�ȭ

    while (true) {
        cin >> d >> s;

        // ����ڰ� -1 -1�� �Է��ϸ� ���α׷� ����
        if (d == -1 && s == -1)
            break;

        move(d, s, x, y, grid);
    }

    return 0;
}
