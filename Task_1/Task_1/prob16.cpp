#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* ���� / �ֻ��� */
int main(void) {
    srand((unsigned int)time(NULL));

    double event1count = 0.0;
    double event2count = 0.0;

    const int T = 1000000;

    /* T����ŭ �ݺ� ���� */
    for (int i = 0; i < T; i++) {
        bool event1 = false;
        bool event2 = false;

        // ù ��° ���
        for (int j = 0; j < 6; j++) {
            int dice = rand() % 6 + 1;

            if (dice == 1) {
                event1 = true;
                break;
            }
        }

        // �� ��° ���
        int count = 0;  // 1�� ���� Ƚ��
        for (int j = 0; j < 12; j++) {
            int dice = rand() % 6 + 1;

            if (dice == 1) {
                count++;
            }

            if (count >= 2) {
                event2 = true;
                break;
            }
        }

        if (event1) {
            event1count++;
        }
        if (event2) {
            event2count++;
        }
    }

    cout << event1count / T << " " << event2count / T << endl;
    return 0;
}
