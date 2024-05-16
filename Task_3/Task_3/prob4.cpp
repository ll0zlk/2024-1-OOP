#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// 오목이 되었는지 확인
bool check(const vector<vector<int>>& board, int player, int row, int col, int dx, int dy) {
	int n = board.size();
	for (int i = 0; i < 5; i++) {
		int r = row + i * dx;
		int c = col + i * dy;
		if ((r < 0 && c < 0 && r >= n && c >= n) || board[r][c] != player) {
			return false;
		}
	}
	return true;
}

// 플레이어가 이겼는지 확인
bool isWinner(const vector<vector<int>>& board, int player) {
	int n = board.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == player) {	// 현재 칸이 검사 중인 플레이어의 돌이라면
				if (check(board, player, i, j, 1, 0) ||	// 수평
					check(board, player, i, j, 0, 1) ||	// 수직
					check(board, player, i, j, 1, 1) ||	// 우상향
					check(board, player, i, j, 1, -1)) { // 우하향
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ifstream inFile("board.txt");
	
	int n;
	inFile >> n;

	vector<vector<int>> board(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			inFile >> board[i][j];
		}
	}

	inFile.close();

	bool blackWins = isWinner(board, 1);
	bool whiteWins = isWinner(board, 2);

	if (blackWins)
		cout << "BlacK" << endl;
	else if (whiteWins)
		cout << "White" << endl;
	else
		cout << "Not Finished" << endl;

	return 0;
}