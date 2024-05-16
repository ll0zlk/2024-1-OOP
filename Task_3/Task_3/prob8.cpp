#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 영단어 찾기 */
bool correctWord(const string& word, const vector<string>& dictionary) {
	return find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

void searchWords(const vector<vector<char>>& grid, const vector<string>& dictionary, int row, int col, int dirX, int dirY, int size, vector<string>& found) {
	string word = "";

	for (int i = 0; i < size; i++) {
		int newRow = row + i * dirX;
		int newCol = col + i * dirY;

		// 이동한 위치가 범위 내인지
		if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
			word += grid[newRow][newCol];
			// 만들어진 단어가 사전에 있는지 확인
			if (correctWord(word, dictionary)) {
				// 처음 발견한 단어면
				if (find(found.begin(), found.end(), word) == found.end()) {
					cout << word << endl;
					found.push_back(word);
				}
			}
		}
		// 경계 벗어나면 중지
		else
			break;
	}
}

int main() {
	ifstream dictFile("dictionary.txt");
	ifstream puzzleFile("puzzle.txt");

	vector<string> dictionary;
	string word;
	while (dictFile >> word) {
		dictionary.push_back(word);
	}

	int size;
	puzzleFile >> size;

	vector<vector<char>> grid(size, vector<char>(size));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			puzzleFile >> grid[i][j];
		}
	}

	vector<string> found;

	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			for (int dirX = -1; dirX <= 1; dirX++) {
				for (int dirY = -1; dirY <= 1; dirY++) {
					if (dirX != 0 || dirY != 0) {
						searchWords(grid, dictionary, row, col, dirX, dirY, size, found);
					}
				}
			}
		}
	}
	return 0;
}