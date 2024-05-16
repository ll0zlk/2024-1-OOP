#include <iostream>
#include <string>
using namespace std;

/* 수식 계산 */
int main(void) {
    string str;
    int sum = 0;
    getline(cin, str);

    char op = '+';      // 연산자 초기 값 +로 지정
    string num = "";    // 연산할 숫자 저장할 문자열

    int start = 0;      // 검사할 시작 인덱스
    if (str[0] == '-') {    // 처음 수가 음수일 경우
        op = '-';     // 연산자 갱신
        start = 1;      // 다음 검사 시작점 갱신
    }

    for (int i = start; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-') {   // 연산자일 때
            if (!num.empty()) {     // 연산할 숫자가 없지 않으면(있으면)
                if (op == '+')
                    sum += stoi(num);
                else
                    sum -= stoi(num);
                num = "";       // 연산할 숫자 초기화
            }
            op = str[i];    // 연산자 갱신
        }
        else {      // 숫자인 경우
            num += str[i];  // 문자열 num에 하나씩 저장
        }
    }

    /* 마지막 숫자 연산 - 연산자가 있어야 계산 가능했기 때문 */
    if (!num.empty()) {     // 연산할 숫자가 없지 않으면(있으면)
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
