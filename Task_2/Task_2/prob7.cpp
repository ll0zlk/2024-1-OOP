#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* �ߺ��� ���ڿ� ������ ���� */
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