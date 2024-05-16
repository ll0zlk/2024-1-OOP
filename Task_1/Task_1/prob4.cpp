#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (b > c) {
		int temp = b;
		b = c;
		c = temp;
	}
	if (c > a) {
		int temp = c;
		c = a;
		a = temp;
	}

	cout << a << b << c << endl;
	return 0;
}