#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 중복된 문자열 사전식 정렬 */
int main() {
	vector<string> str;
	while (true) {
		string word;
		getline(cin, word);

		if (word == "exit")
			break;

		bool found = false;
		for (string s : str) {
			if (s == word) {
				found = true;
				cout << "duplicate";
				break;
			}
		}
		if (!found) {
			str.push_back(word);
			sort(str.begin(), str.end());
			for (string s : str) {
				cout << s << " ";
			}
		}
		cout << endl;
	}
	return 0;
}