#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 8;

vector<vector<int>> board(SIZE, vector<int>(SIZE));		// 보드 8x8 2차원 배열
const int BLACK = 1;	// 검은 돌은 1
const int WHITE = 2;	// 흰 돌은 2

int countStoneToCapture(int x, int y, int color) {
	int oppositeColor = (color == BLACK) ? WHITE : BLACK;
	int cnt = 0;

	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0)		// 움직이지 않는 경우
				continue;
			int nx = x + dx;
			int ny = y + dy;
			if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE)	// 판을 벗어나는 경우
				continue;
			if (board[nx][ny] == oppositeColor) {
				while (true) {
					nx += dx;
					ny += dy;
					if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE || board[nx][ny] == 0)
						break;
					if (board[nx][ny] == color) {
						cnt++;
						break;
					}
				}
			}
		}
	}
	return cnt;
}

bool isValidMove(int x, int y, int color) {
	if (board[x][y] != 0) {
		cout << "Invalid Move - Already placed" << endl;
		return false;
	}
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx == 0 && dy == 0)
				continue;
			int nx = x + dx;
			int ny = y + dy;
			while (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] != 0) {
				if (board[nx][ny] != color) {
					return true;
				}
				nx += dx;
				ny += dy;
			}
		}
	}
	return false;
}

void placeStone(int x, int y, int color) {
	board[x][y] = color;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0)
				continue;
			int nx = x + dx;
			int ny = y + dy;
			while (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] != 0) {
				if (board[nx][ny] == color) {
					int cx = x + dx;
					int cy = y + dy;
					while (cx != nx || cy != ny) {
						board[cx][cy] = color;
						cx += dx;
						cy += dy;
					}
					break;
				}
				nx += dx;
				ny += dy;
			}
		}
	}
}

// 오셀로...
int main() {
	// 중앙 네 칸에 돌 놓은 걸로 시작
	board[SIZE / 2 - 1][SIZE / 2 - 1] = WHITE;
	board[SIZE / 2][SIZE / 2] = WHITE;
	board[SIZE / 2][SIZE / 2 - 1] = BLACK;
	board[SIZE / 2 - 1][SIZE / 2] = BLACK;

	int turn = BLACK;	// 검은 돌이 먼저 시작

	while (true) {
		// 보드 출력하기
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				if (board[i][j] == BLACK) cout << "1 ";
				else if (board[i][j] == WHITE) cout << "2 ";
				else cout << "0 ";
			}
			cout << endl;
		}
		cout << endl;

		int x, y;
		int maxCaptured = 0;
		int bestX = -1, bestY = -1;
		if (turn == BLACK) {
			cout << "Your turn (1): ";
			cin >> x >> y;
			placeStone(x, y, BLACK);
		}
		else {
			for (int x = 0; x < SIZE; x++) {
				for (int y = 0; y < SIZE; y++) {
					if (board[x][y] == 0 && isValidMove(x, y, WHITE)) {
						int captured = countStoneToCapture(x, y, WHITE);
						if (captured > maxCaptured) {
							maxCaptured = captured;
							bestX = x;
							bestY = y;
						}
					}
				}
			}
			cout << "Computer's turn (2): " << bestX << " " << bestY << endl;
			placeStone(bestX, bestY, WHITE);
		}
		turn = (turn == BLACK) ? WHITE : BLACK;
	}

	return 0;
}
