#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// ������ �Ǿ����� Ȯ��
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

// �÷��̾ �̰���� Ȯ��
bool isWinner(const vector<vector<int>>& board, int player) {
	int n = board.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == player) {	// ���� ĭ�� �˻� ���� �÷��̾��� ���̶��
				if (check(board, player, i, j, 1, 0) ||	// ����
					check(board, player, i, j, 0, 1) ||	// ����
					check(board, player, i, j, 1, 1) ||	// �����
					check(board, player, i, j, 1, -1)) { // ������
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