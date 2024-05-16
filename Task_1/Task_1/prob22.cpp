#include <iostream>
#define MAX 100
using namespace std;

/* 주식 최대 이익 */
int stockTrading(int P[], int size) {
    int maxProfit = 0;
    int minPrice = P[0];

    for (int i = 1; i < size; i++) {
        if (P[i] < minPrice)
            minPrice = P[i];
        else {
            maxProfit += P[i] - minPrice;
            minPrice = P[i];
        }
    }

    return maxProfit;
}

int main() {
    int price;
    int P[MAX];
    int size = 0;

    while (cin >> price && price != -1 && size < MAX) {
        P[size] = price;
        size++;
    }

    cout << stockTrading(P, size) << endl;
    return 0;
}