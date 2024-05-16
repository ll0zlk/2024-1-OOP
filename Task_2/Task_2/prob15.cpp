#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 형식 맞춰서 출력 / 테이블 */
int main() {
	ifstream infile("table.txt");
	ofstream outfile("output.txt");

	int rows, cols;
	infile >> rows >> cols;		// 첫 줄의 행 열 개수
	infile.ignore();

	// table.txt 읽기
	for (int i = 0; i < rows; i++) {
		string line;
		getline(infile, line);
		vector<string> cells;
		string cell;

		for (char c : line) {
			if (c != '&')
				cell += c;
			else {
				cell.erase(remove_if(cell.begin(), cell.end(), ::isspace), cell.end());
				if (!cell.empty())  // 빈 문자열이 아닌 경우에만 벡터에 추가
					cells.push_back(cell);
				cell.clear();
			}
		}

		// 마지막 셀 처리
		cell.erase(remove_if(cell.begin(), cell.end(), ::isspace), cell.end());
		if (!cell.empty())  // 빈 문자열이 아닌 경우에만 벡터에 추가
			cells.push_back(cell);

		for (const string& cell : cells) {
			outfile << cell << "\t";
		}

		outfile << endl;
	}

	infile.close();
	outfile.close();

	return 0;
}