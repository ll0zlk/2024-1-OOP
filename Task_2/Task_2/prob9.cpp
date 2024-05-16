#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* ���� �˻� */
struct Dictionary{
	string word;
	string description;
};

bool dictSort(const Dictionary& a, const Dictionary& b) {
	return a.word < b.word;
}

int main() {
	ifstream infile("shuffled_dict.txt");

	// ����ü ����
	vector<Dictionary> dictionary;
	string line;
	while (getline(infile, line)) {
		int pos = line.find('\t');
		Dictionary dict;
		dict.word = line.substr(0,pos);
		dict.description = line.substr(pos + 1);
		dictionary.push_back(dict);
	}

	// ���� ����
	sort(dictionary.begin(), dictionary.end(), dictSort);

	string user;
	cin >> user;

	bool found = false;
	for (auto dict : dictionary) {
		if (dict.word == user) {
			found = true;
			cout << dict.word << endl;
			cout << dict.description << endl;
		}
	}
	if (!found) {	// ��ġ�ϴ� �ܾ ������? -> �յ� �ܾ� ����ؾ� ��
		cout << "Not found" << endl;

		int low = 0, high = dictionary.size();	// ����Ž�� (low�� user�� ��ġ)
		while (low < high) {
			int mid = (low + high) / 2;
			if (dictionary[mid].word < user)
				low = mid + 1;
			else
				high = mid;
		}

		// ���� ��ġ�� �� ó���̰ų� / ���� ��ġ�� ���� ���� ���� ��
		if (low == 0 || low < dictionary.size()) {
			if (low > 0)	// ���� ��ġ �յڷ� �ܾ� ���� �� ���� �ܾ� ���, �� �� ���� �� ���� �ܾ� ���
				cout << "- " << dictionary[low - 1].word << ": " << dictionary[low - 1].description << endl;
			if (low < dictionary.size())	// ���� ��ġ �յڷ� �ܾ� ���� �� ���� �ܾ� ���, �� �� ���� �� ���� �ܾ� ���
				cout << "+ " << dictionary[low].word << ": " << dictionary[low].description << endl;
		}
	}

	cout << endl;
	cout << "Results of prefix search:" << endl;

	for (auto dict : dictionary) {
		if (dict.word.find(user) == 0) {	// ���λ��̸�
			cout << dict.word << ": " << dict.description << endl;
		}
	}

	infile.close();
	return 0;
}