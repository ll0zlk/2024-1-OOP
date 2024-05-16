#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 사전 검색 */
struct Dictionary{
	string word;
	string description;
};

bool dictSort(const Dictionary& a, const Dictionary& b) {
	return a.word < b.word;
}

int main() {
	ifstream infile("shuffled_dict.txt");

	// 구조체 설정
	vector<Dictionary> dictionary;
	string line;
	while (getline(infile, line)) {
		int pos = line.find('\t');
		Dictionary dict;
		dict.word = line.substr(0,pos);
		dict.description = line.substr(pos + 1);
		dictionary.push_back(dict);
	}

	// 사전 정렬
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
	if (!found) {	// 일치하는 단어가 없으면? -> 앞뒤 단어 출력해야 함
		cout << "Not found" << endl;

		int low = 0, high = dictionary.size();	// 이진탐색 (low가 user의 위치)
		while (low < high) {
			int mid = (low + high) / 2;
			if (dictionary[mid].word < user)
				low = mid + 1;
			else
				high = mid;
		}

		// 삽입 위치가 맨 처음이거나 / 삽입 위치가 사전 범위 내일 때
		if (low == 0 || low < dictionary.size()) {
			if (low > 0)	// 삽입 위치 앞뒤로 단어 있을 때 이전 단어 출력, 맨 뒤 삽입 시 이전 단어 출력
				cout << "- " << dictionary[low - 1].word << ": " << dictionary[low - 1].description << endl;
			if (low < dictionary.size())	// 삽입 위치 앞뒤로 단어 있을 때 다음 단어 출력, 맨 앞 삽입 시 다음 단어 출력
				cout << "+ " << dictionary[low].word << ": " << dictionary[low].description << endl;
		}
	}

	cout << endl;
	cout << "Results of prefix search:" << endl;

	for (auto dict : dictionary) {
		if (dict.word.find(user) == 0) {	// 접두사이면
			cout << dict.word << ": " << dict.description << endl;
		}
	}

	infile.close();
	return 0;
}