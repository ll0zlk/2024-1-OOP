#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sorted_merge(vector<string>& first, vector<string>& second) {
    for (int i = 0; i < second.size(); i++) {
        first.push_back(second[i]);
    }
    for (int i = 0; i < first.size() - 1; i++) {
        for (int j = i; j < first.size(); j++) {
            if (first[i] > first[j]) {
                swap(first[i], first[j]);
            }
        }
    }
}

int main() {
    int m, n;
    string str;
    vector<string> first, second;
    cin >> m;
    // m���� �����ڿ��� ���������� ���ĵǾ� �Է�
    for (int i = 0; i < m; i++) {
        cin >> str;
        first.push_back(str);
    }
    cin >> n;
    // n���� �����ڿ��� ���������� ���ĵǾ� �Է�
    for (int i = 0; i < n; i++) {
        cin >> str;
        second.push_back(str);
    }

    // �պ�
    sorted_merge(first, second);

    // m+n���� ���ڿ��� ���������� ���ĵǾ� ���
    for (auto item : first)
        cout << item << " ";
    cout << endl;
    return 0;
}