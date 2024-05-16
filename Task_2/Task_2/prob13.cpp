#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* ���̼� ������ */
int main() {
	int n;
	cin >> n;
	cin.ignore();

	vector<string> strings(n);

	for (int i = 0; i < n; i++) {
		getline(cin, strings[i]);
	}

	sort(strings.begin(), strings.end(), [](const string& a, const string& b) {
		if (a.length() == b.length()) {
			return a < b;
		}
		return a.length() < b.length();
		});

	for (string s : strings) {
		cout << s << endl;
	}

	return 0;
}