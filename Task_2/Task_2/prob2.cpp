#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(void) {
	while (true) {
		string str, result;
		getline(cin, str);

		if (str == "exit")
			break;

		str.erase(0, str.find_first_not_of(" "));	// ���� ���� ����
		str.erase(str.find_last_not_of(" ") + 1);	// ���� ���� ����

		bool prev_space = false;	// ���� ���ڰ� ����?
		for (char c : str) {
			if (isblank(c)) {	// ���� ���� ���ڰ� �����̰�,
				if (!prev_space) {	// ������ ������ �ƴϾ��ٸ�
					result += c;	// �ʿ��� �����̹Ƿ� �߰�
					prev_space = true;
				}
			}
			else {		// ���� ���ڰ� ������ �ƴϸ� = �����̸�,
				result += c;
				prev_space = false;
			}
		}

		cout << result << ":" << result.length() << endl;
	}

	return 0;
}