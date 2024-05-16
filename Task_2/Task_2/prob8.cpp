#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();

	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		getline(cin, words[i]);
	}

	string prefix = words[0];	// 일단 첫 번째 단어가 접두사
	for (int i = 1; i < n; i++) {
		int j = 0;
		for (; min(prefix.length(), words[i].length()); j++) {
			if (prefix[j] != words[i][j])
				break;
		}
		prefix = prefix.substr(0, j);
	}

	if (prefix.empty())
		cout << "nothing" << endl;
	else
		cout << prefix << endl;

	return 0;
}