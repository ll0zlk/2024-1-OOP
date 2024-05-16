#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;
const int MAX = 1000;

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

/* 사전식 배열 */
void sorting(string A[], int B[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (B[i] < B[j] || (B[i]==B[j] && A[i]>A[j])) {
                swap(B[i], B[j]);
                swap(A[i], A[j]);
            }
        }
    }
}

int main() {
    ifstream infile("input3.txt");

    string words[MAX];
    int counts[MAX] = { 0 };
    int size = 0;

    string word;
    while (infile >> word) {
        // 단어를 소문자로 변환
        for (char& c : word) {
            c = tolower(c);
        }

        // 단어가 배열에 이미 있는지 확인하고 빈도수 증가
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (words[i] == word) {
                counts[i]++;
                found = true;
                break;
            }
        }
        // for문 돌면서 found 정보 수집한 것 바탕으로 단어 추가
        if (!found) {
            words[size] = word;
            counts[size] = 1;
            size++;
        }
    }

    infile.close();

    sorting(words, counts, size);       // 내림차순 정렬

    for (int i = 0; i < size; ++i) {
        cout << words[i] << ": " << counts[i] << endl;
    }

    return 0;
}
