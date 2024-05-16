#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 100;

void reverseSort(string A[], int B[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (B[i] < B[j]) {
				int temp = B[i];
				B[i] = B[j];
				B[j] = temp;

				swap(A[i], A[j]);
			}
		}
	}
}

int main() {
	ifstream infile("sample_lines.txt");

	string sentences[MAX];
	int counts[MAX];
	int line_count = 0;

	string line;
	while (getline(infile, line)) {
		/* 빈 줄일 경우 스킵 */
		if (line.find_first_not_of(" \t") == string::npos) {
			continue;
		}

		/* 불필요한 공백 제거 */
		line.erase(0, line.find_first_not_of(" "));	// 앞쪽 공백 제거
		line.erase(line.find_last_not_of(" ") + 1);	// 뒤쪽 공백 제거

		string sentence;
		int count = 0;
		bool prev_space = false;
		for (char c : line) {
			if (isspace(c)) {
				if (!prev_space) {
					sentence += c;
					prev_space = true;
					count++;
				}
			}
			else {
				sentence += c;
				prev_space = false;
			}
		}
		sentences[line_count] = sentence;
		counts[line_count] = count + 1;
		line_count++;
	}
	infile.close();

	reverseSort(sentences, counts, line_count);
	for (int i = 0; i < line_count; i++) {
		cout << sentences[i] << ":" << counts[i] << endl;
	}

	return 0;
}