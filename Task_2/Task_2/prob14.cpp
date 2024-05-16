#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 접두어 */
int main() {
	ifstream infile("harry.txt");

	/* 파일 받아서 공백 제거 및 단어 정렬 */
	vector<string> words;
	string word;
	while (infile >> word) {
		word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
		if (find(words.begin(), words.end(), word) == words.end()) {
			words.push_back(word);
		}
	}
	sort(words.begin(), words.end());

	string prefix;
	cin >> prefix;
	int cnt = 0;
	for (string w : words) {
		if (w.substr(0, prefix.length()) == prefix) {
			cout << w << endl;
			cnt++;
		}
	}
	cout << cnt;

	infile.close();

	return 0;
}