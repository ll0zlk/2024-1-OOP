#include <iostream>
using namespace std;

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (b >= c && a <= d) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}