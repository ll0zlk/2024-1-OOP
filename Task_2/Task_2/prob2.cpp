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

		str.erase(0, str.find_first_not_of(" "));	// 앞쪽 공백 제거
		str.erase(str.find_last_not_of(" ") + 1);	// 뒤쪽 공백 제거

		bool prev_space = false;	// 이전 문자가 공백?
		for (char c : str) {
			if (isblank(c)) {	// 만약 현재 문자가 공백이고,
				if (!prev_space) {	// 이전이 공백이 아니었다면
					result += c;	// 필요한 공백이므로 추가
					prev_space = true;
				}
			}
			else {		// 현재 문자가 공백이 아니면 = 문자이면,
				result += c;
				prev_space = false;
			}
		}

		cout << result << ":" << result.length() << endl;
	}

	return 0;
}