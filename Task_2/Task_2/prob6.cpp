#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

/* 목록을 만들어 출력 / 특수문자 제거 */
int main() {
	ifstream infile("sample.txt");
	string str;
	vector<string> words;

	while (infile >> str) {
		int s = 0, t = str.length() - 1;	// s: 처음 등장하는 alnum 위치
		while (s < str.length() && !isalnum(str[s]))
			s++;
		while (t >= 0 && !isalnum(str[t]))
			t--;
		if (s <= t) {	// 제대로 된 문자열이 있으면
			string pure_word = str.substr(s, t - s + 1);

			for (int i = 0; i < pure_word.length(); i++) {
				pure_word[i] = tolower(pure_word[i]);
			}

			bool found = false;
			for (string w : words) {
				if (w == pure_word) {
					found = true;
					break;
				}
			}
			if (!found)
				words.push_back(pure_word);
		}
	}
	infile.close();

	sort(words.begin(), words.end());

	for (string w : words)
		cout << w << endl;

	return 0;
}