#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* 랜덤 / 주사위 */
int main(void) {
    srand((unsigned int)time(NULL));

    double event1count = 0.0;
    double event2count = 0.0;

    const int T = 1000000;

    /* T번만큼 반복 실험 */
    for (int i = 0; i < T; i++) {
        bool event1 = false;
        bool event2 = false;

        // 첫 번째 사건
        for (int j = 0; j < 6; j++) {
            int dice = rand() % 6 + 1;

            if (dice == 1) {
                event1 = true;
                break;
            }
        }

        // 두 번째 사건
        int count = 0;  // 1이 나온 횟수
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
