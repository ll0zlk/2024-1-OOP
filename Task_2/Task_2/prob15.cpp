#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* ���� ���缭 ��� / ���̺� */
int main() {
	ifstream infile("table.txt");
	ofstream outfile("output.txt");

	int rows, cols;
	infile >> rows >> cols;		// ù ���� �� �� ����
	infile.ignore();

	// table.txt �б�
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
				if (!cell.empty())  // �� ���ڿ��� �ƴ� ��쿡�� ���Ϳ� �߰�
					cells.push_back(cell);
				cell.clear();
			}
		}

		// ������ �� ó��
		cell.erase(remove_if(cell.begin(), cell.end(), ::isspace), cell.end());
		if (!cell.empty())  // �� ���ڿ��� �ƴ� ��쿡�� ���Ϳ� �߰�
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