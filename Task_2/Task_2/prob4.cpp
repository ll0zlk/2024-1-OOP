#include <iostream>
#include <string>
using namespace std;

/* ���� ��� */
int main(void) {
    string str;
    int sum = 0;
    getline(cin, str);

    char op = '+';      // ������ �ʱ� �� +�� ����
    string num = "";    // ������ ���� ������ ���ڿ�

    int start = 0;      // �˻��� ���� �ε���
    if (str[0] == '-') {    // ó�� ���� ������ ���
        op = '-';     // ������ ����
        start = 1;      // ���� �˻� ������ ����
    }

    for (int i = start; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-') {   // �������� ��
            if (!num.empty()) {     // ������ ���ڰ� ���� ������(������)
                if (op == '+')
                    sum += stoi(num);
                else
                    sum -= stoi(num);
                num = "";       // ������ ���� �ʱ�ȭ
            }
            op = str[i];    // ������ ����
        }
        else {      // ������ ���
            num += str[i];  // ���ڿ� num�� �ϳ��� ����
        }
    }

    /* ������ ���� ���� - �����ڰ� �־�� ��� �����߱� ���� */
    if (!num.empty()) {     // ������ ���ڰ� ���� ������(������)
        if (op == '+') {
            sum += stoi(num);
        }
        else {
            sum -= stoi(num);
        }
    }

    cout << sum << endl;
    return 0;
}
